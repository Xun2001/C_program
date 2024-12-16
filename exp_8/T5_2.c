#include <stdio.h>
#include <string.h>

#define MAX_COUNTRIES 10
#define MAX_NAME_LENGTH 40

// 按字符串长度排序的比较函数
int compareByLength(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    return strlen(strA) - strlen(strB);  // 按长度升序
}

// 按ASCII顺序排序的比较函数
int compareByAscii(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    return strcmp(strA, strB);  // 按字典顺序升序
}

int main() {
    char countries[MAX_COUNTRIES][MAX_NAME_LENGTH];
    char *pointersByLength[MAX_COUNTRIES];  // 按长度排序的指针数组
    char *pointersByAscii[MAX_COUNTRIES];   // 按ASCII顺序排序的指针数组
    
    // 输入国家名称
    printf("请输入10个国家名称：\n");
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        fgets(countries[i], MAX_NAME_LENGTH, stdin);
        // 去掉输入字符串末尾的换行符
        countries[i][strcspn(countries[i], "\n")] = '\0';
        
        // 将国家名称的指针分别存入两个指针数组
        pointersByLength[i] = countries[i];
        pointersByAscii[i] = countries[i];
    }

    // 按照字符串长度排序
    qsort(pointersByLength, MAX_COUNTRIES, sizeof(char *), compareByLength);
    
    // 按照ASCII码顺序排序
    qsort(pointersByAscii, MAX_COUNTRIES, sizeof(char *), compareByAscii);

    // 输出按长度排序后的国家名称
    printf("\n按字符串长度排序后的国家名称：\n");
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        printf("%s\n", pointersByLength[i]);
    }

    // 输出按ASCII顺序排序后的国家名称
    printf("\n按ASCII码顺序排序后的国家名称：\n");
    for (int i = 0; i < MAX_COUNTRIES; i++) {
        printf("%s\n", pointersByAscii[i]);
    }

    return 0;
}
