#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int max_area = 0;

    for (int left = 0; left < heightSize - 1; left++) {
        for (int right = left + 1; right < heightSize; right++) {
            int width = right - left;
            int current_height = (height[left] < height[right]) ? height[left] : height[right];
            int current_area = width * current_height;

            if (current_area > max_area) {
                max_area = current_area;
            }
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