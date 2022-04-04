#include <stdio.h>

void swap(int*a, int* b);
int part(int* arr, int low, int high);
void myQuickSort(int* arr, int low, int high);
void printArray(int* arr, size_t n);

int main(){
    int arr[]={1, 4, 7, 12, 32, 56};
    int n=sizeof(arr)/sizeof(arr[0]);

    myQuickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}







void swap(int*a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int part(int* arr, int low, int high){
    int a=arr[high];    
    int i=(low-1);

    for(int k=low; k<high;k++){
        if(arr[k]<=a){
            i++;
            swap(&arr[i], &arr[k]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    
    return (i+1);
}


void myQuickSort(int* arr, int low, int high){
    if(low<high){
        int x=part(arr, low, high);

        myQuickSort(arr, low, x-1);
        myQuickSort(arr, x+1, high);
   }
}

void printArray(int* arr, size_t n){
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
}