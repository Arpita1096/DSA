#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int coeff;
    int power;
    struct nodetype *next;
}node;
void insert(node **poly, int coeff, int power)
{

    node *ptr = (node *)malloc(sizeof(node));
    ptr->coeff = coeff;
    ptr->power = power;
    ptr->next = NULL;
    if(*poly == NULL)
    {
        *poly = ptr;
        return;
    }
    node *curr = *poly;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = ptr;
}
void print(node *poly)
{
    if(poly == NULL)
    {
        printf("0\n");
        return;
    }
    node *curr = poly;
    while(curr != NULL)
    {
        printf("%dx^%d",curr->coeff,curr->power);
        if(curr->next != NULL)
        {
            printf(" + ");
        }
        curr = curr->next;
    }
    printf("\n");
}
node *addPoly(node *poly1,node *poly2)
{
    node *result = NULL;
    while (poly1!=NULL && poly2!=NULL)
    {
        if(poly1->power == poly2->power)
        {
            insert(&result,poly1->coeff+poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->power > poly2->power)
        {
            insert(&result,poly1->coeff,poly2->coeff);
            poly1 = poly1->next;
        }
        else{
            insert(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
    }
    while(poly1 != NULL)
    {
        insert(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
    while(poly2 != NULL)
    {
        insert(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
    return result; 
}
int main()
{
    node *poly1 = NULL;
    insert(&poly1, 5, 4);
    insert(&poly1, 3, 2);
    insert(&poly1, 1, 0);
     
    node *poly2 = NULL;
    insert(&poly2, 4, 4);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);

    printf("First polynomial: \n");
    print(poly1);

    printf("Second polynomial: \n");
    print(poly2);

    node *result = addPoly(poly1,poly2);
    printf("Result: ");
    print(result);
    return 0;
}
