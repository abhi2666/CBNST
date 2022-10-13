/*
Gauss Siedal Method --> is an indirect method to solve system of linear
equations and solely based on interations.

Conditions -->
1. Your matrix should be strictly diagonal dominant otherwise you will get
your answers after doing very long iterations.

In this below code we are asuming that user will enter strictly
dominant matrix.
*/

#include <stdio.h>
#include <math.h>
#define e 0.001 // correct upto 2 decimal places

void inita(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0.0;
    }
}

void gaussSiedal(int n, float a[][100])
{
    float values_new[n], values_old[n];
    inita(values_old, n);
    inita(values_new, n);
    float sum;
    // we will iterate over the values
    for (int i = 0; i < 50; i++)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    sum += a[i][j] * values_new[j];
                }
            }
            values_new[i] = (a[i][n] - sum) / a[i][i];
        }

        int flag = 0;
        // checking if we got the solution or not
        for (int k = 0; k < n; k++)
        {
            if (fabs(values_new[k] - values_old[k]) < e)
            {
                // means you have got your answers
                continue;
            }
            else
            {
                // old and new values didn't match..
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            // you have successfully got the unknowns..
            for (int i = 0; i < n; i++)
            {
                printf("%0.2f ", values_new[i]);
            }
            printf("\n");
            return;
        }
        // if not then reset the flag value for the next iteration
        flag = 0;
        // copy new values to old values
        for (int i = 0; i < n; i++)
        {
            values_old[i] = values_new[i];
        }
    }
}

int main()
{
    int n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("\n");
    float mat[n][n + 1]; // 1 extra column is required because we will be
    // using an augumented matrix

    printf("Enter elements in augumented matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }

    gaussSiedal(n, mat);

    return 0;
}