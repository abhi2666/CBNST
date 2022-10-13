/*
Gauss Jordan --> This method is totally like the Gauss 
Elimination but we convert matrix here to diagonal matrix
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
            if(i != j) //means we are transforming all other elements except diagonal to zero
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
    printf("Values are -->  ");
    for(int i = 0; i < n; i++)
    {
        printf("%0.2f ", mat[i][n]/mat[i][i]);
    }
    return 0;
}