#include <stdio.h>
#include <math.h>


void gaussJord(float mat[][100], int n)
{
    float ratio;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i != j)
            {
                ratio = mat[j][i]/mat[i][i];

                for (int k = 0; k < n + 1; k++)
                {
                    mat[j][k] = mat[j][k] - (ratio*mat[i][k]);
                }
                
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%f ", mat[i][n]/mat[i][i]);
    }
    
    
}
int main()
{
    int n;
    printf("Enter order of the matrix: \n");
    scanf("%d", &n);
    float mat[n][n + 1];
    printf("Enter matrix elements: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &mat[i][j]);
        }
        
    }
    
    gaussJord(mat, n);
    return 0;
}