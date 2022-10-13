/*
Gauss Elimination Method --> is used to solve system of linear equations
by using a matrix.
The matrix is converted into  upper traingular matrix and then values 
of x, y, z are calculated
*/
#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("\n");
    float mat[n][n + 1]; // 1 extra column is required because we will be 
    // using an augumented matrix

    printf("Enter elements in augumented matrix: \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }

    // converting matrix into upper triangular matrix
    float ratio; // here we will store the ratio
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j > i)
            {
                // implies that we will work on creating a upper traingular
                //matrix
                ratio = mat[j][i]/mat[i][i];
                // once we have got the ratio, then we will  apply it
                // to the whole fucking row
                for(int k = 0; k < n + 1; k++)
                {
                    mat[j][k] = mat[j][k] - (ratio*mat[i][k]);
                }
            }
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n + 1; j++)
    //     {
    //         printf("%0.2f ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    float value[n];
    value[n - 1] = mat[n - 1][n]/mat[n - 1][n - 1];

    // calculating other values
    for(int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for(int j = i + 1; j < n; j++)
        {
            // calculate the sum first
            sum += mat[i][j] * value[j];
        }
        value[i] = (mat[i][n] - sum)/mat[i][i];
    }     

    printf("Values are -->  ");
    for(int i = 0; i < n; i++)
    {
        printf("%0.2f ", value[i]);
    }
    return 0;
}