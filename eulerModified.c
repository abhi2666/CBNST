/*
Euler modified method -->
1. use euler method to get ye 
2. Then find the value of yem using ye
*/
#include <stdio.h>
#include <math.h>

float func(float x, float y)
{
    return pow(x, 2) + y;
}
int main()
{
    int n;
    printf("Enter total no. of intervals: \n");
    scanf("%d", &n);
    float x0, y0, h, xn;
    printf("Enter x0, y0, xn respectively: \n");
    scanf("%f%f%f", &x0, &y0, &xn);
    h = (xn - x0)/n;
    float ye; //ye from euler method
    float yem; // yem from euler modified method
    float xtemp, ytemp;
    while(n--)
    {
        //find ye from euler method
        ye = y0 + h*func(x0, y0);
        xtemp = x0;
        x0 = x0 + h;
        ytemp = y0;
        y0 = ye;
        //now calculating euler modified method
        yem = ytemp + h*(func(xtemp, ytemp) + func(x0 , y0));
    }
    printf("Answer is %f", yem);

    return 0;
}