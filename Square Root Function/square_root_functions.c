# include <stdio.h>

  //========= complete this function
  void print_square_root(double number, double square_root) {

    printf("The square root of %.3f is %.6f.\n", number, square_root);

  }

  //====== complete this function
  double compute_square_root(double number, double guess) {

    double lo;
    double med;
    double hi;

    hi = number + 1;
    lo = 0;
    med = (lo + hi) / 2;
    while (hi - lo > 0.000001) {
      if ((med * med) > number) {
        hi = med;
      } else if ((med * med) < number) {
        lo = med;
      }
      med = (lo + hi) / 2;
    }

    return med;

  }

  int main() {

    double number;
    double guess;
    double square_root;

    printf("Enter a positive number: ");
    scanf("%lf", &number);
      if (number < 1) {
        printf("...Wrong. Try again! ");
        printf("Enter a positive number: ");
        scanf("%lf", &number);
      }
      if (number == 1) {
        print_square_root(1, 1);
        return (0);
      }
    printf("Enter a positive initial guess of the square root: ");
    scanf("%lf", &guess);
    square_root = compute_square_root(number, guess);
    print_square_root(number, square_root);

  }



