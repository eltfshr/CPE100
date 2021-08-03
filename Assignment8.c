#include <stdio.h>
#include <math.h>
void add_data(double data[],int *count)
{
    double a;
    printf("Enter data(type characters to stop): ");
    while(scanf("%lf",&a)==1&&a>=0)
    {
        data[*count]=a;
        (*count)++;
    }
    if(a<0)
        printf("Warning: negative numbers are not accepted\n");

    rewind(stdin);
}

void print_data(double data[],int count)
{
    for(int i=0;i<count;i++)
    {
        printf("data[%d] = %g\n",i,data[i]);
    }
}

void calculate_stat(double data[],int count,double *min,double *max,double *mean,double *sd)
{
    double sum=0,sum2=0;
    *min=data[0];
    *max=data[0];
    for(int i=0;i<count;i++)
    {
        sum+=data[i];
        sum2+=data[i]*data[i];
        if(data[i]>*max)
            *max=data[i];
        if(data[i]<*min)
            *min=data[i];
    }
    *mean=sum/count;
    *sd=sqrt((sum2/count)-*mean**mean);
}

int find_number(double data[],int count,int number,int start)
{
    for(int i=start;i<count;i++)
    {
        if(data[i]==number)
            return i;
    }
    return -1;
}

void delete_data(double data[],int *count,double number,int start)
{
    int i=find_number(data,*count,number,start);

    if(i>=0)
    {
        for(i;i<*count;i++)
        {
            data[i]=data[i+1];
        }
        (*count)--;
        printf("Deleted %g\n",number);
    }
    else
        printf("Error: cannot find %g\n",number);
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
    printf("***********************************************\n");
    printf("* My Test function                            *\n");
    printf("***********************************************\n");
    printf("* 1. Add data                                 *\n");
    printf("* 2. Delete data                              *\n");
    printf("* 3. Calculate statistics                     *\n");
    printf("* 4. Print data                               *\n");
    printf("* 0. exit                                     *\n");
    printf("***********************************************\n");
    printf("Enter menu number : ");
    select = getint(0,4);
    return select;
}

int main()
{
    int select;
    double data[100];
    int count=0,start;
    double min,max,mean,sd,number;
    do
    {
        select = get_menu();
        if(select == 1)
        {
            add_data(data,&count);
            print_data(data,count);
            printf("\n");
        }
        else if(select == 2)
        {
            if(count>0)
            {
               char ch;
                printf("Which number to delete: ");
                scanf("%lf",&number);
                printf("Where to start deletion(first data is at 0): ");
                start = getint(0,count);
                printf("Delete confirmation(Y/N): ");
                scanf("%c",&ch);
                if(ch=='Y'||ch=='y'){
                    delete_data(data,&count,number,start);
                    print_data(data,count);
                    printf("\n");
                }
                else
                    printf("Canceled deletion\n\n");
            }
            else
                printf("Error: no data found\n");
            printf("\n");
        }
        else if(select == 3)
        {
            if(count>1)
            {
                calculate_stat(data,count,&min,&max,&mean,&sd);
                printf("Min = %g    Max = %g\n",min,max);
                printf("Mean = %g   SD = %g\n",mean,sd);
            }
            else
                printf("Error: must have 2 or more data\n");
            printf("\n");

        }
        else if(select == 4)
        {
            if(count>0)
                print_data(data,count);
            else
                printf("Error: no data found\n");
            printf("\n");
        }
    }while(select!=0);

    return 0;
}
