#include <string.h>

#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

string smallestContainer(const vector<string>& strs) {
  string result;
  priority_queue<char, vector<char>, greater<char>> min_heap;
  int n = strs.size(), ind[n];
  memset(ind, 0, sizeof(ind));

  for (int i = 0; i < n; i++) {
    if (!strs[i].empty()) min_heap.push(strs[i][0]);
  }

  while (!min_heap.empty()) {
    char mc = min_heap.top();
    while (!min_heap.empty() && mc == min_heap.top()) min_heap.pop();

    result.push_back(mc);
    for (int i = 0; i < n; i++) {
      if (ind[i] == strs[i].size()) continue;

      if (mc == strs[i][ind[i]]) {
        ind[i] += 1;
        if (ind[i] < strs[i].size()) min_heap.push(strs[i][ind[i]]);
      }
    }
  }

  return result;
}

int main(int argc, char *argv[])
{
  vector<string> strs = {"abc", "zbcd", "def", "dgh"};
  cout << smallestContainer(strs) << endl;
  return 0;
}
