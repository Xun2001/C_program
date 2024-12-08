#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链表节点结构体
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// 在链表尾部插入节点
void insertNode(Node **head, char c) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 转换小写字母为大写字母
void convertString(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data >= 'a' && temp->data <= 'z') {
            temp->data = temp->data - 32;
        }
        temp = temp->next;
    }
}

// 将链表内容写入文件
void writeToFile(Node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("无法打开文件！\n");
        return;
    }

    Node *temp = head;
    while (temp!= NULL) {
        fputc(temp->data, fp);
        temp = temp->next;
    }

    fclose(fp);
}

// 释放链表内存
void freeList(Node *head) {
    Node *current = head;
    Node *next;
    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = NULL;
    char c;
    char filename[100];

    // 输入文件名
    printf("请输入文件名：");
    scanf("%s", filename);

    // 输入字符串并构建链表
    printf("请输入字符串（以#结束）：");
    scanf("%c", &c); // 处理scanf输入文件名后的换行符
    while ((c = getchar())!= '#') {
        insertNode(&head, c);
    }

    // 转换小写字母为大写字母
    convertString(head);

    // 将链表内容写入文件
    writeToFile(head, filename);

    // 释放链表内存
    freeList(head);

    printf("字符串已成功写入文件！\n");

    return 0;
}