/*
有一个字符串包含n个字符，
编写函数udf_strcpy()
将此字符串中第m个字符开始的字符全部复制称为另外一个字符串；

*/

#include <stdio.h>
#include <string.h>

// 自定义的字符串复制函数
void udf_strcpy(char *dest, const char *src, int m) {
    int i = 0;
    
    // 检查m的合法性
    if (m < 1 || m > strlen(src)) {
        printf("Error: invalid position m\n");
        dest[0] = '\0';  // 若m无效，目标字符串为空
        return;
    }

    // 从src的第m个字符开始复制
    // 需要将m转换为0索引，即m-1
    for (i = 0; src[m - 1 + i] != '\0'; i++) {
        dest[i] = src[m - 1 + i];
    }

    // 目标字符串末尾加上终止符
    dest[i] = '\0';
}

int main() {
    char src[] = "Hello, world!";
    char dest[100];
    int m = 7;
    // 调用udf_strcpy函数
    udf_strcpy(dest, src, m);
    // 输出复制的字符串
    printf("Original string: %s\n", src);
    printf("Copied string: %s\n", dest);

    return 0;
}
