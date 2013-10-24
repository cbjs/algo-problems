class Solution {
public:
    int trap(int A[], int n) {
        int l[n];
        for (int i = 0; i < n; ++i) {
            l[i] = i;
            if (i > 0 && A[i] < A[l[i - 1]]) l[i] = l[i - 1];
        }

        int b = n - 1, area = 0;
        for (int i = n - 2; i > 0; --i) {
            int a = l[i - 1];
            int h = min(A[a], A[b]);
            if (h > A[i]) area += (h - A[i]);

            if (A[b] < A[i]) {
                b = i;
            }
        }

        return area;
    }
};
