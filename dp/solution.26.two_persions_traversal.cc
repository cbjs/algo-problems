#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <time.h>

using namespace std;

vector<vector<int> > min_distance(const vector<vector<int> >& d) {
  int n = d.size();
  vector<vector<int> > partition(2, vector<int>());

  int D[n + 1][n + 1], T[n + 1];
  memset(D, 0, sizeof(D));
  memset(T, 0, sizeof(T));

  for (int i = 2; i <= n; i++) {
    D[i][i - 1] = INT_MAX;
    for (int j = 0; j < i - 1; j++) {
      // D[i][j]
      D[i][j] = D[i - 1][j] + d[i - 2][i - 1];

      // D[i][i - 1]
      int curdis = D[i - 1][j] + (j > 0 ? d[j - 1][i - 1] : 0);
      if (D[i][i - 1] > curdis) {
        D[i][i - 1] = curdis;
        T[i] = j;
      }
    }
  }

  int k = 0;
  for (int i = 1; i < n; i++) {
    if (D[n][i] < D[n][k]) k = i;
  }
  cout << "min_distance:" << D[n][k] << endl;

  int i = 0;
  while (n > 0) {
    partition[i].push_back(n);
    if (n == k + 1) {
      i = 1 - i;
      k = T[n];
    }
    n -= 1;
  }
  reverse(partition[0].begin(), partition[0].end());
  reverse(partition[1].begin(), partition[1].end());
  return partition;
}

int main(int argc, const char *argv[])
{
  // generate random testcase
  vector<vector<int> > matrix;
  int n = 5;
  matrix.resize(n, vector<int>(n));
  srand(time(NULL));
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
          int v = rand() % 10 + 1;
          matrix[i][j] = matrix[j][i] = v;
      }
  }
  // print distance matrix
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          printf("%5d", matrix[i][j]);
      }
      cout << endl;
  }
  // run algorithm
  vector<vector<int> > partition = min_distance(matrix);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < partition[i].size(); j++) {
      cout << partition[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
