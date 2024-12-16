#include <stdio.h>
#include <string.h>
/*
4.1.3 4 字符串中数字的提取
Double pointer 双指针法
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[1000];   // 输入的字符串
    char result[1000] = "";  // 存储最终结果的字符串
    int count = 0;      // 连续数字串的个数

    // 输入字符串
    printf("请输入一行字符串:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int i = 0;
    int n = strlen(input);
    
    // 双指针: start为数字串的开始位置
    while (i < n) {
        // 找到一个数字串的开始
        if (isdigit(input[i])) {
            int start = i;
            char *start_p = &input[start];
            // 找到数字串的结束位置
            while (i < n && isdigit(input[i])) {
                i++;
            }
            
            // 处理这个数字串
            int length = i - start;  // 当前数字串的长度
            if (length >= 2) {  // 如果长度大于等于2
                // 将数字串添加到结果字符串中
                if (count > 0) {
                    strcat(result, ",");
                }
                // 使用snprintf来提取当前数字串并加入结果
                char temp[100];
                // snprintf(temp, sizeof(temp), "%.*s", length, input + start);
                for (int j = 0; j < length; j++) {
                    temp[j] = *(start_p + j);
                }
                strcat(result, temp);
                count++;  // 更新数字串数量
            }
        } else {
            i++;  // 继续遍历下一个字符
        }
    }

    // 输出结果
    printf("输入的字符串是:%s\n",input);
    printf("提取的数字串为:%s\n", result);

    return 0;
}
