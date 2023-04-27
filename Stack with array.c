#include<stdio.h>
int stack[100],i,j,choice, n,top=-1;
void push(void);
void pop(void);
void display(void);
void main()
{
printf("Enter number of elements in stack:");
scanf("%d",&n);
while(choice != 4)
{
printf("--------Available Options--------\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
 push();
 break;
case 2:
 pop();
 break;
case 3:
 display();
 break;
case 4:
 printf("---Exiting----");
 break;
default:
 printf("Enter valid choice......");
 break;
}
getch();
}
}
void push()
{
int item;

if(top == n)
{
printf("Stack overflow");
}
else
{
printf("Enter value to be entered:");
scanf("%d",&item);
top = top+1;
stack[top] = item;
}
}
void pop()
{
if(top == -1)
{
printf("Stack underflow");
}
else
{
//int item = stack[top];
top = top-1;
}
}
void display()
{
if(top > 0)
{
for(i=top;i>=0;i--)
{
printf("\nStack is:%d\n",stack[i]);
printf("Enter next choice:");
}
}
else
{
printf("Stack is empty....");
}
}
