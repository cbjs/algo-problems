#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <tuple>
#include <functional>

using namespace std;

typedef tuple<int, int, int> ThreeTuple;
typedef priority_queue<ThreeTuple, vector<ThreeTuple>, greater<ThreeTuple> > MinHeap;

pair<int, int> smallestRange(const vector<vector<int> >& lists) {
  pair<int, int> range;
  int max_value = lists[0][0];
  MinHeap min_heap;
  for (int i = 0; i < lists.size(); i++) {
    min_heap.push(make_tuple(lists[i][0], i, 0));
    if (max_value < lists[i][0]) max_value = lists[i][0];
  }
  range.first = get<0>(min_heap.top());
  range.second = max_value;

  while (true) {
    ThreeTuple tt = min_heap.top();
    min_heap.pop();

    int i = get<1>(tt), j = get<2>(tt);
    if (lists[i].size() - 1 == get<2>(tt)) break;

    min_heap.push(make_tuple(lists[i][j + 1], i, j + 1));
    if (max_value < lists[i][j + 1]) max_value = lists[i][j + 1];

    // update smallest range
    if (max_value - get<0>(min_heap.top()) < range.second - range.first) {
      range.first = get<0>(min_heap.top());
      range.second = max_value;
    }
  }
  return range;
}

int main(int argc, char *argv[])
{
  vector<vector<int> > lists = {
    {4, 10, 15, 24, 26},
    {0, 9, 12, 20},
    {5, 18, 22, 30}
  };
  pair<int, int> range = smallestRange(lists);
  cout << "smallest range:" << "[" << range.first
       << " " << range.second << "]" << endl;
  return 0;
}
