#include <iostream>

using namespace std;

bool is_walprimes(int num) {
  return num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0;
}

void _walprimes(const string& s, int sum, int i, long& ans) {
  if (i == s.size()) {
    if (is_walprimes(sum)) ans += 1;
    return;
  }

  int first = 0;
  for (int k = i; k < s.size(); k++) {
    first = first * 10 + s[k] - '0';

    if (i == 0) {
      _walprimes(s, first, k + 1, ans);
    } else {
      _walprimes(s, sum + first, k + 1, ans);
      _walprimes(s, sum - first, k + 1, ans);
    }
  }
}

int walprimes(const string& s) {
  long ans = 0;
  _walprimes(s, 0, 0, ans);
  return ans;
}

int main(int argc, const char *argv[])
{
  string s = "011";
  cout << s << " : " << walprimes(s) << endl;

  s = "12345";
  cout << s << " : " << walprimes(s) << endl;

  s = "1234567";
  cout << s << " : " << walprimes(s) << endl;
  return 0;
}
