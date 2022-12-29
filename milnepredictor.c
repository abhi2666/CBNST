/*
milne's predictor
*/
#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
    return x - pow(y, 2);
}

int main()
{
    int n;
    printf("Enter the no. of intervals: \n");
    scanf("%d", &n);
    float x[n], y[n], func[n], h;
    printf("Enter value of x: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    h = x[1] - x[0];
    printf("Enter value of y: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    float xn;
    printf("Enter the value of xn: \n");
    
    for(int i = 0; i < n; i++)
    {
        func[i] = f(x[i], y[i]);
    }
    //calculating predictor
    float yp = y[0] + 4*h/3*(2*func[1] - func[2] + 2*func[3]);
    //calculating corrector
    float yc = y[2] + (h/3)*(func[2] + 4*func[3] + func[4]);
    printf("predictor --> %f and corrector --> %f", yp, yc);

    return 0;
}