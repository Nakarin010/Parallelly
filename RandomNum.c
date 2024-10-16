#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> // so that bool, true, and false can be used
// #include <omp.h>

#define BUCKETNUM 10; // 0-9 it's constant while BUCKETSIZE is vary 

void fill_ran(int array[], int length,int min,int max);
void bucket_sort(int array[], int length)
int main(void){
    srand(time(NULL) * getpid() ); // seed random number generator for
    int size = 0;
    printf("Here's the size of the array that can be generated");
    printf("We support 10000, 100000, 500000, 1000000, 2000000 \n");
    // int a[size];
    int* a = (int*)malloc(size * sizeof(int)); 
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    fill_ran(a,size,0,99999);
    for(int i=0; i<size;i++){
        printf("a[%d] = %d\n",i,a[i]);
    }    
}


void fill_ran(int array[], int length,int min,int max)
{   
    int new_random;
    // bool* unique = (bool*)calloc(max - min + 1, sizeof(bool)); 
    for(int i=0;i<length;i++){
        array[i] = (rand() % (max - min +1)) + min;  
    }
}















// void printRandoms(int min, int max, int count) {
//     printf("Random numbers between %d and %d: ", min, max);
//     // Loop that will print the count random numbers
//     for (int i = 0; i < count; i++) {

//         // Find the random number in the range [min, max]
//         int rd_num = rand() % (max - min + 1) + min;

//         printf("%d ", rd_num);
//     }
// }

// int main() {
//     int min = 0, max = 99999, count = 100000;
//     printRandoms(min, max, count);
//     return 0;
// }