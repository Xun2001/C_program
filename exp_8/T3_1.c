#include <stdio.h>
#include <string.h>
/*
4.1.3 4 字符串中数字的提取
Double pointer 双指针法
*/

void copy_to_str(char *p_left, char *p_right, char *new_str)
{
    char add_str={'\0'};
    int count = 0;
    while (*p_left != *p_right) 
    {
        
        add_str=*p_left;
        strcat(new_str, &add_str);        
        p_left++;
        count++;
    }

}
void get_num(char *str, char *new_str)
{
    char *p_left = &str[0];
    char *p_right = &str[0];
    char douhao = ',';
    int count = 0;

    while (*p_right)
    {
        if ((*p_right >= '0' && *p_right <= '9') && count == 0)
        {
            p_left = p_right;
            count++;
        }
        else if ((*p_right >= '0' && *p_right <= '9') && count != 0)
        {
            count++;
        }
        else if(!(*p_right >= '0' && *p_right <= '9') && count >= 2)
        {   
            if(new_str[0]!='\0')
                {strcat(new_str, &douhao);}
            copy_to_str(p_left, p_right, new_str);
            count = 0;
        }
        p_right++;
    }

    if ((new_str[0]!='\0') && (*p_right=='\0') && count >= 2)
    {
        strcat(new_str, &douhao);
        copy_to_str(p_left, p_right, new_str);
    }
    else if((new_str[0]=='\0') && (*p_right=='\0') && count >= 2)
    {
        copy_to_str(p_left, p_right, new_str);
    }
}
int main()
{
    char str[100]={'\0'};
    char num_str[100]={'\0'};
    num_str[0]='\0';
    // char *p_num_str;
    printf("请输入一行字符串:\n");
    scanf("%s",str);//遇换行符中止
    printf("输入的字符串是:%s\n",str);//确保Vscode中scanf可以正确使用
    get_num(str,num_str);
    printf("提取出来的数字是:%s\n",num_str);
	// puts(str);
	// puts(num_str);
    return 0;
}