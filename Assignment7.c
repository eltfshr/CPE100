#include <stdio.h>

void test5(int n, double *fi, int *count)//n บอกจำนวนตัวที่เอา, *f1 ไว้เก็บค่าที่ตรงเงื่อนไข, *count ไว้นับจำนวนค่าที่ตรงเงื่อนไข
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

void print_test5(int count, double *fi)//count ไว้บอกจำนวนตัว , *fi ไว้บอกค่า
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

void test4(int max, double *fi, double *data, int *count)//max ไว้บอกค่าที่ไม่ให้เกิน, *fi ไว้เก็บค่าแต่ละเทอม, *data ไว้เก็บผลรวมของค่า, *count ไว้เก็บจำนวนครั้งที่ทำ
{int sum=0;
    while(sum<=max)
    {
        ++*count;
        fi[*count]= (2*(*count)-1)*(42-(2*(*count)));
        sum+=fi[*count];
        data[*count]=sum;
    }
}

void print_test4(int count, double *fi, double *data)//count ไว้บอกจำนวนตัว, *fi ไว้บอกค่าของแต่ละเทอม, *data ไว้บอกผลรวมค่า
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

int is_prime(int i)//รับตัวเลขมาแล้วคืนค่าไปว่า 0 ถ้าไม่เป็นจำนวนเฉพาะ และคืนเป็น 1 ไปถ้าเป็นจำนวนเฉพาะ
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

void print_test3(int count, double *fi, double *data)//count ไว้บอกจำนวนตัว, *fi ไว้บอกค่าที่จะแสดง, *data ไว้บอกผลรวมของค่า
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

void test3(int min, int max, double *fi, double *data, int *count)//min และ max ไว้บอกขอบเขตของการทำงาน , *fi เป็นอาเรย์ไว้เก็บตัวเลขจำนวนเฉพาะ , *data ไว้เก็บผลรวม, *count ไว้เก็บจำนวนตัวที่มี
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

int fibonacci(int n)//จะรับค่าตำแหน่งมาและคืนค่าfibonacciที่ตำแหน่งนั้นๆกลับไป
{
    if(n==0)
        return 0;
    else if(n<=2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);

}

void print_test2(int count,double *fi,double *data)//count ไว้บอกจำนวนตัว, *fi ไว้บอกค่าที่จะแสดง, *data ไว้บอกตำแหน่งของค่าที่จะแสดง
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

void test2(int n, double *fi, double *data,int *count)//n ไว้สำหรับบอกว่าจะเอากี่ตัว , *fi เป็นอาเรย์ที่เก็บค่าที่ตรงกับเงื่อนไข, *data เป็นอาเรย์ที่ไว้เก็บตำแหน่งของค่าที่ตรงเงื่อนไข, *count ไว้นับจำนวนครั้งที่มีตัวตรงเงื่อนไข
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

double sigma(int i)//รับค่าตำแหน่งมา และคืนค่าของคำตอบที่ตำแหน่งนั้นๆกลับไป
{double ans=0;
    for(int j=1;j<=i;j++)
    {
        ans = ans+j*2;
    }
    return ans;
}

double product(int i)//รับค่าตำแหน่งมา และคืนค่าของคำตอบที่ตำแหน่งนั้นๆกลับไป
{double ans=1;
    for(int j=1;j<=i;j++)
    {
        ans = ans*j;
    }
    return ans;
}

void print_test1(int count,double *fi,double *sum)//count ไว้บอกจำนวนข้อมูลทั้งหมด , *f1 คือเทอมต่างๆของข้อมูล, *sum คือผลรวมของเทอมต่างๆ
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

void test1(int n, double *fi, double *sum, int *count)//n ไว้กำหนดว่าจะมีกี่ตัว, *fi ไว้เก็บค่าของ เทอมต่างๆ, *sum ไว้เก็บผลรวมของค่า, *count ไว้นับจำนวนครั้งที่วนรอบ
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
int getint(int min,int max)//ไว้รับค่าตัวเลขให้ถูกต้องโดยมีขอบเขตจำกัดด้วย
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

int get_menu()//ไว้สร้างเมนูใช้งาน
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

