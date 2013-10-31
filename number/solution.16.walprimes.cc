#include <iostream>
#include <string>

using namespace std;

int F(const string& s, int p) {
  int n = s.size(), remain[n][p];
  memset(remain, 0, sizeof(remain));

  for (int i = n - 1; i >= 0; i--) {
    int first = s[i] - '0';

    for (int k = i + 1; k < n; k++) {
      for (int j = 0; j < p; j++) {
        // -1 % 2 = -1 replaced with (2 + -1 % 2) % 2 = 1
        remain[i][j] += remain[k][(p + (j - first) % p) % p];
        remain[i][j] += remain[k][(p + (first - j) % p) % p];
      }

      first = 10 * first + s[k] - '0';
    }

    remain[i][first % p] += 1;
  }

  return remain[0][0];
}

int walprimes(const string& s) {
  return F(s, 2) + F(s, 3) + F(s, 5) + F(s, 7)
       - F(s, 2 * 3) - F(s, 2 * 5) - F(s, 2 * 7) - F(s, 3 * 5) - F(s, 3 * 7) - F(s, 5 * 7)
       + F(s, 3 * 5 * 7) + F(s, 2 * 5 * 7) + F(s, 2 * 3 * 7) + F(s, 2 * 3 * 5)
       - F(s, 2 * 3 * 5 * 7);
}

int main(int argc, const char *argv[])
{
  string s = "011";
  cout << s << " : " << walprimes(s) << endl;

  s = "12345";
  cout << s << " : " << walprimes(s) << endl;
  return 0;
}
