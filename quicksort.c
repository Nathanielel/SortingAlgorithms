#include <stdio.h>
#include <stdlib.h>
#define MEDIAN_MIN 24


void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int get_median(int* A, int p, int q, int r){
  if ((A[p] > A[q]) != (A[p] > A[r]))
    return p;
  if ((A[q] > A[p]) != (A[q] > A[r]))
    return q;
  return r;
}

int partition(int* A, int p, int r){
  int len = r - p + 1;
  if (len >= MEDIAN_MIN)
    swap(&A[get_median(A, p, p + len>>1, r)], &A[p]);
  int pivot = A[p];
  int i = p-1, j = r+1;
  while (1){
    do {++i;} while (A[i] < pivot);
    do {--j;} while (A[j] > pivot);
    if (i >=j) return j;
    swap(&A[i], &A[j]);
  }
}

void quicksort(int* A, int p, int r){
  if (p < r){
    int q = partition(A, p, r);
    quicksort(A, p, q);
    quicksort(A, q+1, r);
  }
}

int main(){
  int vals_to_read;
  int* vals_to_sort;
  scanf("%d", &vals_to_read);
  vals_to_sort = calloc(vals_to_read, 4);
  for (int i = 0; i < vals_to_read; ++i){
    scanf("%d", &vals_to_sort[i]);
  }
  for (int i = 0; i < vals_to_read-1; ++i){
    printf("%d, ", vals_to_sort[i]);
  }
  printf("%d\n" , vals_to_sort[vals_to_read-1]);

  quicksort(vals_to_sort, 0, vals_to_read-1);

  printf("SORTED:\n");
  for (int i = 0; i < vals_to_read-1; ++i){
    printf("%d, ", vals_to_sort[i]);
  }
  printf("%d\n" , vals_to_sort[vals_to_read-1]);

  free(vals_to_sort);  
  return 0;
}
