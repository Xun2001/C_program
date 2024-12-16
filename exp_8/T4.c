/*
4.1.3 8
要求用单层循环实现
*/

#include <stdio.h>
#include <stdlib.h>
#define N 200

int is_word(char s);
int main()
{

    // 输入数据
    char input[N];
    char temp[N]="";
    char *start_p;
    printf("请输入一行字符串:\n");
    fgets(input, sizeof(input), stdin);
    int i = 0;
    int k=0;
    int max=0;
    while(i<N && input[i]!='\0')
    {
        if(is_word(input[i]))
        {
            temp[k]=input[i];
            k++;
        }
        else
        {

            if (k>max)
            {
                max=k;
                start_p=&input[i-k];
            }
            k=0;
        }


        i++;
    }

    // 输出结果
    printf("最长的单词是: ");
    for(int i=0; i<max; i++)
    {   printf("%c", *(start_p+i));}
}

int is_word(char s)
{
    return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}