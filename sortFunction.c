#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void bubbleSort(void*, size_t, size_t size, int (*)(const void*, const void*));
void (*getSorting(void*))(void*, size_t, size_t, int(*)(const void*, const void*));
int comp(const void* , const void* );
void swapg (void** , void**);


int main()
{   
    size_t size = 8;
    char* arr[] = {"bum", "trqs", "pras", "wrqs", "krix", "asdw", "monkey", "bottle"};
    getSorting("qsort")(arr, sizeof(arr)/sizeof(char*), sizeof(char*), comp);
    for (int i = 0; i < size; i++)
    {
         printf("Sorted: %s\n", arr[i]);
    }
    return 0;
}

void (*getSorting(void* fname))(void*,size_t,size_t,int(*)(const void*,const void*)){

    if((strcmp(fname, "bubbleSort")) == 0){
        return bubbleSort;
    }
    if((strcmp(fname, "qsort")) == 0){
        return qsort;
    }

}
 
void bubbleSort(void* array_, size_t n, size_t size, int (*comp)(const void*,const void*)){
   char** arr = (char**) array_;
   for (int i = 0; i < n-1; i++){
       for (int j = 0; j < (n-1); j++){
           if (comp((void *) arr[j], (void*) arr[j + 1]) > 0){
              swapg((void**)arr+j, (void**)(arr+j+1));
           }
       }
   }
}

int comp(const void* string1, const void* string2){
    char* str1 = *(char**) string1;
    char* str2 = *(char**) string2;
    int i=0;
    int str1_sz = strlen(str1);
    int str2_sz = strlen(str2);
    int min_size = str1_sz < str2_sz ? str1_sz : str2_sz;
    while(i < min_size && str1[i] == str2[i]){
        i++;
    }
    i += str1[i] == str2[i];
    return (i == min_size) ? (str1_sz - str2_sz) : (str1[i] - str2[i]);
}

void swapg(void** str1, void** str2){
    void* tmp;
    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}