#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<vector<int> > min_distance(const vector<vector<int> >& d) {
  int n = d.size();
  vector<vector<int> > partition(2, vector<int>());

  int S[n], T[n], D[n], A[n];
  memset(S, 0, sizeof(S));
  memset(T, 0, sizeof(T));
  memset(D, 0, sizeof(D));
  memset(A, 0, sizeof(A));

  for (int i = 0; i < n; i++) {
    int minj = i - 1;
    S[i] = INT_MAX;
    for (int j = i - 1; j >= 0; j--) {
      int curdis = S[j] + D[j + 1] + d[j][i];
      int k = j - 1;
      while (k >= 0 && T[k] == T[j]) k--;
      if (k >= 0) curdis += d[k][j + 1];
      if (S[i] > curdis) {
        S[i] = curdis;
        minj = j;
      }
      if (i >= 2 && j < i - 1) D[j] += d[i - 2][i - 1];
    }
    if (S[i] > D[0]) {
      S[i] = D[0];
      minj = -1;
    }

    int k = 0;
    if (minj == -1) {
      T[i] = 1;
    } else {
      T[i] = T[minj];
      k = 1 - T[i];
    }
    for (int j = minj + 1; j < i; j++) {
      T[j] = k;
    }
  }

  cout << "min_distance:" << S[n - 1] << endl;

  for (int i = 0; i < n; i++) partition[T[i]].push_back(i);
  return partition;
}

int main(int argc, const char *argv[])
{
  vector<vector<int> > d = {
    {0, 1, 5, 3},
    {1, 0, 5, 2},
    {5, 5, 0, 6},
    {3, 2, 6, 0}
  };
  vector<vector<int> > partition = min_distance(d);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < partition[i].size(); j++) {
      cout << partition[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
