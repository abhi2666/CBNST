#include <stdio.h>
#include <math.h>
#define e 0.001
void inita(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    
}

void printSolution(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%f ", a[i]);
    }
    printf("\n");
    
}
void gaussSid(float mat[][100], int n)
{
    float sum;
    float values_old[n], values_new[n];
    inita(values_new, n);
    inita(values_old, n);

    // this loop for max iterations
    for(int i = 0; i < 30; i++)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    sum += mat[i][j]*values_new[j];
                }
            }
            values_new[i] = (mat[i][n] - sum)/mat[i][i];
        }

        //check if the new values are correct values
        int flag = 0;
        for (int k = 0; k < n; k++)
        {
            if(fabs(values_new[k] - values_old[k]) < e)
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printSolution(values_new, n);
        }
        //copy the content from old to new array
        for (int i = 0; i < n; i++)
        {
            values_old[i] = values_new[i];
        }
        
        
    }
    printSolution(values_new, n);
}

int main()
{
    int n;
    printf("Enter order : \n");
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

    gaussSid(mat, n);
    
    return 0;
}