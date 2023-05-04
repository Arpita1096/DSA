#include<stdio.h>
int fact(int , int);
void main()
{
    int n,result,init=1;
    printf("Enetr number:");
    scanf("%d",&n);
    result=fact(n,init);
    printf("Factorial is:%d",result);
}
int fact(int n , int init)
{
    if(n<=1)
    {
        return init;
    }
    else
    {
        return fact(n-1,n*init);
    }
}
