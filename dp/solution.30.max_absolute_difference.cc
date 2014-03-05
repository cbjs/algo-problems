#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int arr[], int i, int j) {
  for (int k = i; k <= j; k++) {
    cout << arr[k] << ", ";
  }
  cout << endl;
}

int maxAbsoluteDiff(int arr[], int n, int* a, int* b, int* c) {
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
  *a = 0, *b = 1, *c = 1;

  int rmin = 0, rmax = 0, rmini = n, rmaxi = n;
  for (int i = n - 1; i > 0; i--) {
    if (rmin < 0) {
      rmin += arr[i];
    } else {
      rmin = arr[i];
      rmini = i;
    }

    if (lmax[i - 1] - rmin > max_abs) {
      max_abs = lmax[i - 1] - rmin;
      *a = lmaxi[i - 1];
      *b = i;
      *c = rmini;
    }

    if (rmax > 0) {
      rmax += arr[i];
    } else {
      rmax = arr[i];
      rmaxi = i;
    }

    if (rmax - lmin[i - 1] > max_abs) {
      max_abs = rmax - lmin[i - 1];
      *a = lmini[i - 1];
      *b = i;
      *c = rmaxi;
    }
  }

  return max_abs;
}

int main(int argc, char *argv[])
{
  int arr[] = {2, -1, -2, 1, -4, 2, 8};
  int i, j, k;
  int max_abs = maxAbsoluteDiff(arr, sizeof(arr) / sizeof(int), &i, &j, &k);

  cout << "max abs: " << max_abs << endl;
  cout << "left subarray: ";
  printArr(arr, i, j - 1);
  cout << "right subarray: ";
  printArr(arr, j, k);
  return 0;
}
