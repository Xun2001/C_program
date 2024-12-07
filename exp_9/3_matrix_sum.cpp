/*
P177 4.2.3 T3
requirement:
    void transport(float a[][2], float transport_a[][2]);//矩阵的转置
    void inverse(float （*a)[2], float inverse_a[][2]); //矩阵的求逆
    void add(float *a, float *b, float s[][2]);//两个矩阵相加

*/
# include <stdio.h>


void create_matrix(float a[][2]);

void transport(float a[][2], float transport_a[][2]);
void inverse(float (*a)[2], float inverse_a[][2]);
void add(float *a, float *b, float s[][2]);

int main()
{
    // input 2D matrix
    float a[2][2] = {3,3,4,5};
    // create_matrix(a);
    float transport_a[2][2]={0};
    float inverse_a[2][2]={0};
    
    
    transport(a,transport_a);
    inverse(a,inverse_a);
    add(*transport_a,*inverse_a,a);


}

void transport(float a[][2], float transport_a[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transport_a[i][j] = a[j][i];
        }
    }
    printf("transport 2D matrix is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%f ", transport_a[i][j]);
        }
        printf("\n");
    }

}


void inverse(float (*a)[2], float inverse_a[][2])
{
    // printf("a is %d\n",a);
    // printf("a+1 is %d\n",a+1);
    // printf("a[0] is %d\n",a[0]);
    // printf("a[1] is %d\n",a[1]);
    // printf("a[0][0] is %f\n",*(a[0]));
    // printf("a[1][0] is %f\n",*(a[1]));
    // printf("a[0][1] is %f\n",*(a[0]+1));
    // printf("a[1][1] is %f\n",*(a[1]+1));
    // printf("a[0][1] is %f\n",a[0][1]);
    // printf("a[1][1] is %f\n",a[1][1]);

    float d = a[0][0] * a[1][1] - a[1][0] * a[0][1];

    float astar[2][2] = {a[1][1], -a[0][1], -a[1][0], a[0][0]};
    printf("\ninverse matrix is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            inverse_a[i][j] = astar[i][j] / d;
            printf("%.2f\t", inverse_a[i][j]);
        }
        printf("\n");
    }

}

void add(float *a, float *b, float s[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
        //    s[i][j] = a[i][j] + b[i][j];
          s[i][j] =*(a+2*i+j) + *(b+2*i+j);
        }
    }
    printf("\nadd matrix is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%f ", s[i][j]);
        }
        printf("\n");
    }
    
}

void create_matrix(float a[][2])
{
    printf("input 2D matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("input 2D matrix is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}