#include<stdio.h>
void printArray(int a[],int n);
void selectionSort(int a[],int n);
void main(){
    int a[5],i;
    int size=sizeof(a)/sizeof(a[0]);
    printf("Enter elements of array:\n");
    for(i=1;i<=5;i++){
        scanf("%d",&a[i]);
    }
    printf("Array before sorting:");
    printArray(a,size);
    selectionSort(a,size);
    printf("\nArray after sorting:");
    printArray(a,size);
}
void printArray(int a[],int n)
{
    int i;
    for(i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}
void selectionSort(int a[],int n){
    int temp,small,loc,i,j;
    for(i=1;i<=(n-1);i++){
        small=a[i];
        loc=i-1;
        for(j=i;j<=n-1;j++){
            if(a[j]<small){
                small=a[j];
                loc=j;
            }
        }
            if(loc!=(i-1)){
            temp=a[i-1];
            a[i-1]=a[loc];
            a[loc]=temp;
        
        
        }
    }
}
