#include <stdio.h>

void test5(int n, double *fi, int *count)//n �͡�ӹǹ��Ƿ�����, *f1 ����纤�ҷ��ç���͹�, *count ���Ѻ�ӹǹ��ҷ��ç���͹�
{int temp1=0,temp2=0;
    for(int i=0;*count<n;i++)
    {
        temp1=1+(5*i);
        for(int j=0;temp2<=temp1;j++)
        {
            temp2=1+(3*j);
            if(temp2==temp1)
            {
                ++*count;
                fi[*count]=temp1;
            }
        }

    }
}

void print_test5(int count, double *fi)//count ���͡�ӹǹ��� , *fi ���͡���
{
    printf("Test #5\n");
    printf("**************\n");
    printf("* no *  term *\n");
    printf("**************\n");
    for(int i=1;i<=count;i++)
    {
        printf("* %2d *  %3g  *\n",i,fi[i]);
    }
    printf("**************\n");
    printf("count = %d\n\n",count);
}

void test4(int max, double *fi, double *data, int *count)//max ���͡��ҷ���������Թ, *fi ����纤���������, *data ����纼�����ͧ���, *count ����纨ӹǹ���駷���
{int sum=0;
    while(sum<=max)
    {
        ++*count;
        fi[*count]= (2*(*count)-1)*(42-(2*(*count)));
        sum+=fi[*count];
        data[*count]=sum;
    }
}

void print_test4(int count, double *fi, double *data)//count ���͡�ӹǹ���, *fi ���͡��Ңͧ�������, *data ���͡��������
{
    printf("Test #4\n");
    printf("***********************\n");
    printf("*  i *   fi  *   sum  *\n");
    printf("***********************\n");
    for(int i=1;i<=count;i++)
    {
        printf("* %2d *%5g  * %5g  *\n",i,fi[i],data[i]);
    }
    printf("***********************\n");
    printf("n = %d , sum = %g\n\n",count,data[count]);
}

int is_prime(int i)//�Ѻ����Ţ�����Ǥ׹������� 0 �������繨ӹǹ੾�� ��Ф׹�� 1 件���繨ӹǹ੾��
{int count=0;
    for(int j=1;j<=i;j++)
    {
        if(i%j==0)
        {
            count++;
        }
    }
    if(count==2)
        return 1;
    else
        return 0;
}

void print_test3(int count, double *fi, double *data)//count ���͡�ӹǹ���, *fi ���͡��ҷ����ʴ�, *data ���͡������ͧ���
{
    printf("Test #3\n");
    printf("*******************\n");
    printf("* no *  i *  sum  *\n");
    printf("*******************\n");
    for(int i=1;i<=count;i++)
    {
        printf("* %2d * %2g *  %3g  *\n",i,fi[i],data[i]);
    }
    printf("*******************\n");
    printf("count = %d , sum = %g\n\n",count,data[count]);
}

void test3(int min, int max, double *fi, double *data, int *count)//min ��� max ���͡�ͺࢵ�ͧ��÷ӧҹ , *fi ������������纵���Ţ�ӹǹ੾�� , *data ����纼����, *count ����纨ӹǹ��Ƿ����
{int i=min,sum=0;
    while(i<=max)
    {
       if(is_prime(i)!=0)
       {
           ++*count;
           fi[*count]=i;
           sum+=i;
           data[*count]=sum;
       }
       i++;
    }
}

int fibonacci(int n)//���Ѻ��ҵ��˹�����Ф׹���fibonacci�����˹觹����Ѻ�
{
    if(n==0)
        return 0;
    else if(n<=2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);

}

void print_test2(int count,double *fi,double *data)//count ���͡�ӹǹ���, *fi ���͡��ҷ����ʴ�, *data ���͡���˹觢ͧ��ҷ����ʴ�
{
    printf("Test #2\n");
    printf("***************************\n");
    printf("* count *   i  *    fi    *\n");
    printf("***************************\n");
    for(int i=1;i<=count;i++)
    {
        printf("*  %2d   *%4g  *%8g  *\n",i,data[i],fi[i]);
    }
    printf("***************************\n");
    printf("count = %d , ans = %g\n\n",count,fi[count]);
}

void test2(int n, double *fi, double *data,int *count)//n �������Ѻ�͡��Ҩ���ҡ���� , *fi �����������纤�ҷ��ç�Ѻ���͹�, *data ��������������纵��˹觢ͧ��ҷ��ç���͹�, *count ���Ѻ�ӹǹ���駷���յ�ǵç���͹�
{int temp,i=0;
    while(*count<n)
    {
        i++;
        temp = fibonacci(i);
        if(temp%2==0)
        {
            ++*count;
            fi[*count]=temp;
            data[*count]=i;
        }
    }
}

double sigma(int i)//�Ѻ��ҵ��˹��� ��Ф׹��Ңͧ�ӵͺ�����˹觹����Ѻ�
{double ans=0;
    for(int j=1;j<=i;j++)
    {
        ans = ans+j*2;
    }
    return ans;
}

double product(int i)//�Ѻ��ҵ��˹��� ��Ф׹��Ңͧ�ӵͺ�����˹觹����Ѻ�
{double ans=1;
    for(int j=1;j<=i;j++)
    {
        ans = ans*j;
    }
    return ans;
}

void print_test1(int count,double *fi,double *sum)//count ���͡�ӹǹ�����ŷ����� , *f1 ��������ҧ�ͧ������, *sum ��ͼ�����ͧ�����ҧ�
{
    printf("Test #1\n");
    printf("*********************************\n");
    printf("*   i  *     fi     *     sum   *\n");
    printf("*********************************\n");
    for(int i=1;i<=count;i++)
    {
        printf("*  %2d  *%10.6lf  *%10.6lf *\n",i,fi[i],sum[i]);
    }
    printf("*********************************\n");
    printf("ans = %.6lf\n\n",sum[count]);
}

void test1(int n, double *fi, double *sum, int *count)//n ����˹���Ҩ��ա����, *fi ����纤�Ңͧ �����ҧ�, *sum ����纼�����ͧ���, *count ���Ѻ�ӹǹ���駷��ǹ�ͺ
{
    double total=0;
    for(int i=1;i<=n;i++)
    {
        fi[i] = sigma(i)/product(i);
        total = fi[i] + total;
        sum[i]= total;
        *count = i;
    }
}
int getint(int min,int max)//����Ѻ��ҵ���Ţ���١��ͧ���բͺࢵ�ӡѴ����
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

int get_menu()//������ҧ������ҹ
{
    int select;
    printf("***********************************************\n");
    printf("* My Test function                            *\n");
    printf("***********************************************\n");
    printf("* 1. Test #1                                  *\n");
    printf("* 2. Test #2                                  *\n");
    printf("* 3. Test #3                                  *\n");
    printf("* 4. Test #4                                  *\n");
    printf("* 5. Test #5                                  *\n");
    printf("* 0. exit                                     *\n");
    printf("***********************************************\n");
    printf("Enter menu number :");
    select = getint(0,5);
    return select;
}


int main()
{
    int select;
    do
    {
        int count=0;
        double fi[200],data[200];
        select = get_menu();
        if(select==1)
        {
            test1(10,fi,data,&count);
            print_test1(count,fi,data);
        }
        else if(select==2)
        {
            test2(10,fi,data,&count);
            print_test2(count,fi,data);

        }
        else if(select==3)
        {
            test3(1,30,fi,data,&count);
            print_test3(count,fi,data);
        }
        else if(select==4)
        {
            test4(5000,fi,data,&count);
            print_test4(count-1,fi,data);
        }
        else if(select==5)
        {
            test5(15,fi,&count);
            print_test5(count,fi);
        }
    }while(select!=0);
    return 0;
}

