#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkIdentifier(char *token)
{
    if(isalpha(token[0])||token[0]=='_')//เช็คว่าตัวแรกเป็นตัวอักษรหรือ_หรือไม่
    {
        for(int i=1;i<strlen(token);i++)
        {
            if(!(isalnum(token[i])||token[i]=='_'))//ถ้าไม่เป็นตัวอักษรหรือเลขหรือ_ให้คืนค่า0
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

double checkNumber(char *token)
{
    char c;
    double i;
    //เช็คว่านำโทเค็นมารับเป็นตัวเลขได้หรือไม่ โดยมีการรับตัวอักษรด้านหลังและตั้งว่าต้องรับได้ค่าเดียวเพื่อกันกรณี 1x 1.1.1
     if((sscanf(token,"%lf%c",&i,&c)==1))
        return i;
     else
        return -1;

}

int checkOperator(char *token)
{
    if(strstr("+-*/^()",token)!=NULL)//โทเค็นต้องเป็น+-*/^(  )
        return 1;
    else
        return 0;
}

int checkFunction(char *token)
{
    int i=0;
    char functions[10][5]={"sin","cos","tan","asin","acos","atan","sqrt","log","exp","pow"};
    for(i;i<10;i++)
    {
        if(strcmp(token,functions[i])==0)//เช็คว่าโทเค็นเท่ากับ1ในชื่อฟังก์ชันข้างบนหรือไม่
        {
            return 1;
        }
    }
    return 0;
}

int splitString(char token[][200],char buff[])
{
    char *tok;
    int i=0;
    tok=strtok(buff," ");//แยกสตริงเป็นโทเค็นโดยแบ่งที่ช่องว่าง
    while(tok!=NULL)
    {
        strcpy(token[i++],tok);
        tok=strtok(NULL," ");
    }
    return i;
}

void trimSpace(char buff[])
{
    while(buff[strlen(buff)-1]==' ')//เช็คว่าสตริงมีช่องว่างต่อท้ายหรือไม่
    {
        buff[strlen(buff)-1]='\0';//ทับช่องว่างด้วยตัวอักษร\0ซึ่งถือว่าเป็นจุดจบของสตริง
    }
}

void addWhiteSpace(char buff[])
{
    int i,j;
    char str[200]="";
    for(i=0,j=0;i<strlen(buff);i++)
    {
        if(strchr("+-*/^()",buff[i])!=NULL)//ถ้าเจอ+-*/^(  )ให้เพิ่มช่องว่างข้างหน้าและข้างหลังตัวอักษรนั้นๆ
        {
            str[j++]= ' ';
            str[j++]=buff[i];
            str[j++]= ' ';
        }
        else
        {
            str[j++]=tolower(buff[i]);
        }
    }
    strcpy(buff,str);//copy strให้buff
}

int main()
{
    int count;//ตัวแปรไว้เก็บจำนวนโทเค็น
    double temp;//ตัวแปรไว้เก็บค่าของโทเค็นถ้าเป็นตัวเลข
    char token[50][200];//อาเรย์ของโทเค็น
    char data[200]="",buff[200]="";//dataคือที่เอาไว้ไปรับข้อมูลจริง แต่buffไว้copy data
    while(1)
    {
        printf("Input: ");
        gets(data);
        strcpy(buff,data);
        addWhiteSpace(buff);
        trimSpace(buff);
        count=splitString(token,buff);
        for(int i=0;i<count;i++)
        {
            if(count==1&&strcmp("exit",token[i])==0)
            {
                return 0;
            }
            else if(checkOperator(token[i]))
            {
                printf("token[%2d] = \"%s\" \t is operator\n",i,token[i]);
            }
            else if((temp=checkNumber(token[i]))>=0)
            {
                printf("token[%2d] = \"%s\" \t is number %g\n",i,token[i],temp);
            }
            else if(checkFunction(token[i]))
            {
                printf("token[%2d] = \"%s\" \t is function\n",i,token[i]);
            }
            else if(checkIdentifier(token[i]))
            {
                printf("token[%2d] = \"%s\" \t is identifier\n",i,token[i]);
            }
            else
            {
                printf("token[%2d] = \"%s\" \t is error\n",i,token[i]);
            }
        }
        printf("\nType \"exit\" to end program\n");
    }
}
