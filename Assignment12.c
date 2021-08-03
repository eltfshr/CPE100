#include <stdio.h>

void readMatrix(double m[][10], int *row, int *col)
{
    printf("Number of rows: ");
    scanf("%d",row);
    printf("Number of cols: ");
    scanf("%d",col);
    for(int i=0;i<*row;i++)
    {
        for(int j=0;j<*col;j++)
        {
            printf("m[%d][%d] = ",i,j);
            scanf("%lf",&m[i][j]);
        }
    }
}

void printMatrix(double m[][10], int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%g ",m[i][j]);
        }
        printf("\n");
    }
}

int addMatrix(double m3[][10],int *row3,int *col3,double m1[][10],int row1,int col1,double m2[][10],int row2,int col2 )
{
    if(row1==row2&&col1==col2)
    {
        *row3=row1;
        *col3=col1;
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                m3[i][j]=m1[i][j]+m2[i][j];
            }
        }
    }


}

void transposeMatrix(double m2[][10],int *row2,int *col2,double m1[][10],int row1,int col1)
{
    *row2=row1;
    *col2=col1;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            m2[i][j]=m1[j][i];
        }
    }
}

int multiplyMatrix(double m3[][10],int *row3,int *col3,double m1[][10],int row1,int col1,double m2[][10],int row2,int col2)
{
    int sum;
    if(col1==row2)
    {
        *row3=row1;
        *col3=col2;
        for(int i=0;i<*row3;i++)
        {
            for(int j=0;j<*row3;j++)
            {
                for(int k=0;k<col1;k++)
                {
                    m3[i][j]+=m1[i][k]*m2[k][j];
                }
            }
        }
    }
}

void identityMatrix(double m[][10],int *row,int *col)
{
    int d;
    printf("Input dimension of the matrix: ");
    scanf("%d",&d);
    *row=d;
    *col=d;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(j==i)
            {
                m[i][j]=1;
            }
            else
            {
                m[i][j]=0;
            }
        }
    }
}

void fillMatrix(double m[][10],int *row,int *col)
{
    int d;
    printf("Input dimension of the matrix: ");
    scanf("%d",&d);
    *row=d;
    *col=d;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if((i+j)>=d-1)
            {
                m[i][j]=(i+j)-(d-2);
            }
            else
            {
                m[i][j]=0;
            }
        }
    }
}

int main()
{
    double m1[10][10],m2[10][10],m3[10][10];
    double mean=0,min=0,max=100,sd=0;
    int col1,col2,col3,row1,row2,row3;
    readMatrix(m1,&row1,&col1);
    readMatrix(m2,&row2,&col2);
    //addMatrix(m3,&row3,&col3,m1,row1,col1,m2,row2,col2);
    //transposeMatrix(m2,&row2,&col2,m1,row1,col1);
    multiplyMatrix(m3,&row3,&col3,m1,row1,col1,m2,row2,col2);
    //identityMatrix(m3,&row3,&col3);
    //fillMatrix(m3,&row3,&col3);
    printMatrix(m3,row3,col3);
    return 0;
}
