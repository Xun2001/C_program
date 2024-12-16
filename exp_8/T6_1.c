/*
给定n个非负整数 41，42，…，a，每个数代表坐标中的一个点(i,a;)。
在坐标内画n条垂直线，垂直线i的两个端点分别为(i,a;)和(i,0)。
找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
说明:不能倾斜容器，且n的值至少为 2。
*/

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_height = (height[left] < height[right]) ? height[left] : height[right];
        int current_area = width * current_height;

        if (current_area > max_area) {
            max_area = current_area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int heights[] = {41, 42, 43, 44, 45};  // 示例输入
    int n = sizeof(heights) / sizeof(heights[0]);
    int result = maxArea(heights, n);
    printf("The maximum area is: %d\n", result);
    return 0;
}