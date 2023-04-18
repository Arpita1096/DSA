#include"stdio.h"
#include"conio.h"
#include<stdlib.h>
#include<process.h>

//Created structure
typedef struct linkList{

    int info;
    struct linkList *next;
} node;

//function declaration
void crateLinkList(node **head);
void traverseInOrder(node *head);
void traverseInReverseOrder(node *head);
node *searchInUnorderedList(node *head, int item);
void auxilliarySearch(node *head, node **ploc, node **loc, int item);
void insertAtBeginning(node **head, int item);
void insertAfterElement(node *head, int item, int after);
void deletefromBeginning(node **head);
void deleteFromEnd(node **head);
void deleteAfterElement(node *head, int after);
void revesreList(node **head);
void deleteList(node **head);

//main function
void main(){
    node *head;
    int choice, element, after;
    crateLinkList(&head);

    while(1){
        printf("\n~~Function available~~\n");
        printf("-------------------------------\n\n");
        printf(" 1. Insert at begginning  \n");
        printf(" 2. Insert at end  \n");
        printf(" 3. Insert after a given element  \n");
        printf(" 4. Traverse in Order  \n");
        printf(" 5. Traverse in reverse order  \n");
        printf(" 6. Delete from beginning\n");
        printf(" 7. Delete from end  \n");
        printf(" 8. Delete after a givig element  \n");
        printf(" 9.  Reverse Link List  \n");
        printf("10.  Exit  \n");
        printf("  Pick your choice (1-10)  \n");
        scanf("%d",&choice);

        switch(choice){
            case 1 : 
                        printf("\nEter element: ");
                        scanf("%d",&element);
                        void insertAtBeginning(&head, element);
                        break;
            case 2 : 
                        printf("\nEter element: ");
                        scanf("%d",&element);
                        void insertAtEnd(&head, element);
                        break;
            case 3 : 
                        printf("\nEter element: ");
                        scanf("%d",&element);
                        printf("\nEnter element after which to insert: ");
                        scanf("%d",&after);
                        void deleteAfterElement(head, element, after);
                        break;
            case 4 : 
                        if(head === NULL)
                            printf("\nList is empty....!");
                        else
                            traverseInOrder(head);
                            printf("\n Press any key to continue ");
                        break;
            case 5 :  
                        if(head === NULL)
                            printf("\nThe list is empty");
                        else
                            traverseInReverseOrder(head);
                            printf("\n Press any key to continue ");
                        break;
            case 6 :   
                        deletefromBeginning(&head);
                        break;
            case 7: 
                        deleteFromEnd(&head);
                        break;            
            case 8 : 
                        printf("\nEnter element after which to delet : ");
                        scanf("%d",&after);
                        deleteAfterElement(head, after);
                        break;
            case 9 :       
                        revesreList(&head);
                        break;
            case 10 :       
                        deleteList(&head);
                        exit(1);
        }
    }
}


void crateLinkList( node  *head){

    * head = NULL;
} 

void traverseInOrder(node *head){
    while(head != NULL){
        printf("%d",head->info);
        head = head->next;
    }
}

void traverseInReverseOrder(node *head){
    if(head-.next != NULL)
        traverseInReverseOrder(head->next);
        printf("%d\n",head->next);
}

node *searchInUnorderedList(node *head, int item){
    while( head != NULL) && (head->info != item)
        head = head->next;
    return head;
} 

node *searchInUnorderedList(node *head, int item){
    while(head != NULL){
        if(head->info == item)
            return head;
        else if(item <head->info)
            return NULL;
        else
            head = head->next;
    }
    return NULL;
}
void auxilliarySearch(node *head, node **ploc, node **loc, int item){
    int flag = 0;
    if(head == NULL)
        *ploC = *loc= NULL;
    else if (head->info == item){
        *ploC = NULL;
        *loc  = head;
    }
    else{
        *ploC = head;
        *loc = head->next;

        while((*loc != NULL) && (!flag)){
            if((*loc)-> info == item)
                flag = 1;
            else{
                *ploC = *loc;
                *loc = (*loc)->next;
            }
        }
    }
}


void insertAtBeginning(node **head, int item){
    node *ptr;
    ptr =(node *) malloc (sizeof(node));
    ptr->info = item;
    if(*head == NULL)
        ptr->next = NULL;
    else
        ptr->next = *head;
        *head = ptr;     
}

void insertAfterElement(node *head, int item, int after){
    node *ptr, *loc;
    ptr =  (node *) malloc (sizeof(node));
    ptr->info = item;
    ptr->next = NULL;
    if(*head == NULL)
        *head = ptr;
    else{
        loc = *head;
        while(loc->next != NULL)
        loc = loc->next;
        loc->next = ptr;
    }     
}
void insertAfterElement(node *head, int item, int after){
   node *ptr, *loc;
   loc = searchInUnorderedList(head, after);
   if(loc == (node *)NULL)  
        return;
    ptr = (node *) malloc (sizeof(node));
    ptr->info = item;
    ptr->next = loc->next;
    loc->next = ptr;  
}
void deletefromBeginning(node **head){
    node *ptr;
    if(*head == NULL)
        return;
    else{
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }    
}

void deleteFromEnd(node **head){
    node *ptr, *loc;
    if(*head == NULL)
        return;
    else if ((head)->next == (node) NULL){
        ptr = *head;
        *head = NULL;
        free(ptr);
    }
    else{
        ptr = *head;
        *head =NULL;
        while(ptr->next != NULL){
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        free(ptr);
    }
}
void deleteAfterElement(node *head, int after){
    node *ptr, *loc;
    loc = searchInUnorderedList(head, after);
    if(loc == (node*)NULL)
        return;
    ptr = loc->next;
    loc->next = ptr->next;
    free(ptr);   
}
void revesreList(node **head){
    node *preNode, currentNode, nextNode;
    currentNode = *head;
    nextNode= currentNode->head;
    preNode = NULL;
    currentNode->next = NULL;
    while(nextNode != NULL){
        preNode = currentNode;
        currentNode = nextNode;
        nextNode = currentNode->next;
        currentNode.next = preNode;
    }
    *head = currentNode;
}

void deleteList(node **head){
    node *ptr;
    while(*head != NULL){
        ptr =   *head;
        *head = (*head)->next;
        free(ptr);
    }
}
