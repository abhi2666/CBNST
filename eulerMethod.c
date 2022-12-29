/*
Euler method or runge kutta first order method
formula --> yn+1 = yn + h*func(xn, yn)
*/
#include <stdio.h>
#include<math.h>

float func(float x, float y)
{
    return x + y;
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
    float y = 0;
    for(int i = 0; i < n; i++)
    {
        y = yo + h * func(xo, yo);
        xo = xo + h;
        yo = y;
    }
    printf("Final answer is %f", y);
    return 0;
}