/*
Trapezodial formula --> h/2*((yo + yn) + 2*(y1+y2+y3+...+yn-1))
take a(lower limit), b(upper limit) and n(no. of intervals) 
from user.
*/
#include <stdio.h>
#include <math.h>

float func(float val)
{
    return 1/(1 + pow(val, 2));
}

int main()
{
    int n;
    printf("Enter no. of intervals\n");
    scanf("%d", &n);
    float a, b, h, sum = 0;
    printf("Enter lower and upper limit respectively: \n");
    scanf("%f%f", &a, &b);
    h = (b - a)/n;
    sum = func(a) + func(b);
    for(float i = a+h; i < b; i = i + h)
    {
        sum = sum + 2*func(i);
    }
    sum = (sum*h)/2.0;
    printf("Answer is %f", sum);
}