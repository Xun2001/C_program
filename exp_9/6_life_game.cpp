#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

// 打印当前网格状态
void printMatrix(char *lifeMatrix[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", lifeMatrix[i][j]);
        }
        printf("\n");
    }
}

// 获取指定位置的周围8个邻居的活细胞数
int countAliveNeighbors(char *lifeMatrix[SIZE], int x, int y) {
    int count = 0;
    // 邻居位置的相对坐标
    int neighbors[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    for (int i = 0; i < 8; i++) {
        int nx = x + neighbors[i][0];
        int ny = y + neighbors[i][1];
        // 确保不越界
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            if (lifeMatrix[nx][ny] == '*') {
                count++;
            }
        }
    }
    return count;
}

// 进化 n 代的函数
void evolution(char *lifeMatrix[SIZE], int n) {
    for (int gen = 0; gen < n; gen++) {
        // 创建一个临时矩阵来保存下一代状态
        char newMatrix[SIZE][SIZE];

        // 逐个检查每个细胞
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int aliveNeighbors = countAliveNeighbors(lifeMatrix, i, j);

                if (lifeMatrix[i][j] == '*') {  // 当前是活细胞
                    if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                        newMatrix[i][j] = '-';  // 死亡
                    } else {
                        newMatrix[i][j] = '*';  // 继续生存
                    }
                } else {  // 当前是死细胞
                    if (aliveNeighbors == 3) {
                        newMatrix[i][j] = '*';  // 复生
                    } else {
                        newMatrix[i][j] = '-';  // 继续死亡
                    }
                }
            }
        }

        // 将新状态复制回原矩阵
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                lifeMatrix[i][j] = newMatrix[i][j];
            }
        }

        // 打印当前代数的网格
        printf("Generation %d:\n", gen + 1);
        printMatrix(lifeMatrix);
    }
}

// 初始化生命网格，随机生成初始状态
void initializeMatrix(char *lifeMatrix[SIZE]) {
    srand(time(NULL));  // 设置随机数种子
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                lifeMatrix[i][j] = '*';  // 随机生成活细胞
            } else {
                lifeMatrix[i][j] = '-';  // 随机生成死细胞
            }
        }
    }
}

int main() {
    char *lifeMatrix[SIZE];  // 生命网格
    // 为每一行分配内存
    for (int i = 0; i < SIZE; i++) {
        lifeMatrix[i] = (char *)malloc(SIZE * sizeof(char));
    }

    // 初始化网格
    initializeMatrix(lifeMatrix);

    // 用户输入代数
    int n;
    printf("Enter the number of generations (n > 2): ");
    scanf("%d", &n);

    // 确保用户输入有效的代数
    if (n <= 2) {
        printf("Please enter a number greater than 2.\n");
        return 1;
    }

    // 进化 n 代
    evolution(lifeMatrix, n);

    // 释放内存
    for (int i = 0; i < SIZE; i++) {
        free(lifeMatrix[i]);
    }

    return 0;
}
