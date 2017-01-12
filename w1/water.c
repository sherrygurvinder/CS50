#include<stdio.h>

int get_int()
{
int n;
printf("No of minutes taken by shower :");
scanf("%d",&n);

return n;
}

void main()
{

int minutes=get_int();
printf("Minutes : %d \n Bottles : %d \n ",minutes,minutes*12);

}
