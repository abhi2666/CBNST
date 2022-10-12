/* Regula Falsi method -- this method is just like bisection method
but the only difference is this method has better convergence rate
and uses a formula to calculate the root of a given equation
*/
#include<stdio.h>
#include<math.h>
#define e 0.001
#define max 300000000

float func(float x)
{
    // function of which we want to find the root
    return x*x*x - 4*x + 1;
}

void regulaFalsi(float a, float b)
{
    float fa, fb, fc;
    float c = 0.0;
    int i = 0;
    
    do
    {
        fa = func(a);
        fb = func(b);
        c = (a*func(b) - b*func(a))/(func(b) - func(a));
        fc = func(c);

        if(fa*fc < 0)
        {
            b = c;

        }
        else
        {
            a = c;

        }
        i++;
    } while (fabs(fc) > e);
    

    printf("The root is --> %f\n", c);
    printf("Total no. of iterations are --> %d\n", i);

}

int main()
{
    float a, b;
    do
    {
        printf("Enter first two guesses: ");
        scanf("%f%f", &a, &b);
    } while (func(a)*func(b) >= 0);
    printf("Your correct guesses are: %0.2f %0.2f\n", a, b);
    // your result i.e., root will lie between a and b
    regulaFalsi(a, b);
    

    
    return 0;
}