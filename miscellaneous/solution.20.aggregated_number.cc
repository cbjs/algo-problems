#include <string>
#include <iostream>

using namespace std;

bool isAggregatedNumber(string number) {
  int n = number.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
    }
  }
}

int main(int argc, const char *argv[])
{
  cout << "112358:" << isAggregatedNumber("112358") << endl;
  cout << "122436:" << isAggregatedNumber("122436") << endl;
  cout << "1299111210:" << isAggregatedNumber("1299111210") << endl;
  cout << "112112224:" << isAggregatedNumber("112112224") << endl;
  cout << "123456:" << isAggregatedNumber("123456") << endl;
  return 0;
}
