#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> recursively(int n) {
  if (n == 0) return {0};
  vector<int> codes = {0, 1};

  for (int i = 1; i < n; i++) {
    int m = codes.size();
    for (int j = m - 1; j >= 0; j--) {
      codes.push_back((1 << i) | codes[j]);
    }
  }
  return codes;
}

vector<int> directly(int n) {
  int m = 1 << n;
  vector<int> codes;
  for (int i = 0; i < m; i++) {
    codes.push_back((i >> 1) ^ i);
  }
  return codes;
}

int main(int argc, char *argv[])
{
  for (int i = 0; i < 10; i++) {
    cout << i << ":" << endl;
    vector<int> c1 = recursively(i);
    for_each(c1.begin(), c1.end(), [](int v) { cout << v << ",\t";});
    cout << endl;
    vector<int> c2 = directly(i);
    for_each(c2.begin(), c2.end(), [](int v) { cout << v << ",\t";});
    cout << endl << endl;
  }
  return 0;
}
