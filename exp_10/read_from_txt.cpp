#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DATA_FILE_NAME "/home/qinllgroup/hongxiangyu/Notes/C_homework/exp_10/count.txt"
#define MAX_WORD_LENGTH 100
#define TOP_N 10
// 定义链表节点
typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordNode *next;
} WordNode;

// 功能函数声明
WordNode* createNode(const char *word);
void insertWord(WordNode **head, const char *word);
WordNode* findWord(WordNode *head, const char *word);
void freeList(WordNode *head);
void toLower(char *str);
void sortList(WordNode *head);
void printTopWords(WordNode *head);

// 主函数
int main() {
    FILE *file = fopen(DATA_FILE_NAME, "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    WordNode *head = NULL;
    char word[MAX_WORD_LENGTH];
    int ch, i = 0;

    // 读取文件并处理每个单词
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            word[i++] = tolower(ch);  // 转小写
        } else if (i > 0) {
            word[i] = '\0';  // 终止字符串
            if (strlen(word) > 1) {  // 只插入长度大于1的单词
                insertWord(&head, word);  // 插入链表
            }
            i = 0;
        }
    }

    if (i > 0) {
        word[i] = '\0';  // 处理最后一个单词
        if (strlen(word) > 1) {  // 只插入长度大于1的单词
            insertWord(&head, word);
        }
    }

    fclose(file);

    // 排序并输出前十个单词
    sortList(head);
    printTopWords(head);

    freeList(head);
    return 0;
}

// 创建一个新的节点
WordNode* createNode(const char *word) {
    WordNode *node = (WordNode *)malloc(sizeof(WordNode));
    if (node) {
        strncpy(node->word, word, MAX_WORD_LENGTH);
        node->count = 1;
        node->next = NULL;
    }
    return node;
}

// 查找链表中是否存在该单词
WordNode* findWord(WordNode *head, const char *word) {
    while (head) {
        if (strcmp(head->word, word) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// 插入单词到链表
void insertWord(WordNode **head, const char *word) {
    WordNode *node = findWord(*head, word);
    if (node) {
        node->count++;
    } else {
        node = createNode(word);
        node->next = *head;
        *head = node;
    }
}

// 释放链表内存
void freeList(WordNode *head) {
    WordNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 排序链表，按单词出现次数降序排列
void sortList(WordNode *head) {
    if (!head) return;

    WordNode *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->count < j->count) {
                // 交换节点
                int tempCount = i->count;
                char tempWord[MAX_WORD_LENGTH];
                strcpy(tempWord, i->word);

                i->count = j->count;
                strcpy(i->word, j->word);

                j->count = tempCount;
                strcpy(j->word, tempWord);
            }
        }
    }
}

// 输出出现次数最多的前十个单词
void printTopWords(WordNode *head) {
    int count = 0;
    while (head && count < TOP_N) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
        count++;
    }
}
