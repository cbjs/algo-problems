#include <iostream>
#include <string>

using namespace std;

int walprimes(const string& s) {
  return _walprimes(s, 2) + _walprimes(s, 3) + _walprimes(s, 5) + _walprimes(s, 7)
        - _walprimes(s, 2 * 3) - _walprimes(s, 2 * 5) - _walprimes(s, 2 * 7)
        - _walprimes(s, 3 * 5) - _walprimes(s, 3 * 7) - _walprimes(s, 5 * 7)
        + _walprimes(s, 2 * 3 * 5) + _walprimes(s, 3 * 5 * 7)
        - _walprimes(s, 2 * 3 * 5 * 7);
}

int _walprimes(const string& s, int p) {
  int n = s.size(), remain[n][p];
  memset(remain, 0, sizeof(remain));

  for (int i = n - 1; i >= 0; i--) {
    int first = s[i] - '0';
    for (int k = i + 1; k < n; k++) {
      for (int j = 0; j < p; j++) {
        remain[i]
      }
      first = 10 * first + s[k] - '0';
    }
    remain[i][first % p] += 1;
  }
}

int main(int argc, const char *argv[])
{
  string s = "011";
  cout << s << " : " << walprimes(s) << endl;

  s = "12345";
  cout << s << " : " << walprimes(s) << endl;
  return 0;
}
