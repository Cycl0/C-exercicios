#include <stdio.h>

void printArr(int* arr, size_t len) {
  printf("[");
  for(int i=0; i<len; ++i) {
    printf("%d", arr[i]);
    if(i == len - 1) break;
    printf(", ");
  }
  printf("]");
}

void swapArr(int* arr, size_t len) {
  for(int i=0; i<len/2; ++i) {
    int
      *a = &(arr[i]),
      *b = &(arr[len-i-1]);
      *a ^= *b ^= *a ^= *b;
  }
}

int main()
{
  int arr[] = {1,2,3,4,5};
  size_t arrLen = sizeof(arr)/sizeof(arr[0]);
  
  printArr(arr, arrLen);
  swapArr(arr, arrLen);
  printArr(arr, arrLen);
  
  return 0;
}
