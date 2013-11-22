#include <climits.h>
#include <string.h>

struct Point {
  double x;
  double y;
};

double error_between(Point ps[], int i, int j) {
  if (j - i <= 1) return 0.0;
  double grad = (ps[j].y - ps[i].y) / (ps[j].x - ps[i].x), errors = 0.0;
  for (int k = i + 1; k < j; k++) {
    double y = grad * (ps[k].x - ps[i].x) + ps[i].y;
    errors += (ps[k].y - y) * (ps[k].y - y);
  }
  return errors;
}

double min_errors(Point ps[], int n, int k) {
  if (n <= 2 || n <= k) return 0.0;
  if (k < 2) return

  double error[n][k];
  memset(error, 0, sizeof(error));

  for (int i = n - 3; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      for (int i = 0; i < min(k, ); i++) {
        /* code */
      }
    }
  }
}
