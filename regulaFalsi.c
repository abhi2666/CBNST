/* Regula Falsi method -- this method is just like bisection method
but the only difference is this method has better convergence rate
and uses a formula to calculate the root of a given equation
*/

#include<stdio.h>
#define e 0.001

float func(float x)
{
    // function of which we want to find the root
    return x*x*x - x*x + 2;
}

void regulaFalsi(float a, float b)
{
    float c = 0.0;
    int itr = 0;
    while((b - a) >= e)
    {
        // finding the mid point of the guessed values
        c = (a*func(b) - b*func(a))/(func(b) - func(a));

        // check if c is the root or not
        if(func(c) == 0.0001)
        {
            // means you have got the root
            printf("The root is --> %f\n", c);
            printf("Total no. of iterations are --> %d", itr);
            return;
        }
        else if(func(a)*func(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        itr++;
    }
    printf("The required root is --> %f\n", c);
    printf("Total no. of iterations are --> %d\n", itr);

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
    bisection(a, b);
    

    
    return 0;
}