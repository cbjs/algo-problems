class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n) {
            // non-positive number or positive in the right place
            if (A[i] <= 0 || A[i] - 1 == i) {
                i++;
                continue;
            }

            // swap to its right place
            int j = A[i] - 1;
            if (j < n && A[j] != j + 1) {
                int t = A[j];
                A[j] = A[i];
                A[i] = t;
                continue;
            }

            // no place to go
            A[i] = -1;
            i++;
        }

        for (int i = 0; i < n; i++) {
            if (A[i] <= 0) return i + 1;
        }
        return n + 1;
    }
};
