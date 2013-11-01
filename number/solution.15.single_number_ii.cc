class Solution {
public:
    int singleNumberDirect(int A[], int n) {
      int result = 0, m = sizeof(int) * 8;
      for (int i = 0; i < m; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
          cur += (A[j] >> i) & 0x01;
        }
        result |= (cur % 3) << i;
      }
      return result;
    }

    int singleNumber(int A[], int n) {
        int one = 0, two = 0;
        for (int i = 0; i < n; i++) {
            int one_ = (one ^ A[i]) & ~two;
            int two_ = A[i] & one | ~A[i] & two;
            one = one_;
            two = two_;
        }

        return one;
    }
};
