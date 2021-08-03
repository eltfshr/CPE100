#include <stdio.h>
#include <time.h>
#include <ctype.h>
int main()
{
    char name[30],nickname[30],z;
    int x,y,count;
    short IsRight=0;
    srand(time(NULL));
    printf("\nAssignment3 : Random number generator\nYou are going to guess what number this program generated\n");
    printf("Please enter your name: ");
    scanf("%s",name);
    printf("Please enter your nickname: ");
    scanf("%s",nickname);
    printf("Hello %s or should we call you %s\n",name,nickname);
    do
    {
        count=0;
        IsRight=0;
        x=rand()%100+1;
        do
        {
            count++;
            printf("Enter your guess: ");
            scanf("%d",&y);
            if(y==x)
            {
                printf("You win!\n");
                IsRight = 1;
            }
            else
            {
                if(y>x)
                {
                    printf("Your guess is too high\n");
                }
                else
                {
                    printf("Your guess is too low\n");
                }
                if(count == 7 )
                {
                    printf("You lose.\nThe number is %d\n",x);
                }
            }
        }while(IsRight==0&&count<7);
        do
        {
            printf("Press y to play another game or press n to exit.");
            scanf(" %c",&z);
        }while(z!='y'&&z!='Y'&&z!='n'&&z!='N');
    }while(z=='y'||z=='Y');
    printf("\nEnd Program\n");
    return 0;
}
