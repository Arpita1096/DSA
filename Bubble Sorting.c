#include<stdio.h>
void printArray(int a[],int n);
void bubbleSort(int a[],int n);
void main(){
    int a[5],i;
    int size = sizeof(a)/sizeof(a[0]);
    printf("Enter array elements:\n");
    for(i=0;i<=5;i++){
        scanf("%d",&a[i]);
    }
    printf("Array before sorting:\n");
    printArray(a,size);
    bubbleSort(a,size);
    printf("\nArray after sorting:\n");
    printArray(a,size);
}
void printArray(int a[],int n){
    int i;
    for(i=0;i<=n;i++){
        printf("%d ",a[i]);
    }
}
void bubbleSort(int a[],int n){
    int j,k,temp;
    for(k=1;k<=n;k++){
        for(j=0;j<=n-k;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
