#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[1000];
    char result[1000] = "";  // 存储最终的数字串
    char temp[100];  // 存储临时的数字串
    int i = 0, j = 0, count = 0;

    // 输入一行字符串
    fgets(input, sizeof(input), stdin);

    // 遍历字符串，提取连续数字串
    for (int k = 0; k < strlen(input); k++) {
        if (isdigit(input[k])) {  // 如果是数字字符
            temp[j++] = input[k];  // 加入到临时数字串中
        } else {
            if (j >= 2) {  // 如果临时数字串的长度大于等于2
                temp[j] = '\0';  // 结束当前数字串
                if (count > 0) {
                    strcat(result, ",");  // 不是第一个数字串，加逗号
                }
                strcat(result, temp);  // 将数字串加入到结果字符串
                count++;  // 计数
            }
            j = 0;  // 重置临时数字串
        }
    }

    // 检查字符串结束时是否有未处理的数字串
    if (j >= 2) {
        temp[j] = '\0';
        if (count > 0) {
            strcat(result, ",");
        }
        strcat(result, temp);
        count++;
    }

    // 输出结果
    printf("%s\n", result);
    printf("%d\n", count);

    return 0;
}
