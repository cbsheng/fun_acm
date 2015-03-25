#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
  double x[2], y[2];

  while (scanf("%lf%lf%lf%lf", x, y, x+1, y+1) != EOF) {
    printf("%.2f\n", sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2)));
  }

  return 0;
}