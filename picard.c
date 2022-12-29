/*
Picard's Method 
*/

#include <stdio.h>
#include<math.h>
float func(float x, float y)
{
    return x + pow(y, 2);
}

int main()
{
    int n;
    printf("Enter no. of iterations: \n");
    scanf("%d", &n);
    float xo, yo, xn;
    printf("Enter xo and yo values: \n");
    scanf("%f%f", &xo, &yo);
    printf("Enter xn value: \n");
    scanf("%f", &xn);
    float h = (xn - xo)/n;
    float ans = 0;
    return 0;
}