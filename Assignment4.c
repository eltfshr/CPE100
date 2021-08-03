#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char ch,s[10];
    char *p;
    double u, x, a;
    double t,Smax,H;
    printf("Assignment 4: Projectile\n");
    printf("You are trying to kick a ball into a 2.44-meter-tall goal\n");
    printf("WARNING : You cannot input characters or spaces in this program\n");
    do
    {
        do
        {
            printf("Input the initial speed of the ball: ");
            gets(s);
            u=strtod(s,&p);
        }while(*p!=NULL||s[0]==NULL);
        do
        {
            printf("Input the angle of the ball from the ground: ");
            gets(s);
            a=strtod(s,&p);
        }while(*p!=NULL||s[0]==NULL);
        do
        {
            printf("Input the distance between the ball and the goal: ");
            gets(s);
            x=strtod(s,&p);
        }while(*p!=NULL||s[0]==NULL);
        a = a * acos(-1)/180;
        if((Smax=(u*u*sin(a)*cos(a))/4.905)<x) //U^2 * cos a * sin a / 4.905
        {
            t=u*sin(a)/4.905;
            printf("The ball is %.2lf m away from the goal and it took %.2lf sec \n",x-Smax,t);
            printf("Fail ball!\n");
        }
        else if((t=x/(u*cos(a))) &&(H=x*(tan(a)-4.905*x/(u*u*cos(a)*cos(a))))>=2.44) //x(tan(a)-4.905x/u^2cos^2(a))
        {
            printf("The ball is %.2lf over the ground and it took %.2lf sec\n",H,t);
            printf("Overshoot\n");

        }
        else if(t>0.5)
        {
            printf("The ball is %.2lf over the ground and it took %.2lf sec\n",H,t);
            printf("Saved\n");
        }
        else
        {
            printf("The ball is %.2lf over the ground and it took %.2lf sec\n",H,t);
            printf("Goal!\n");
        }
        do
        {
            printf("Do you want to play again?(y/n): ");
            scanf(" %c",&ch);
        }while(ch!='n'&&ch!='y');
        gets(s);
    }while(ch=='y');
    printf("\nEnd Program");
    return 0;
}
