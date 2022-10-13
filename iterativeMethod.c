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
    return x*x*x + x*x -1;
}
// g(x) will be used for finding the root
float g(float x)
{
    return 1/sqrt(1 + x);
}
// // below is the derivative of g(x)
// float diffrentiate(float x)
// {
//     return 1/2.0 * (pow(1, pow((1 + x), 3/2.0)));
// }

void iterativeMethod(float c)
{
    
    float a;
    int i = 0;
    for(int i = 0; i < 15; i++)
    {
        a = g(c);
        if(fabs(a - c) < e)
        {
            printf("Root is : %f\n", c);
            printf("Total no. of iterations are --> %d\n", i);
            return;
        }
        c = a;
        i++;
    }
    
    printf("The root is --> %f\n", a);
    printf("Total no. of iterations are --> %d\n", i);
    return;
}

int main()
{
    float a, b;
    do
    {
        printf("Enter first two guesses: ");
        scanf("%f %f", &a, &b);
    } while (f(a)*f(b) > 0);
    printf("Your correct guesses are: %0.2f %0.2f\n", a, b);
    // your result i.e., root will lie between a and b
    float c = (a + b)/2;
    iterativeMethod(c);
    return 0;
}