#include <stdio.h>

void InsertionSort(int A[], int n){

    int x,j;
    for(int i=0;i<n;i++){
        j=i-1;
        x=A[i];

        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main(){
    int A[]={11,13,7,2,6,9,4,5,10,3};
    int n=10;

    InsertionSort(A,n);

    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }

    return 0;
}