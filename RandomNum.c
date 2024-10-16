#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> // so that bool, true, and false can be used
// #include <omp.h>

// 0-9 it's constant while BUCKETSIZE is vary 
// 0-999 it's constant while BUCKETNUM is vary

void fill_ran(int array[], int length,int min,int max);


int* bucket_sort(int length){
    int BUCKETNUM = 10; 
    int BUCKETSIZE =1000; 
    int* array = (int*)malloc(length * sizeof(int));
    int a[BUCKETSIZE], b[BUCKETSIZE], c[BUCKETSIZE], d[BUCKETSIZE], e[BUCKETSIZE], f[BUCKETSIZE], g[BUCKETSIZE], h[BUCKETSIZE], i[BUCKETSIZE], j[BUCKETSIZE];   
    fill_ran(array,length,0,99999); // fill the array with random numbers

    for(int i=0;i<BUCKETNUM;i++){
        if( i==0){
            for(int j=0;j<BUCKETSIZE;j++){
                if(array[j] >= i*BUCKETSIZE && array[j] < (i+1)*BUCKETSIZE){
                    a[j] = array[j];
                }
            }
        }
    }













    // for(int i=0;i<length;i++){
    //     printf("a[%d] = %d\n",i,array[i]);
    // }


    return array;
}

int main(void){


    printf("Hello World\n");
    printf("-------------------\n");
    printf("-------------------\n");
    printf("10000\n");
    bucket_sort(10000);
    printf("-------------------\n");
    printf("-------------------\n");
    printf("100000\n");

    printf("-------------------\n");
    printf("-------------------\n");


    printf("500000\n");
    printf("-------------------\n");
    printf("-------------------\n");

    printf("1000000\n");
    printf("-------------------\n");
    printf("-------------------\n");  

    printf("2000000\n");
    printf("-------------------\n");
    printf("-------------------\n");

}


void fill_ran(int array[], int length,int min,int max)
{   
    int new_random;
    // bool* unique = (bool*)calloc(max - min + 1, sizeof(bool)); 
    for(int i=0;i<length;i++){
        array[i] = (rand() % (max - min +1)) + min;  
    }
}





