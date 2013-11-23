#include <climits>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Point {
  double x;
  double y;
};

double e(Point ps[], int i, int j) {
  if (j - i <= 1) return 0.0;
  double grad = (ps[j].y - ps[i].y) / (ps[j].x - ps[i].x), errors = 0.0;
  for (int k = i + 1; k < j; k++) {
    double y = grad * (ps[k].x - ps[i].x) + ps[i].y;
    errors += (ps[k].y - y) * (ps[k].y - y);
  }
  return errors;
}

double min_errors(Point ps[], int N, int K) {
  if (N <= 2 || N <= K) return 0.0;
  if (K < 2) return INFINITY;
  if (K == 2) return e(ps, 0, N - 1);

  double error[N][K];
  memset(error, 0, sizeof(error));

  for (int i = 2; i < N; i++) {
    error[i][1] = e(ps, 0, i);
    for (int k = 2; k < K; k++) error[i][k] = error[i][1];

    for (int j = 0; j < i; j++) {
      double et = e(ps, j, i);
      for (int k = 2; k < K; k++) {
        double ec = et + error[j][k - 1];
        if (ec < error[i][k]) error[i][k] = ec;
      }
    }
  }

  return error[N - 1][K - 1];
}

int main(int argc, char *argv[])
{
  Point ps[] = {
    {0, 0},
    {0.5, 0.23},
    {1, 0.5},
    {2, 2.3},
    {3, 1.8},
    {4, 4.1}
  };
  int N = sizeof(ps) / sizeof(Point);
  int K = N - 2;
  cout << N << endl;
  cout << K << endl;
  cout << "min_errors:" << min_errors(ps, N, K) << endl;
  return 0;
}
