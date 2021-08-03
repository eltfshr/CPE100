#include <stdio.h>
#include <math.h>

int Newton_Raphson(double a, double b, double c, double err, double Xp, double *Xn)
{
    double delta,t;
    int count=0;
    do
    {
        if(2*a*Xp+b==0)
            Xp+=0.00001;
        else
        {
            delta = (a*Xp*Xp+b*Xp+c)/(2*a*Xp+b);
            *Xn = Xp-delta;
            Xp = *Xn;
            count++;
        }
    }
    while(fabs(delta)>err&&count<10000);
    if(count<10000)
        return count;
    else
        return 0;
}

int main()
{
    char ch;
    int count;
    double a,b,c;
    double x1,x2;
    printf("Assignment 6: Newton-Raphson Method\n");
    printf("Input a,b,c from the equation ax^2 + bx + c\n");
    do
    {
        printf("Enter a b c: ");
        scanf("%lf %lf %lf",&a,&b,&c);
        count = Newton_Raphson(a,b,c,0.00001,-100.123,&x1);
        if(count > 0)
        {
            count = Newton_Raphson(a,b,c,0.00001,100.123,&x2);
            if(fabs(x1-x2)<=0.00001)
                printf("X = %lf\n",x1);
            else
            {
                printf("X1 = %lf\n",x1);
                printf("X2 = %lf\n",x2);
            }
        }
        else
            printf("Can't find answers\n");
        do
        {
            printf("Do you wish to continue?(y/n): ");
            scanf(" %c",&ch);
        }while(ch!='n'&&ch!='y');
    }while(ch=='y');
    return 0;
}
