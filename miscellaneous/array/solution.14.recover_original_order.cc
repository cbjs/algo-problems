#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

void reorder(int h[], int p[], int n) {
  // sort by height
  pair<int, int> hp[n];
  for (int i = 0; i < n; i++) hp[i] = {h[i], p[i]};

  sort(hp, hp + n, [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  });

  // reorder
  for (int i = 0; i < n; i++) {
    if (hp[i].second != i) {
      int t = hp[i].second;
      for (int j = i - 1; j >= t; j--) {
        swap(hp[j], hp[j + 1]);
      }
    }
  }

  // copy back to h
  for (int i = 0; i < n; i++) h[i] = hp[i].first;
}

void reorder_dup(int h[], int p[], int n) {
  // sort by height
  pair<int, int> hp[n];
  for (int i = 0; i < n; i++) hp[i] = {h[i], p[i]};

  sort(hp, hp + n, [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  });

  // reorder
  for (int i = 0; i < n; i++) {
    int t = 0, j = 0;
    while (t < hp[i].second) {
      if (hp[j].first > hp[i].first) t += 1;
      j += 1;
    }
    int k = i - 1;
    while (k >= j) {
      swap(hp[k], hp[k + 1]);
      k -= 1;
    }
  }

  // copy back to h
  for (int i = 0; i < n; i++) h[i] = hp[i].first;
}

int main(int argc, char *argv[])
{
  // generate random test case
  srand(time(NULL));
  int n = 10;
  int h[n], p[n];
  for (int i = 0; i < n; i++) {
    h[i] = rand() % 10 + 1;
    p[i] = 0;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) p[i] += 1;
    }
  }

  // shuffling two arrays
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    swap(h[i], h[j]);
    swap(p[i], p[j]);
  }
  cout << "height array: ";
  for_each(h, h + n, [](int v) { cout << v << ",\t"; });
  cout << endl;

  cout << "another array: ";
  for_each(p, p + n, [](int v) { cout << v << ",\t"; });
  cout << endl;

  reorder_dup(h, p, n);

  cout << "recovered height array: ";
  for_each(h, h + n, [](int v) { cout << v << ",\t"; });
  cout << endl;
  for (int i = 0; i < n; i++) {
    p[i] = 0;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) p[i] += 1;
    }
  }
  cout << "reordered another array: ";
  for_each(p, p + n, [](int v) { cout << v << ",\t"; });
  cout << endl;
}
