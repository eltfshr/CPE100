#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkIdentifier(char *token)
{
    if(isalpha(token[0])||token[0]=='_')//����ҵ���á�繵���ѡ������_�������
    {
        for(int i=1;i<strlen(token);i++)
        {
            if(!(isalnum(token[i])||token[i]=='_'))//�������繵���ѡ�������Ţ����_���׹���0
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
    //����ҹ�������Ѻ�繵���Ţ��������� ���ա���Ѻ����ѡ�ô�ҹ��ѧ��е����ҵ�ͧ�Ѻ�����������͡ѹ�ó� 1x 1.1.1
     if((sscanf(token,"%lf%c",&i,&c)==1))
        return i;
     else
        return -1;

}

int checkOperator(char *token)
{
    if(strstr("+-*/^()",token)!=NULL)//��繵�ͧ��+-*/^(  )
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
        if(strcmp(token,functions[i])==0)//����������ҡѺ1㹪��Ϳѧ��ѹ��ҧ���������
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
    tok=strtok(buff," ");//�¡ʵ�ԧ��������觷���ͧ��ҧ
    while(tok!=NULL)
    {
        strcpy(token[i++],tok);
        tok=strtok(NULL," ");
    }
    return i;
}

void trimSpace(char buff[])
{
    while(buff[strlen(buff)-1]==' ')//�����ʵ�ԧ�ժ�ͧ��ҧ��ͷ����������
    {
        buff[strlen(buff)-1]='\0';//�Ѻ��ͧ��ҧ���µ���ѡ��\0��觶������繨ش���ͧʵ�ԧ
    }
}

void addWhiteSpace(char buff[])
{
    int i,j;
    char str[200]="";
    for(i=0,j=0;i<strlen(buff);i++)
    {
        if(strchr("+-*/^()",buff[i])!=NULL)//�����+-*/^(  )���������ͧ��ҧ��ҧ˹����Т�ҧ��ѧ����ѡ�ù���
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
    strcpy(buff,str);//copy str���buff
}

int main()
{
    int count;//���������纨ӹǹ���
    double temp;//���������纤�Ңͧ��繶���繵���Ţ
    char token[50][200];//������ͧ���
    char data[200]="",buff[200]="";//data��ͷ����������Ѻ�����Ũ�ԧ ��buff���copy data
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
