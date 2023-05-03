#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x);
void dequeue();
void display();
void peek();
void main()
{
    int choice,x;
    while(1)
    {
        printf("Available options....");
        printf("1. enqueue\n 2. dequeue\n 3.peek/front\n 4. display \n 5. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter item to be inserted:");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: printf("Enter valid choice:");
        } 
    }
}
void enqueue(int x)
{
    if(rear == N-1)
    {
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear =0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
    printf("Element(%d) enqueued",x);
}
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue underflow");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("Dequeued element:%d",queue[front]);
    }
}
void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Empty queue");
    }
    else
    {
        for(int i=front ; i<rear ; i++)
        {
            printf("Item are:%d",queue[i]);
           // front++;
        }
    }
}
void peek()
{
    if(front == -1 && rear==-1)
    {
        printf("Empty queue");
    }
    else
    {
        printf("item is:%d",queue[front]);
    }
}
