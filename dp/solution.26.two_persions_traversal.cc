#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<vector<int> > min_distance(const vector<vector<int> >& d) {
  int n = d.size();
  vector<vector<int> > partition(2, vector<int>());

  int D[n + 1][n + 1], T[n + 1];
  memset(D, 0, sizeof(D));
  memset(T, 0, sizeof(T));

  for (int i = 1; i <= n; i++) {
    // D[i][j], j < i - 1
    for (int j = 0; j < i - 1; j++) {
      D[i][j] = D[i - 1][j] + d[i - 2][i - 1];
    }
    // D[i][i - 1]
    D[i][i - 1] = INT_MAX;
    for (int j = 0; j < i - 1; j++) {
      int curdis = D[i - 1][j] + (j > 0 ? d[j - 1][i - 1] : 0);
      if (D[i][i - 1] > curdis) {
        D[i][i - 1] = curdis;
        T[i] = j;
      }
    }
  }

  int k = 0;
  for (int i = 1; i < n; i++) {
    if (D[n][i] < D[n][k]) i = k;
  }
  cout << "min_distance:" << D[n][k] << endl;

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
