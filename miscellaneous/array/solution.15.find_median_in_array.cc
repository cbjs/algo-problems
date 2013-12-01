#include <queue>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

double findMedian(const vector<int>& arr) {
  priority_queue<int, vector<int>, greater<int> > min_heap;
  priority_queue<int> max_heap;

  min_heap.push(arr[0]);
  double median = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > median) {
      min_heap.push(arr[i]);
      if (min_heap.size() - max_heap.size() == 2) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
    } else {
      max_heap.push(arr[i]);
      if (max_heap.size() > min_heap.size()) {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
    }

    if (i % 2) {
      median = (min_heap.top() + max_heap.top()) / 2.0;
    } else {
      median = min_heap.top() * 1.0;
    }
  }

  return median;
}

int main(int argc, char *argv[])
{
  vector<int> arr = {5, 6, 1, 2, 12, 4, 11, 10};
  cout << "median: " << findMedian(arr) << endl;
  return 0;
}
