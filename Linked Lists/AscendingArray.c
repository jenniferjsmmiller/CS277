#include <stdio.h>
#include <stdlib.h>

/* creates defined data type node for linked list, with a value and a pointer to next node */
typedef struct node {
  int value;
  struct node *point;
} node;

/* insertion sort algorithm for linked list */
node * insertion_sort_asc(node* head, int num) {

  node *temp, *prev, *next;

  /* creates temporary value while reorganizing linked list */
  temp = (node*)malloc(sizeof(node));
  temp->value = num;
  temp->point = NULL;

  /* if value is not head value, make head the temp value */
  if (!head) {
    head = temp;
  /* makes next value the head value, null before */
  } else {
    prev = NULL;
    next = head;
    /* reorganizes rest of the list */
    while (next && next->value <= num) {
      prev = next;
      next = next->point;
    }
    /* if not the next value, previous points to the temp value*/
    if (!next) {
      prev->point = temp;
    } else {
      if (prev) {
        temp->point = prev->point;
        prev->point = temp;
      } else {
        temp->point = head;
        head = temp;
      }
    }
  }

  return head;

 }

 /* descending order insertion sort with linked list */
 node * insertion_sort_des(node* head, int num) {

  node *temp, *prev, *next;

  /* creates temporary value while reorganizing linked list */
  temp = (node*)malloc(sizeof(node));
  temp->value = num;
  temp->point = NULL;

  /* if value is not head value, make head the temp value */
  if (!head) {
    head = temp;
  /* makes next value the head value, null before */
  } else {
    prev = NULL;
    next = head;
    /* reorganizes rest of the list */
    while (next && next->value >= num) {
      prev = next;
      next = next->point;
    }
    /* if not the next value, previous points to the temp value*/
    if (!next) {
      prev->point = temp;
    } else {
      if (prev) {
        temp->point = prev->point;
        prev->point = temp;
      } else {
        temp->point = head;
        head = temp;
      }
    }
  }

  return head;

 }

 node * first_in_first_out(node* head, int num) {

  node *entry;

  entry = (node *)malloc(sizeof(node));

  entry -> value = num;
  entry -> point = head;

  return entry;

}

void print(node* head, node* p) {

   /* prints out sorted list */
  p = head;
  printf("\n  *** Sorted List ***\n\n ");
  while (p) {
    printf("%d ", p -> value);
    p = p -> point;
  }

}



int main(void) {

  int num, control = 1, count = 0;
  node *head, *head1, *head2, *p, *p1;
  head = NULL;
  head1 = NULL;

  /* allows user to input elements and counts them*/
  printf("Enter an integer or multiple integers separated by a space.\n");
  printf("  Type any character to quit input\n");
  while (control == 1) {
    control = scanf("%d", &num);
      if (control != EOF && control > 0) {
        head = insertion_sort_asc(head, num);
        head1 = insertion_sort_des(head1, num);
        head2 = first_in_first_out(head2, num);
      }
      count++;
  }
    count--;

  /* prints out different linked lists and count of elements*/
  if (control == 0) {
    printf("Read %d items", count);
    print(head, p);
    print(head1, p);
    print(head2, p);
    printf("\n");
  } else if (control == EOF) {
    printf("\nRead %d items", count);
    print(head, p);
    print(head1, p);
    print(head2, p);
    printf("\n");
  }

  return 0;

}




