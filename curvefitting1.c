// curve fitting for y = a + bx 
#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter no. of terms: \n");
    scanf("%d", &n);
    float x[n], y[n], sumx2 = 0, sumxy = 0, sumx = 0, sumy = 0;
    printf("enter values of x: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("enter values of y: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    //calculating
    for(int i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumx2 += (x[i] * x[i]);
        sumxy += (x[i] * y[i]);
    }
    float a, b;
    a = (sumx2*sumy - sumx*sumxy)/(n*sumx2 - (sumx*sumx));
    b = (n*sumxy - sumx*sumy)/(n*sumx2 - (sumx*sumx));
    printf("y = %f + X%f", a, b);

    return 0;
}