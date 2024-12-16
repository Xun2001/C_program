#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2
#define MAX_LENGTH 40  
// strlen(input)

int main()
{
    char countries[N][MAX_LENGTH];
    char (*p1)[N]; // 根据串长排序
    char (*p2)[N];
    // int j;
    // char ch;

    //输入数据
    for(int i=0;i<N;i++)
    {
        // 使用fgets来读取带有空格的国家名，但是需要替换掉最后的回车符
        // fgets(countries[i],MAX_LENGTH, stdin);
        // countries[i][strcspn(countries[i], "\n")] = '\0';
        int j = 0;
        char ch = getchar();
        while (ch!='\n' && j < MAX_LENGTH - 1)
        {
            countries[i][j] = ch;
            j++;
            ch = getchar();
        }
        countries[i][j] = '\0';
        
    }
    //输出数据
    for(int i=0;i<N;i++)
        printf("Input Country:%s\n",countries[i]);
    
}