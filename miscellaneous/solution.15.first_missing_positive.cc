class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int nnp = 0; // num of non-positive numbers
        int i = 0;
        while (i < n) {
            // reach the end
            if (nnp + i == n) break;

            // non-positive number, put in the end
            if (A[i] <= 0) {
                A[i] = A[n - 1 - nnp];
                A[n - 1 - nnp] = -1;
                ++nnp;
                continue;
            }

            // positive number
            // check if it's in the right place
            int j = A[i] - 1;
            if (j == i) {
                i++;
                continue;
            }

            // swap it to its right place,
            if (j < n - nnp && A[j] != j + 1) {
                int t = A[j];
                A[j] = A[i];
                A[i] = t;
                continue;
            }

            // no place to go, place a flag here
            A[i] = -1;
            i++;
        }

        for (int i = 0; i < n; i++) {
            if (A[i] <= 0) return i + 1;
        }
        return n + 1;
    }
};
