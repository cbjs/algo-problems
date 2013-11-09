#include <string>
#include <string.h>

using namespace std;

string shortest_palindrome(string base) {
  if (base.size() <= 1) return base;

  // initialize
  int n = base.size(), len[n][n];
  char track[n][n];
  memset(len, 0, sizeof(len));
  memset(track, 0, sizeof(track));
  for (int i = 0; i < n; i++) {
    len[i][i] = 1;
    track[i][i] = base[i];
  }

  // compute in bottom-up fashion
  for (int l = 2; l <= n; l++) {
    int i = 0;
    while (i + l <= n) {
      int j = i + l - 1;
      if (base[i] == base[j]) {
        track[i][j] = base[i];
        len[i][j] = 2 + len[i + 1][j - 1];
      } else {
        if (len[i + 1][j] < len[i][j - 1]) {
          track[i][j] = base[i];
          len[i][j] = 2 + len[i + 1][j];
        } else if (len[i + 1][j] > len[i][j - 1]) {
          track[i][j] = base[j];
          len[i][j] = 2 + len[i][j - 1];
        } else {
          track[i][j] = (base[i] < base[j] ? base[i] : base[j]);
          len[i][j] = 2 + len[i + 1][j];
        }
      }
      i += 1;
    }
  }

  // build palindrome result
  int i = 0, j = n - 1;
  string result;
  while (i <= j) {
    result.push_back(track[i][j]);
    if (base[i] == base[j]) {
      i += 1;
      j -= 1;
      continue;
    }

    if (track[i][j] == base[i]) {
      i += 1;
    } else {
      j -= 1;
    }
  }

  int k = result.size() - 1;
  if (i - j == 2) k -= 1;
  while (k >= 0) result.push_back(result[k--]);
  return result;
}
