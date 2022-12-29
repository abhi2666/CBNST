/*
Simpson 3/8 method (for multiple of 3 intervals) 
 --> to find the solution of integration question
formula --> 3*h/8*((y0 + yn) + 3*(y1 + y2 + y4 + ...) 
+ 2*(y3 + y6 +..))
*/

#include <stdio.h>
#include<math.h>

float f(float x)
{
    return 1/(1 + pow(x, 2));
}
int main()
{
    int n;
    printf("Enter no. of intervals: \n");
    scanf("%d", &n);
    float a, b, h;
    printf("Enter value of upper and lower limits: \n");
    scanf("%f%f", &a, &b);
    h = (b - a)/n;
    float x = 0, sum = 0;
    sum += f(a) + f(b);
    for(int i = 1; i < n; i++)
    {
        x = a + i*h;
        if(i % 3 == 0)
        {
            sum += 2*f(x);
        }
        else
        {
            sum += 3*f(x);
        }
    }
    sum = (3*h * sum)/8.0;
    printf("The answer is %f", sum);
    return 0;
}