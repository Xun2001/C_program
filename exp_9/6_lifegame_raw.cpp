#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MatrixSize 10
#define valid(x) (x >= 0 && x <= MatrixSize)
// typedef char (*MTRX)[MatrixSize];

void initmatrix(void);
void printmatrix(void);
void update(void);
void evolution(int n);

char lifematrix[MatrixSize][MatrixSize];
char cellsdata[MatrixSize][MatrixSize] = {0};

int main(void)
{
    int n;
    initmatrix();

    printf("\n Input n ( generations) for evolution:");
    scanf("%d", &n);
    evolution(n);

    return 0;
}

void initmatrix(void)
{
    int i, j;
    srand(time(0));
    for (i = 0; i < MatrixSize; i++)
        for (j = 0; j < MatrixSize; j++)
        {
            // if (i == j || i + j + 1 == MatrixSize)
            //     lifematrix[i][j] = '*';
            // else
            //     lifematrix[i][j] = '-';
            if (rand() % 2)
                lifematrix[i][j] = '*';
            else
                lifematrix[i][j] = '-';
        }
}

void printmatrix(void)
{
    int i, j;
    for (i = 0; i < MatrixSize; i++)
    {
        for (j = 0; j < MatrixSize; j++)
            printf("%2c", putchar(lifematrix[i][j]));
        putchar('\n');
    }
    putchar('\n');
}
void update(void) // check every neighbour cell that live
{
    int i, j, k;
    int v;
    for (i = 0; i < MatrixSize; ++i)
        for (j = 0; j < MatrixSize; ++j)
        {
            v = 0;
            if (valid(j - 1))
                v += (lifematrix[i][j - 1] == '*' ? 1 : 0);
            if (valid(i - 1))
                v += (lifematrix[i - 1][j] == '*' ? 1 : 0);
            if (valid(j + 1))
                v += (lifematrix[i][j + 1] == '*' ? 1 : 0);
            if (valid(i + 1))
                v += (lifematrix[i + 1][j] == '*' ? 1 : 0);
            cellsdata[i][j] = v;
        }
}

void evolution(int n)
{
    int i, j, k;
    int v;
    for (i = 1; i <= n; i++)
    {

        printf("\n=================== life game %2d generation ==================== \n", i);
        printmatrix();
        update();
        getchar();
        for (j = 0; j < MatrixSize; j++)
            for (k = 0; k < MatrixSize; k++)
            {
                v = cellsdata[j][k];
                if (v < 2 || v > 3)
                    lifematrix[j][k] = '-';
                else if (v == 3)
                    lifematrix[j][k] = '*';
            }
    }
}