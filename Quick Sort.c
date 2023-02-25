#include<stdio.h>

int Partition(int a[],int low,int high){
    int pivot=a[low];
    int start=low;
    int end=high;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            int tem=a[start];
            a[start]=a[end];
            a[end]=tem;
        }
    }
    int tem=a[low];
    a[low]=a[end];
    a[end]=tem;
    return end;
}

void Qsort(int a[],int low,int high){
    if(low<high){
       int position = Partition(a,low,high);
       Qsort(a,low,position-1);
       Qsort(a,position+1,high);
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    Qsort(a,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}