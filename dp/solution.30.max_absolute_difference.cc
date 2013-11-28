#include <string.h>

#include <iostream>
#include <algorithm>

using namespace std;

int maxAbsoluteDiff(int arr[], int n) {
  if (0 == n)
  {
    return 0;
  }
  else if (1 == n)
  {
    return arr[0];
  }

  int lmin[n], lmax[n], rmin[n], rmax[n];

  memcpy(lmin, arr, n * sizeof(int));
  memcpy(lmax, arr, n * sizeof(int));
  memcpy(rmin, arr, n * sizeof(int));
  memcpy(rmax, arr, n * sizeof(int));

  for (int i = 1; i < n; i++) {
    if (lmin[i - 1] < 0) {
      lmin[i] += lmin[i - 1];
    }
    if (lmax[i - 1] > 0) {
      lmax[i] += lmax[i - 1];
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    if (rmin[i + 1] < 0)
    {
      rmin[i] += rmin[i + 1];
    }
    if (rmax[i + 1] > 0)
    {
      rmax[i] += rmax[i + 1];
    }
  }


  int l_m = arr[0];
  int l_n = arr[0];
  int max_abs = abs(arr[1] - arr[0]);
  for (int i = 0; i < n-1; i++) {
    if(lmax[i] > l_m)
    {
      l_m = lmax[i];
    }

    if(lmin[i] < l_n)
    {
      l_n = lmin[i];
    }

    max_abs = max(abs(l_m - rmin[i+1]), max_abs);
    max_abs = max(abs(l_n - rmax[i+1]), max_abs);
  }

  return max_abs;
}

int main(int argc, char *argv[])
{
  int arr[] = {2, -1, -2, 1, -4, 2, 8};
  cout << maxAbsoluteDiff(arr, sizeof(arr) / sizeof(int));
  return 0;
}
