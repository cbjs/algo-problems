#include <string.h>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void printArr(int arr[], int i, int j) {
  for (int k = i; k <= j; k++) {
    cout << arr[k] << ", ";
  }
  cout << endl;
}

int maxAbsoluteDiff(int arr[], int n, int* a, int* b, int* c, int* d) {
  if (0 == n) return 0;
  if (1 == n) return arr[0];

  int lmin[n], lmax[n], lmini[n], lmaxi[n];

  memcpy(lmin, arr, n * sizeof(int));
  memcpy(lmax, arr, n * sizeof(int));
  memset(lmini, 0, n * sizeof(int));
  memset(lmaxi, 0, n * sizeof(int));

  for (int i = 1; i < n; i++) {
    lmini[i] = lmaxi[i] = i;
    if (lmin[i - 1] < 0) {
      lmin[i] += lmin[i - 1];
      lmini[i] = lmini[i - 1];
    }
    if (lmax[i - 1] > 0) {
      lmax[i] += lmax[i - 1];
      lmaxi[i] = lmaxi[i - 1];
    }
  }

  // init results
  int max_abs = arr[0] - arr[1];
  *a = 0, *b = 0, *c = 1, *d = 1;

  int rmin = 0, rmax = 0, rmini = n, rmaxi = n;
  int xmin = arr[n - 1], xmini = n - 1, xminj = n - 1;
  int xmax = arr[n - 1], xmaxi = n - 1, xmaxj = n - 1;

  for (int i = n - 1; i > 0; i--) {
    if (rmin < 0) {
      rmin += arr[i];
    } else {
      rmin = arr[i];
      rmini = i;
    }

    if (xmin > rmin) {
      xmin = rmin;
      xmini = i;
      xminj = rmini;
    }

    if (lmax[i - 1] - xmin > max_abs) {
      max_abs = lmax[i - 1] - xmin;
      *a = lmaxi[i - 1];
      *b = i - 1;
      *c = xmini;
      *d = xminj;
    }

    if (rmax > 0) {
      rmax += arr[i];
    } else {
      rmax = arr[i];
      rmaxi = i;
    }

    if (xmax < rmax) {
      xmax = rmax;
      xmaxi = i;
      xmaxj = rmaxi;
    }

    if (xmax - lmin[i - 1] > max_abs) {
      max_abs = xmax - lmin[i - 1];
      *a = lmini[i - 1];
      *b = i - 1;
      *c = xmaxi;
      *d = xmaxj;
    }
  }

  return max_abs;
}

int main(int argc, char *argv[])
{
  int arr[] = {2, -1, -2, -5, 5, 2, 8};
  int i, j, k, l;
  int max_abs = maxAbsoluteDiff(arr, sizeof(arr) / sizeof(int), &i, &j, &k, &l);

  cout << "max abs: " << max_abs << endl;
  cout << "left subarray: ";
  printArr(arr, i, j);
  cout << "right subarray: ";
  printArr(arr, k, l);
  return 0;
}
