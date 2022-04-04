#include <stdio.h>

int getDirection(int num);
int sumDigits(int number);
int elemntSrch(int *numbers,int* visited, size_t n, int pos );



int main(){
    return 0;
}

int getDirection(int num){
    if(sumDigits(num)%2==0){
        return 3;
    }
    else{
        return -2;
    }
}

int sumDigits(int number){
    int sum=0;
    while(number){
        sum+=number%10;
        number=number/10;
    }
    return sum;
}

int elemntSrch(int *numbers,int* visited, size_t n, int pos ){

    if(pos<0 || pos>=n || visited[pos]>0){
        return 0;
    }
    
    int steps = getDirection(numbers[pos]);
    visited[pos]=1;
    return 1+elemntSrch(numbers, visited, n, pos+steps);
}