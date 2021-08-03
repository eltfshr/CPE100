#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct gradeInfo
{
    long long id;
    char name[40],grade[3];
    double mid,fin,atten,total,gpoint;
} gradeType;

struct statistic
{
    double min;
    double max;
    double mean;
    double sd;
    double sum;
    double sum2;
};

struct gradeCounts
{
    int countA;
    int countBp;
    int countB;
    int countCp;
    int countC;
    int countDp;
    int countD;
    int countF;
    double sum;
    double gpa;
};

void readFileToArrayStruct(char *fileName, gradeType cpe[],int *count)
{
    gradeType tmp;
    FILE *data;
    data = fopen(fileName,"r");
    while(fscanf(data,"%lld,%[^,],%lf,%lf,%lf",&tmp.id,tmp.name,&tmp.mid,&tmp.fin,&tmp.atten)!=EOF)
    {
        tmp.total = tmp.mid + tmp.fin + tmp.atten;
        cpe[(*count)++]=tmp;
    }
    fclose(data);
    printf("Readed %d records\n",*count);
}

double findMaxArray(double data[],int count)
{
    double max=0;
    for(int i=0;i<count;i++)
    {
        if(data[i]>max)
            max=data[i];
    }
    return max;
}
double findMinArray(double data[],int count)
{
    double min=40;
    for(int i=0;i<count;i++)
    {
        if((data)[i]<min)
            min=(data)[i];
    }
    return min;
}

void setGradeStatistic(gradeType cpe[],int count,struct gradeCounts *gradeNum, int A, int Bp,int B, int Cp,int C, int Dp,int D)
{
    struct statistic smid = {.sum = 0, .sum2 = 0},sfin = {.sum = 0, .sum2=0};
    struct statistic satten= {.sum = 0, .sum2 = 0},stotal = {.sum = 0, .sum2 = 0};
    double amid[100],afin[100],aatten[100],atotal[100];
    //setgrade
    for(int i=0;i<count;i++)
    {
        if(cpe[i].total>=A)
        {
            strcpy(cpe[i].grade,"A");
            cpe[i].gpoint = 4.0;
            gradeNum->countA++;
            gradeNum->sum+=4;

        }
        else if(cpe[i].total>=Bp)
        {
            strcpy(cpe[i].grade,"B+");
            cpe[i].gpoint = 3.5;
            gradeNum->countBp++;
            gradeNum->sum+=3.5;
        }
        else if(cpe[i].total>=B)
        {
            strcpy(cpe[i].grade,"B");
            cpe[i].gpoint = 3.0;
            gradeNum->countB++;
            gradeNum->sum+=3;
        }
        else if(cpe[i].total>=Cp)
        {
            strcpy(cpe[i].grade,"C+");
            cpe[i].gpoint = 2.5;
            gradeNum->countCp++;
            gradeNum->sum+=2.5;
        }
        else if(cpe[i].total>=C)
        {
            strcpy(cpe[i].grade,"C");
            cpe[i].gpoint = 2.0;
            gradeNum->countC++;
            gradeNum->sum+=2;
        }
        else if(cpe[i].total>=Dp)
        {
            strcpy(cpe[i].grade,"D+");
            cpe[i].gpoint = 1.5;
            gradeNum->countDp++;
            gradeNum->sum+=1.5;
        }
        else if(cpe[i].total>=D)
        {
            strcpy(cpe[i].grade,"D");
            cpe[i].gpoint = 1.0;
            gradeNum->countD++;
            gradeNum->sum+=1;
        }
        else
        {
            strcpy(cpe[i].grade,"F");
            cpe[i].gpoint = 0.0;
            gradeNum->countF++;
        }
        gradeNum->gpa = gradeNum->sum/count;
    }

    for(int i=0;i<count;i++)
    {


           //mid score and stats
        smid.sum+=cpe[i].mid;
        smid.sum2+=cpe[i].mid*cpe[i].mid;
        amid[i]=cpe[i].mid;

        //fin score and stats
        sfin.sum+=cpe[i].fin;
        sfin.sum2+=cpe[i].fin*cpe[i].fin;
        afin[i]=cpe[i].fin;

        //total score and stats
        stotal.sum+=cpe[i].total;
        stotal.sum2+=cpe[i].total*cpe[i].total;
        atotal[i]=cpe[i].total;

        //atten score and stats
        aatten[i]=cpe[i].atten;
        satten.sum+=cpe[i].atten;
        satten.sum2+=cpe[i].atten*cpe[i].atten;
    }
    printf("\n       min   max   mean   sd\n");

    //print mid
    smid.mean=smid.sum/count;
    smid.sd=sqrt((smid.sum2/count)-smid.mean*smid.mean);
    smid.max = findMaxArray(amid,count);
    smid.min = findMinArray(amid,count);
    printf("mid   %5.2lf %5.2lf %5.2lf %5.2lf\n",smid.min,smid.max,smid.mean,smid.sd);

    //print fin
    sfin.mean=sfin.sum/count;
    sfin.sd=sqrt((sfin.sum2/count)-sfin.mean*sfin.mean);
    sfin.max = findMaxArray(afin,count);
    sfin.min = findMinArray(afin,count);
    printf("fin   %5.2lf %5.2lf %5.2lf %5.2lf\n",sfin.min,sfin.max,sfin.mean,sfin.sd);

    //print atten
    satten.mean=satten.sum/count;
    satten.sd=sqrt((satten.sum2/count)-satten.mean*satten.mean);
    satten.max = findMaxArray(aatten,count);
    satten.min = findMinArray(aatten,count);
    printf("atten %5.2lf %5.2lf %5.2lf %5.2lf\n",satten.min,satten.max,satten.mean,satten.sd);

    //print total
    stotal.mean=stotal.sum/count;
    stotal.sd=sqrt((stotal.sum2/count)-stotal.mean*stotal.mean);
    stotal.max = findMaxArray(atotal,count);
    stotal.min = findMinArray(atotal,count);
    printf("total %5.2lf %5.2lf %5.2lf %5.2lf\n",stotal.min,stotal.max,stotal.mean,stotal.sd);

    //print grade stats
    printf("\n       A  B+ B  C+ C  D+ D  F\n");
    printf("count %2d %2d %2d %2d %2d %2d %2d %2d\n",gradeNum->countA,gradeNum->countBp,
           gradeNum->countB,gradeNum->countCp,gradeNum->countC,gradeNum->countDp,gradeNum->countD,gradeNum->countF);
    printf("GPA = %.2lf\n",gradeNum->gpa);

}

void displayIndividuals(gradeType cpe[], int count)
{
    printf("\nNo.     ID               Name                     Mid  Final Atten Total Grade GP\n");
    for(int i=0;i<count;i++)
    {
        printf("%2d. %lld %-32s %5.2lf %5.2lf %5.2lf %5.2lf  %-2s %5.2lf\n",i+1,cpe[i].id,cpe[i].name,cpe[i].mid,
           cpe[i].fin,cpe[i].atten,cpe[i].total,cpe[i].grade,cpe[i].gpoint);
    }
}

void sortByScore(gradeType cpe[],int count)
{
    gradeType tmp;
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-1-i;j++)
        {
            if(cpe[j].total<cpe[j+1].total)
            {
                tmp = cpe[j+1];
                cpe[j+1]=cpe[j];
                cpe[j]=tmp;
            }
        }
    }
}

void sortById(gradeType cpe[],int count)
{
    gradeType tmp;
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-1-i;j++)
        {
            if(cpe[j].id>cpe[j+1].id)
            {
                tmp = cpe[j+1];
                cpe[j+1]=cpe[j];
                cpe[j]=tmp;
            }
        }
    }
}

void searchByScore(gradeType cpe[],int count,double min, double max)
{
    char firstline='y';
    for(int i=0;i<count;i++)
    {
        if(cpe[i].total<=max&&cpe[i].total>=min)
        {
            if(firstline=='y')
            {
                printf("No.     ID               Name                     Mid  Final Atten Total Grade GP\n");
                firstline='n';
            }
            printf("%2d. %lld %-32s %5.2lf %5.2lf %5.2lf %5.2lf  %-2s %5.2lf\n",i+1,cpe[i].id,cpe[i].name,cpe[i].mid,
           cpe[i].fin,cpe[i].atten,cpe[i].total,cpe[i].grade,cpe[i].gpoint);
        }

    }
}

void searchByGrade(gradeType cpe[],int count,char *grade)
{
    char firstline='y';
    grade[0]=toupper(grade[0]);
    for(int i=0;i<count;i++)
    {
        if(strcmp(cpe[i].grade,grade)==0)
        {
            if(firstline=='y')
            {
                printf("No.     ID               Name                     Mid  Final Atten Total Grade GP\n");
                firstline='n';
            }
            printf("%2d. %lld %-32s %5.2lf %5.2lf %5.2lf %5.2lf  %-2s %5.2lf\n",i+1,cpe[i].id,cpe[i].name,cpe[i].mid,
           cpe[i].fin,cpe[i].atten,cpe[i].total,cpe[i].grade,cpe[i].gpoint);
        }

    }
}

void searchByName(gradeType cpe[],int count,char name[])
{
    char name2[40]="";
    for(int j=0;j<strlen(name);j++)
            name2[j]=toupper(name[j]);
    char firstline='y';
    for(int i=0;i<count;i++)
    {
        if(strstr(cpe[i].name,name2)!=NULL)
        {
            if(firstline=='y')
            {
                printf("No.     ID               Name                     Mid  Final Atten Total Grade GP\n");
                firstline='n';
            }
            printf("%2d. %lld %-32s %5.2lf %5.2lf %5.2lf %5.2lf  %-2s %5.2lf\n",i+1,cpe[i].id,cpe[i].name,cpe[i].mid,
           cpe[i].fin,cpe[i].atten,cpe[i].total,cpe[i].grade,cpe[i].gpoint);
        }
    }
}

int getMenu()
{
    int select;
    printf("\n Select Menu:\n");
    printf("1. Read a file\n");
    printf("2. Set and show grade statistics\n");
    printf("3. Display data\n");
    printf("4. Sort data by score\n");
    printf("5. Sort data by id\n");
    printf("6. Search data by score range\n");
    printf("7. Search data by grade\n");
    printf("8. Search data by name\n");
    printf("0. Exit\n");
    printf("Input: ");
    while(scanf("%d%*c",&select)!=1||select>8||select<0)
    {
        printf("Invalid input\n");
        printf("New Input: ");
        rewind(stdin);
    }
    return select;
}

int main()
{
    struct gradeCounts gradeNum={0,0,0,0,0,0,0,0,0,0};
    gradeType cpe[100];
    int count=0,select;
    char fileName[40];
    printf("Assignment 11 : Struct\n");
    do
    {
        select = getMenu();
        if(select == 1)
        {
            printf("File name: ");
            scanf("%s",fileName);
            readFileToArrayStruct(fileName,cpe,&count);
        }
        else if(select == 2)
        {
            int a,bp,b,cp,c,dp,d;
            if(count!=0)
            {
                printf("Set grades(A B+ B C+ C D+ D): ");
                scanf("%d %d %d %d %d %d %d",&a,&bp,&b,&cp,&c,&dp,&d);
                setGradeStatistic(cpe,count,&gradeNum,a,bp,b,cp,c,dp,d);
            }
            else
            {
                printf("Error: no data found");
            }
        }
        else if(select == 3)
        {
            displayIndividuals(cpe,count);
        }
        else if(select == 4)
        {
            sortByScore(cpe,count);
            printf("\nSorting completed\n");
        }
        else if(select == 5)
        {
            sortById(cpe,count);
            printf("\nSorting completed\n");
        }
        else if(select == 6)
        {
            int min=0,max=100;
            printf("Score range(min max): ");
            scanf("%d %d",&min,&max);
            searchByScore(cpe,count,min,max);
        }
        else if(select == 7)
        {
            char grade[3];
            printf("Grade to search: ");
            scanf("%s",grade);
            searchByGrade(cpe,count,grade);
        }
        else if(select == 8)
        {
            char name[30];
            printf("Name to search: ");
            scanf("%s",name);
            searchByName(cpe,count,name);
        }
    }while(select!=0);
    return 0;
}

