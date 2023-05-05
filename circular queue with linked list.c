#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
}node;
node * front = NULL;
node * rear = NULL;
void enqueue(int x);
void dequeue();
void display();
void peek();
void main()
{
    int x,choice;
    while(1)
    {
        printf("Choices available........\n");
        printf(" \n0. exit\n 1. Enqueue\n 2. Dequeue\n 3. peek\n 4. display\n");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("Enter value to be enqueued:");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            default: printf("Enter valid choice:");
        }
    }
}
void enqueue(int x)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = x;
    ptr->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}
void display()
{
    node *temp;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else 
    {
        temp = front;
        while(temp != NULL)
        {
        printf("%d->",temp->info);
        temp = temp->next;
        }
    }
}
void dequeue()
{
    node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("Dequeued item is:%d",front->info);
        front  = front->next;
        free(temp);
    }
}
void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Front element is:%d",front->info);
    }
}
