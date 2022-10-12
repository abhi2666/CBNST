/* Iterative method  in this we first find the intervals and then
find the si(x) which is the writting the f(x) in terms of x where 
we can get value as close to 0 as possible.
Then we find derivative of si(x) and then start inserting the values
in it until we reach the required answer..

This method is better than regula falsi method.
*/
#include<stdio.h>
#include<math.h>
#define e 0.001
#define max 50

// below is the original function
float f(float x)
{
    return pow(x, 3) - 4*x + 1;
}
//derivative of function f(x)
float g(float x)
{
    return 3*x*x - 4;
}

void newtonRaphson(float c)
{
    
    float a, fa;
    int i = 0;
    do
    {

        a = c - (f(c)/g(c));
        fa = f(a);
        c = a;
        i++;
    } while (fabs(fa) > e);
    
    
    printf("The root is --> %f\n", a);
    printf("Total no. of iterations are --> %d\n", i);
    return;
}

int main()
{
    float a, b, c;
    do
    {
        printf("Enter first two guesses: ");
        scanf("%f %f", &a, &b);
    } while (f(a)*f(b) > 0);
    printf("Your correct guesses are: %0.2f %0.2f\n", a, b);
    // your result i.e., root will lie between a and b
    c = (a + b)/2;
    newtonRaphson(0.02);

    return 0;
}