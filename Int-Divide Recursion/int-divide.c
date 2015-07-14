#include <stdio.h>

int int_divide(int a, int b) {

  if (b == 0) {
    return 0;
  } else if (a - b == 0) {
    return 1;
  } else if (a < b) {
    return 0;
  } else {
    return (1 + int_divide(a - b, b));
  }

}

int main(void) {

  int c = int_divide(10, 5);
  printf("%d\n", c);

  return 0;

}
