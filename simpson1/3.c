/*
Simpson 1/3 (For even interval only)...n --> interval
formula ----> h/3((yo + yn) + 4*(y1 + y3 + y5 + ...) 
              + 2*(y2 + y4 + y6 + ...))
purpose --> to solve integration equations             
*/
#include <stdio.h>
#include <math.h>

float func(float x)
{
    return 1/(1 + pow(x, 2));
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
    float x = 0;
    for(int i = 1; i < n; i++)
    {
        x = a + i*h;
        if(i % 2 == 0)
        {   
            //even
            sum = sum + 2*func(x);
        }
        else
        {
            sum = sum + 4*func(x);
        }
    }
    sum = (h * sum)/3.0;
    printf("Your answer is %f", sum);
    return 0;
}