#include <string>
#include <algorithm>

using namespace std;

int minimum_moves_to_front(string A, string B)
{
  if (A.empty()) return 0;

  string a = A, b = B;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a != b) return -1;


  int n = A.size(), res = 0;
  int i = n - 1, j = n - 1, li = n;
  while (i >= 0) {
    if (A[i] == B[j]) {
      res += (li - i - 1);
      li = i;
      i--;
      j--;
      continue;
    }

    i--;
  }

  res += (li - i - 1);
  return res;
}
