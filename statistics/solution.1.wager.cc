#include <iostream>

using namespace std;

int min_wager(int my_score, int scores[], int wagers[], int n) {
  int min_wager = 0, max_prob = 0;
  for (int w = 0; w <= my_score; w++) {
    int cur_prob = 0;

    for (int r = 0; r < (2 << n); r++) {
      int my_last_score = my_score + ((r & 0x08) ? w : -w);

      int i = 0;
      while (i < n - 1) {
        int other_score = scores[i] + wagers[i] * (((r >> 1) & 0x1) ? 1 : -1);
        if (my_last_score <= other_score) break;
        i += 1;
      }

      if (i == 3) cur_prob += 1;
    }

    if (cur_prob > max_prob) {
      max_prob = cur_prob;
      min_wager = w;
    }
  }

  // cout << "max_prob:" << max_prob << endl;
  return min_wager;
}

int main(int argc, const char *argv[])
{
  int scores[] = {11, 9, 10};
  int wagers[] = {5, 3, 4};
  for (int i = 0; i < 17; i++) {
    cout << "my_score:" << i << endl;
    cout << "my min_wager:" << min_wager(i, scores, wagers, 4) << endl;
    cout << endl;
  }
  return 0;
}
