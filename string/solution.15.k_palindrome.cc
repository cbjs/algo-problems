#include <string.h>

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool kPalindrome(const string& str, int k) {
  int n = str.size();
  if (n <= 1) return true;

  unsigned int ed[n + 1][n + 1];
  memset(ed, 0xfe, sizeof(ed));

  for (int i = 0; i < n + 1; i++) ed[0][i] = ed[i][0] = i;

  for (int i = 1; i <= n; i++) {
    int s = max(1, i - k), e = min(i + k, n);
    for (int j = s; j <= e; j++) {
      if (str[i - 1] == str[n - j]) ed[i][j] = ed[i - 1][j - 1];

      ed[i][j] = min(ed[i][j], 1 + ed[i - 1][j]);
      ed[i][j] = min(ed[i][j], 1 + ed[i][j - 1]);
    }
  }

  return ed[n][n] <= 2 * k;
}

int main(int argc, const char *argv[])
{
  cout << "abxa" << kPalindrome("abxa", 1) << endl;
  cout << "abdxa" << kPalindrome("abdxa", 1) << endl;
  cout << "abaxdzaba" << kPalindrome("abaxdzaba", 2) << endl;
  return 0;
}
