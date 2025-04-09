#include <stdio.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[], int l, int h){
    int pivot=A[l];
    int i=l,j=h;

do{
    do {i++;} while(A[i]<=pivot);
    do {j--;} while(A[j]>pivot);

    if(i<j)
    swap(&A[i], &A[j]);
}

    while(i<j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}


int main(){
    int A[]={3,7,9,10,6,5,11,4,11,2};
    int n=10;

    QuickSort(A,0,10);

    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }

    return 0;
}





