#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> // so that bool, true, and false can be used
// #include <omp.h>

// 0-9 it's constant while BUCKETSIZE is vary 
// 0-999 it's constant while BUCKETNUM is vary
// number threads are 1 4 8 12 16

void fill_ran(int array[], int length,int min,int max);
void sortindi (int array[]);
int compare (const void * a, const void * b);
int* bucket_sort(int length){
    int BUCKETSIZE = 2000000;
    int BUCKETNUM = 10; 
    int* array = (int*)malloc(length * sizeof(int));

 // Dynamically allocate bucket arrays
    int *a = malloc(BUCKETSIZE * sizeof(int));
    int *b = malloc(BUCKETSIZE * sizeof(int));
    int *c = malloc(BUCKETSIZE * sizeof(int));
    int *d = malloc(BUCKETSIZE * sizeof(int));
    int *e = malloc(BUCKETSIZE * sizeof(int));
    int *f = malloc(BUCKETSIZE * sizeof(int));
    int *g = malloc(BUCKETSIZE * sizeof(int));
    int *h = malloc(BUCKETSIZE * sizeof(int));
    int *k = malloc(BUCKETSIZE * sizeof(int));
    int *y = malloc(BUCKETSIZE * sizeof(int));

    // Check if all bucket allocations were successful
    if (!a || !b || !c || !d || !e || !f || !g || !h || !k || !y) {
        fprintf(stderr, "Memory allocation for buckets failed\n");
        // Free any allocated memory before exiting
        free(array);
        free(a); free(b); free(c); free(d); free(e);
        free(f); free(g); free(h); free(k); free(y);
        exit(EXIT_FAILURE);
    }
    // Initialize bucket counters
    int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_e = 0, 
        count_f = 0, count_g = 0, count_h = 0, count_k = 0, count_y = 0;

    fill_ran(array, length, 0, 99999); // Fill the array with random numbers

    // Distribute array elements into buckets
    for (int j = 0; j < length; j++) {
        int value = array[j];
        if (value >= 0 && value < 999) {
            if (count_a < BUCKETSIZE) a[count_a++] = value;
        } else if (value >= 1000 && value < 2000) {
            if (count_b < BUCKETSIZE) b[count_b++] = value;
        } else if (value >= 2000 && value < 3000) {
            if (count_c < BUCKETSIZE) c[count_c++] = value;
        } else if (value >= 3000 && value < 4000) {
            if (count_d < BUCKETSIZE) d[count_d++] = value;
        } else if (value >= 4000 && value < 5000) {
            if (count_e < BUCKETSIZE) e[count_e++] = value;
        } else if (value >= 5000 && value < 6000) {
            if (count_f < BUCKETSIZE) f[count_f++] = value;
        } else if (value >= 6000 && value < 7000) {
            if (count_g < BUCKETSIZE) g[count_g++] = value;
        } else if (value >= 7000 && value < 8000) {
            if (count_h < BUCKETSIZE) h[count_h++] = value;
        } else if (value >= 8000 && value < 9000) {
            if (count_k < BUCKETSIZE) k[count_k++] = value;
        } else if (value >= 9000 && value < 10000) {
            if (count_y < BUCKETSIZE) y[count_y++] = value;
        }
    }
    printf("Bucket A: ");
    for (int i = 0; i < count_a; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Sort each bucket
    #pragma omp parallel sections
    {
    #pragma omp section
    qsort(a, count_a, sizeof(int), compare); 
    #pragma omp section
    qsort(b, count_b, sizeof(int), compare);
    
    #pragma omp section
    qsort(c, count_c, sizeof(int), compare);
    #pragma omp section
    qsort(d, count_d, sizeof(int), compare);
    #pragma omp section
    qsort(e, count_e, sizeof(int), compare);
    #pragma omp section
    qsort(f, count_f, sizeof(int), compare);
    #pragma omp section
    qsort(g, count_g, sizeof(int), compare);
    #pragma omp section
    qsort(h, count_h, sizeof(int), compare);
    #pragma omp section
    qsort(k, count_k, sizeof(int), compare);
    #pragma omp section
    qsort(y, count_y, sizeof(int), compare);
    }
    printf("\n");
    // Example: Print sorted buckets (only Bucket A for brevity)
    printf("Bucket A: ");
    for (int i = 0; i < count_a; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    

/* =================================================================
    TODO 
    // - merge the buckets together and then sort the merged array
    // then return the sorted array
    // don't forget to utilize the OpenMP
*/
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
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}






