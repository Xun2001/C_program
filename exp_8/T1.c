#include <stdio.h>

// 交换两个数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[10]={2,1,3,4,5,6,7,8,10,9};
    int *p;
    int i;

    // 找到最小值并与第一个元素交换
    p = arr;
    int *min_p = p;
    for (i = 0; i < 10; i++) {
        if (*p < *min_p) {
            min_p = p;
        }
        p++;
    }
    swap(arr, min_p);

    // 找到最大值并与最后一个元素交换
    p = arr;
    int *max_p = p;
    for (i = 0; i < 10; i++) {
        if (*p > *max_p) {
            max_p = p;
        }
        p++;
    }
    swap(arr + 9, max_p);

    // 输出数组
    for (p = arr; p < arr + 10; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
    // 这是第一个修改
}

