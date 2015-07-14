#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

/* insertion sort algorithm for array-based linked list */
void insertionSort(int *a, int num) {

  int *head = a;

  int i, j, c, temp, k = 0;

  for(i = 0; i < num; i++) {
      temp = *(head + i);
      j = i - 1;
      while (j >= 0 && temp < *(head + j)) {
        *(head + j + 1) = *(head + j);
        j--;
      }
    *(head + j + 1) = temp;
  }

 }

int main(void) {

  /* input the number of elements that will be in the array */
  int elements, num, count, array[LIMIT];
  printf("How many elements will be in your array? ");
  scanf("%d", &elements);
  if (elements > LIMIT) {
    printf("Oops! You can't enter more than ten elements. Try again!\n");
    scanf("%d", &elements);
  }

  /* allows user to input elements */
  printf("Enter your numbers: ");
    for (count = 0; count < elements; count++) {
      scanf("%d", &array[count]);
    }

  /* prints out sorted list */
  printf("\n*** Sorted List ***\n\n ");
    for (count = 0; count < elements; count++) {
      insertionSort(&*array, elements);
      printf("%d ", array[count]);
    }

  printf("\n");
  return 0;

}

 // for(i = 0; i < num; i++) {
 //    for (j = i + 1; j < num; j++) {
 //      if (a[i][k] > a[j][k]) {
 //        for (c = 0; c < 2; c++) {
 //          temp = a[i][c];
 //          a[i][c] = a[j][c];
 //          a[j][c] = temp;
 //        }
 //      }
 //    }
 //  }



