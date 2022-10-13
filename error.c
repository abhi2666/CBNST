/*
1. Calculate the Absolute Error Ea = | X – X’|. 
2. Calculate the Relative Error Er = | X – X’| / | X |. 
3. Calculate the Percentage Error Ep = Er * 100. 
*/
#include <stdio.h>
#include <math.h>

void printError(float x, float x1)
{
    
    printf("Absolute Error is %0.4f\n", fabs(x - x1));
    printf("Relative Error is %0.4f\n", (fabs(x - x1)/fabs(x)));
    printf("Percentages Error is %0.4f", ((fabs(x - x1)/fabs(x)) * 100));
    printf("\n\n");

}

void truncate(float x)
{
    float x1;
    int a;
    x1 = x*10000;
    a = (int) x1;
    x1 = a/10000.0; // truncation complete
    printf("After Truncation: \n");
    printError(x, x1);
    
}

void roundOff(float x)
{
    float x1;
    x1 = x * 10000;
    x1 = round(x1);
    x1 = x1/10000.0;
    printf("After Roundoff: \n");
    printError(x, x1);
}
int main()
{
    float x;
    printf("Enter original number: \n");
    scanf("%f", &x);

    truncate(x);
    roundOff(x);
    return 0;
}