#include <stdio.h>
#include <math.h>
#define e 0.0001 // 2 decimal places

float f(float x)
{
    return x*x*x - 2*x - 5;
}

void bisection(float a, float b)
{
    float c;
    do
    {
        c = (a + b)/2;
        if(f(a)*f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    } while (fabs(b - a) > e);
    printf("The root is %f", c);
}


int main()
{
    float a, b;
    do
    {
        printf("Enter values of a and b: \n");
        scanf("%f%f", &a, &b);
    } while (f(a)*f(b) > 0);
    printf("Values accepted\n");
    
    bisection(a, b);
    return 0;
}