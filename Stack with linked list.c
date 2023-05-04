#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
}node;
node *top = 0;
void push(int);
void display();
void peek();
void pop();
void main()
{
    int x,choice;
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("Enter data to be pushed:");
                    scanf("%d",&x);
                    push(x);
                    break;
            case 2: display();
                    break;
            case 3: peek();
                    break;
            case 4: pop();
                    break;
            default: printf("Enter valid choice.");
        }
    }
}
void push(int x)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = x;
    ptr->next = top;
    top = ptr;
    printf("Item(%d) pushed in stack",x);
}
void display()
{
    node *temp;
    temp = top;
    if(top == 0)
    {
        printf("Empty stack.");
    }
    else
    {
        while(temp != 0)
        {
            printf("%d->",temp->info);
            temp = temp->next;
        }
    }
}
void peek()
{
    if(top == 0)
    {
        printf("Empty stack.");
    }
    else
    {
        printf("Top element:%d",top->info);
    }
}
void pop()
{
    node *temp;
    if(top == 0)
    {
        printf("Stack underflow.");
    }
    else
    {
        printf("Popped item:%d",temp->info);
        top = top->next;
        top--;
    }
}
