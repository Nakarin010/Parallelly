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
    int BUCKETSIZE = 2000000;
    int BUCKETNUM = 10; 
    int* array = (int*)malloc(length * sizeof(int));
    int a[BUCKETSIZE], b[BUCKETSIZE], c[BUCKETSIZE], d[BUCKETSIZE], e[BUCKETSIZE], f[BUCKETSIZE], g[BUCKETSIZE], h[BUCKETSIZE], k[BUCKETSIZE], y[BUCKETSIZE];   
    fill_ran(array,length,0,99999); // fill the array with random numbers

    for (int i = 0; i < sizeof(a); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 0 && array[j] < 999)
        {
            a[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(b); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 1000 && array[j] < 1999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(c); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 2000 && array[j] < 2999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(d); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 3000 && array[j] < 3999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(e); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 4000 && array[j] < 4999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(f); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 5000 && array[j] < 5999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(g); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 6000 && array[j] < 6999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(h); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 7000 && array[j] < 7999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(k); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 8000 && array[j] < 8999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    for (int i = 0; i < sizeof(y); i++)
    {for (int j = 0; j < sizeof(array); j++)
    {
        if(array[j] >= 9000 && array[j] < 9999)
        {
            b[i] = array[j];
        }
        
    } 
    }
    
    


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





