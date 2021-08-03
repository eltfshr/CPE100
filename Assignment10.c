#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *p1, const void *p2)
{
    return *(int*)p1-*(int*)p2;
}

//compare from small number to big number from sorted array
void compareReference(int itxt[],int counttxt, int ibin[], int countbin)
{
    double seconds;
    int i=0,j=0;
    while((i<counttxt)&&(j<countbin))
    {
        if(itxt[i]<ibin[j])
            i++;
        else if(itxt[i]>ibin[j])
            j++;
        else
        {
            printf("%d\n",itxt[i]);
            i++;
            j++;
        }
    }
}

//compare using binary search in the sorted array
void compareBinarySearch(int itxt[],int counttxt, int ibin[], int countbin)
{
    for(int i=0;i<counttxt;i++)
    {
        if((bsearch(&itxt[i],ibin,countbin,sizeof(int),compare))!=NULL)
        {
            printf("%d\n",itxt[i]);
        }
    }
}

void compareScan(int itxt[],int counttxt, int ibin[], int countbin)
{
    for(int i=0;i<counttxt;i++)
    {
        for(int j=0;j<countbin;j++)
        {
            if(itxt[i]==ibin[j])
            {
                printf("%d\n",itxt[i]);
            }
        }
    }
}
//used to read text file into an array
void readTextFile(FILE *txt, int itxt[], int *count)
{
    while(!(feof(txt)))
    {
        fscanf(txt,"%d",&itxt[(*count)++]);
    }
}
//used to read binary file into an array
void readBinaryFile(FILE *bin, int ibin[], int *count)
{
    while(!(feof(bin)))
    {
        fread(&ibin[(*count)++],sizeof(int),1,bin);
    }
}

int main ()
{
    clock_t t;
    int tmp;
    int itxt[100010],ibin[100010];
    int counttxt=0,countbin=0;
    FILE *bin,*txt;
    txt=fopen("./txt100000.txt","r");
    bin=fopen("./bin100000.bin","rb");
    readTextFile(txt,itxt,&counttxt);
    readBinaryFile(bin,ibin,&countbin);
    printf("Test #1\n");
    t=clock();//mark the time before test #1
    compareScan(itxt,counttxt,ibin,countbin);
    printf("Time used is %lf seconds\n\n",((double)(clock()-t))/CLOCKS_PER_SEC);
    //use ((double)(clock()-t)) to find how many clocks have passed and divide by CLOCKS_PER_SEC to find time in seconds
    qsort(ibin,countbin,sizeof(int),compare);//sort binary array
    printf("Test #2\n");
    t = clock();
    compareBinarySearch(itxt,counttxt,ibin,countbin);
    printf("Time used is %lf seconds\n\n",((double)(clock()-t))/CLOCKS_PER_SEC);
    qsort(itxt,counttxt,sizeof(int),compare);//sort text array
    printf("Test #3\n");
    t=clock();
    compareReference(itxt,counttxt,ibin,countbin);
    printf("Time used is %lf seconds\n\n",((double)(clock()-t))/CLOCKS_PER_SEC);
    return 0;
}
