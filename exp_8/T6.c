#include <stdio.h>
#include <stdlib.h>

// 函数声明
int maxArea(int* waterTroughHeights, int n);

int main() {
    // 输入的水槽高度数组
    int waterTroughHeights[] = {1, 2, 1, 3, 2, 1, 2, 4, 3, 2, 3, 2};
    int n = sizeof(waterTroughHeights) / sizeof(waterTroughHeights[0]);
    
    // 输出最大积水容积
    int result = maxArea(waterTroughHeights, n);
    printf("最大积水容积: %d\n", result);
    
    return 0;
}

// 最大容积计算函数
int maxArea(int* waterTroughHeights, int n) {
    int left = 0;  // 左指针
    int right = n - 1;  // 右指针
    int max_volume = 0;  // 存储最大容积

    // 使用双指针法，直到两个指针相遇
    while (left < right) {
        // 计算当前容积
        int height;
        if(waterTroughHeights[left]< waterTroughHeights[right])
            height=waterTroughHeights[left];
        else height=waterTroughHeights[right];
        int width = right - left;
        int volume = height * width;

        // 更新最大容积
        if (volume > max_volume) {
            max_volume = volume;
        }

        // 移动较小的指针
        if (waterTroughHeights[left] < waterTroughHeights[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_volume;
}
