#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

#define LIMIT 5

struct node {
  double data;
  struct node *point;
} *front, *rear, *temp, *front1;

int count = 0;

void dequeue() {

  front1 = front;

  if (front1 -> point != NULL) {
    front1 = front1 -> point;
    free(front);
    front = front1;
  }
  count--;
}

void enqueue(int value) {

 if (rear == NULL) {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear -> point = NULL;
        rear -> data = value;
        front = rear;
    } else {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear -> point = temp;
        temp -> data = value;
        temp -> point = NULL;

        rear = temp;
    }
    count++;
    if (count > 5) {
      dequeue();
    }
}

int read_operation(char *target) {

  printf("TINYCALC> ");
  if(scanf(" %c", target)) {
    return 0;
  } else {
    return -1;
  }

}

int read_operands(double *op1, double *op2) {
  printf("TINYCALC> Input both operands\nTINYCALC> ");
  if (scanf("%lf %lf", op1, op2)) {
    return 2;
  } else {
    return -1;
  }
}

double get_value(double op1) {

  struct node* current = front;
  double count = 4;

  while (current != NULL) {
      if (count == op1) {
          return (current -> data);
      } else {
        count--;
        current = current -> point;
      }
  }
  return 0;
}

double compute_result(operation_t operation) {

  double former;
  double result;

  if (operation.operator == '+') {
    result = operation.operands[0] + operation.operands[1];
  } else if (operation.operator == '-') {
    result = operation.operands[0] - operation.operands[1];
  } else if (operation.operator == '*') {
    result = operation.operands[0] * operation.operands[1];
  } else if (operation.operator == '/') {
    result = operation.operands[0] / operation.operands[1];
  } else if (operation.operator == '&') {
    former = get_value(operation.operands[0]);
    result = former + operation.operands[1];
  } else if (operation.operator == '~') {
    former = get_value(operation.operands[0]);
    result = former - operation.operands[1];
  } else if (operation.operator == '^') {
    former = get_value(operation.operands[0]);
    result = former * operation.operands[1];
  } else if (operation.operator == '%') {
    former = get_value(operation.operands[0]);
    result = former / operation.operands[1];
  }
  enqueue(result);
  return result;
}


int main(void) {

  operation_t operation;
  char a = 'y';

  while (a == 'y') {
    printf("\nEnter an arithmetic operator( +, -, *, or / ) \nor memory operator ( &, ~, ^, or % ) to use \nprevious values for the 1st operand\n\n");
    read_operation(&operation.operator);
    read_operands(&operation.operands[0], &operation.operands[1]);
    printf("Result: %lf\n\n", compute_result(operation));
    printf("Run another calculation? Type (y/n)\nTINYCALC> ");
    scanf(" %c", &a);
      if (a == 'y') {
        continue;
      } else {
        break;
      }
  }

  return 0;
}
