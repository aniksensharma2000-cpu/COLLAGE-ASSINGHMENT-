#include<stdio.h>
int main()
{
    int sec,h,m,s;
    printf("Enter total seconds");
    scanf("%d",&sec);
    if(sec>0)
    {   h=sec/3600;
        m=(sec%3600)/60;
        s=(sec%3600)%60;
        printf("Time is: %d hours, %d minutes and %d seconds",h,m,s); 
    }
    else
    {
        printf("wrong input");
    }
    return 0;
}