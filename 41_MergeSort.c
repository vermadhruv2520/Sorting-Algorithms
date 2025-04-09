#include <stdio.h>

void Merge(int A[], int l, int mid, int h){  // Merging two List

    int i=l, j=mid+1, k=0;
    int B[100];

    while(i<=mid && j<=h){             // Copying and comparing the elements

        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }

    while(i<=mid){                     // Copying the remaining elements
        B[k++]=A[i++];
    }

    while(j<=h){                       // Copying the remaining elements
        B[k++]=A[j++];
    }

    for(int i=l, k=0;i<=h;i++,k++){    // After copying the element transfer the element from low to high
        A[i]=B[k];
    }
}

void MergeSort(int A[], int n){

    int p,l,mid,h;
    
    for(p=2;p<=n;p=p*2){                   // It is for Passes
        for(int i=0;i+p-1<n;i=i+p){        // It is for merging all the list.

            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n){                          // If there are some element remaining.
        Merge(A,0,p/2-1,n-1);
    }
}

int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3};
    int n=10;

    MergeSort(A,n);

    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }

    return 0;
}