#include <stdio.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void BubbleSort(int A[], int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){

            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag=1;       
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int A[]={3,7,9,10,6,5,11,4,11,2};
    int n=10;

    BubbleSort(A,n);

    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }

    return 0;
}