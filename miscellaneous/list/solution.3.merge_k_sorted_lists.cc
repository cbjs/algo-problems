#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0) : val(x), next(NULL) {}
  void print() {
      ListNode* node = this;
      while (node) {
          std::cout << node->val << ",";
          node = node->next;
      }
      std::cout << std::endl;
  }
};

class node_list_comparision {
  public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    // Note: The Solution object is instantiated only once and is reused by
    // each test case.
    std::priority_queue<ListNode *, std::vector<ListNode*>, node_list_comparision> min_heap;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) min_heap.push(lists[i]);
    }

    ListNode* result = NULL, *pre = NULL;
    while (!min_heap.empty()) {
        ListNode* min_node = min_heap.top();
        min_heap.pop();

        if (pre) {
            pre->next = min_node;
            pre = min_node;
        } else {
            result = pre = min_node;
        }

        if (pre->next) {
            min_heap.push(pre->next);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{

    ListNode list1[10];
    for (int i = 0; i < 10; i++) {
        list1[i].val = i + 2;
        if (i > 0) {
            list1[i - 1].next = &list1[i];
        }
    }

    ListNode list2[10];
    for (int i = 0; i < 10; i++) {
        list2[i].val = i + 3;
        if (i > 0) {
            list2[i - 1].next = &list2[i];
        }
    }

    ListNode list3[10];
    for (int i = 0; i < 10; i++) {
        list3[i].val = i + 4;
        if (i > 0) {
            list3[i - 1].next = &list3[i];
        }
    }

    std::vector<ListNode*> lists;
    lists.push_back(&list1[0]);
    lists.push_back(&list2[0]);
    lists.push_back(&list3[0]);

    ListNode* result = mergeKLists(lists);
    result->print();
    return 0;
}
