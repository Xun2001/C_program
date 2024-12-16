#include <stdio.h>
#include <string.h>
/*
4.1.3 4 字符串中数字的提取
遍历字符串，提取连续数字串，并输出。
*/
int main() {
    char input[1000];// 用于存储输入的字符串;由fgets初始化
    char result[1000] = "";  // 存储最终的数字串;初始化
    char temp[100];  // 存储临时的数字串
    int i = 0, j = 0, count = 0;

    // 输入一行字符串
    printf("请输入一行字符串:\n");
    fgets(input, sizeof(input), stdin);

    // 遍历字符串，提取连续数字串
    for (int k = 0; k < strlen(input); k++) {
        if (input[k]>= '0' && input[k] <= '9') // if(isdigit(input[k]))
        {  // 如果是数字字符
            temp[j] = input[k];  // 加入到临时数字串中
            j++;
        } else {
            if (j >= 2) {  // 如果临时数字串的长度大于等于2
                temp[j] = '\0';  // 结束当前数字串
                if (count > 0) {
                    strcat(result, ",");  // 不是第一个数字串，则在子数字串前加逗号
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
    printf("输入的字符串是:%s\n",input);
    printf("提取的数字串为:%s\n", result);

    return 0;
}
