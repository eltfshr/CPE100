#include <stdio.h>

int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n<=2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);

}

int nCr(int n, int r)
{
    int ans;
    ans = factorial(n)/(factorial(n-r)*factorial(r));
    return ans;
}

int factorial(int ans)
{
    if(ans >= 1)
        return ans*factorial(ans-1);
    else
        return 1;
}

int GCD(int m, int n)
{
    int ans;
    for(ans = m;m%ans!=0||n%ans!=0;ans--);
    return ans;
}
int getint(int min,int max)
{
    char ch;
    int num;
    while(scanf("%d%c",&num,&ch)!=1&&ch!='\n'||num<min||num>max)
    {
        printf("Invalid input, please input again : ");
        rewind(stdin);
    }
    return num;
}

int get_menu()
{
    int select;
    printf(" ***********************************************\n");
    printf(" * My Test function                            *\n");
    printf(" ***********************************************\n");
    printf(" * 1. Fibonacci function                       *\n");
    printf(" * 2. Combination number                       *\n");
    printf(" * 3. Find GCD(x,y)                            *\n");
    printf(" * 4. Find Factorial                           *\n");
    printf(" * 0. exit                                     *\n");
    printf(" ***********************************************\n");
    printf("Enter menu number :");
    select = getint(0,4);
    return select;
}


int main()
{
    int select,m,n,r,ans;
    do
    {
        select=get_menu();
        if(select==1)
        {
            printf("Calculate fibonacci number\n");
            printf("Enter fibonacci term: ");
            n = getint(0,45);
            ans = fibonacci(n);
            printf("%dth term of fibonacci is %d\n\n\n",n,ans);
        }
        else if(select==2)
        {
            printf("Program find Combination number nCr\n");
            printf("Enter n: ");
            n=getint(1,10);
            printf("Enter r: ");
            r=getint(1,n);
            ans = nCr(n,r);
            printf("Answer of %dC%d is %d\n\n\n",n,r,ans);
        }
        else if(select==3)
        {
            printf("Program Great division number GCD(m,n)\n");
            printf("Enter m: ");
            m = getint(1,100000);
            printf("Enter n: ");
            n = getint(1,100000);
            ans = GCD(m,n);
            printf("Answer of GCD(%d,%d) = %d\n\n\n",m,n,ans);
        }
        else if(select==4)
        {
            printf("Program Find Factorial n!\n");
            printf("Enter n: ");
            n = getint(0,10);
            ans = factorial(n);
            printf("The answer of %d! is %d\n\n\n",n,ans);
        }

    }while(select!=0);
    return 0;
}
