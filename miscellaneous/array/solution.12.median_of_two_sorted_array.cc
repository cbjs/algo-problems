double findMedianSortedArraysOne(int A[], int m, int B[], int n) {
   if ((m + n) % 2 == 0) {
       int k = (m + n) / 2;
       return (findKth(A, m, B, n, k) + findKth(A, m, B, n, k + 1)) / 2.0;
   } else {
       int k = 1 + (m + n) / 2;
       return findKth(A, m, B, n, k);
   }
}

double findKth(int A[], int m, int B[], int n, int k) {
    if (m == 0) return B[k - 1];
    if (n == 0) return A[k - 1];

    int am = m / 2, bn = n / 2, p = am + bn + 1;
    if (A[am] >= B[bn]) {
        if (k <= p) {
            return findKth(A, am, B, n, k);
        } else {
            return findKth(A, m, B + bn + 1, n - bn - 1, k - bn - 1);
        }
    } else {
        if (k <= p) {
            return findKth(A, m, B, bn, k);
        } else {
            return findKth(A + am + 1, m - am - 1, B, n, k - am - 1);
        }
    }
}

double findMedianSortedArraysTwo(int A[], int m, int B[], int n) {
   return _findMedianSortedArrays(A, m, 0, m - 1, B, n);
}

double _findMedianSortedArrays(int A[], int m, int l, int r, int B[], int n) {
    if (l > r) return _findMedianSortedArrays(B, n, 0, n - 1, A, m);
    int i = (l + r) / 2;
    int j = (m + n) / 2 - i;
    if ((j == 0 || A[i] >= B[j - 1]) && (j == n || A[i] <= B[j])) {
        // found
        if ((m + n) % 2) {
            return A[i];
        } else {
            if (i > 0 && j > 0) return (max(A[i - 1], B[j - 1]) + A[i]) / 2.0;
            if (i > 0) return (A[i - 1] + A[i]) / 2.0;
            if (j > 0) return (B[j - 1] + A[i]) / 2.0;
        }
    }

    if ((j == 0 || A[i] >= B[j - 1]) && j != n && A[i] > B[j]) {
        return _findMedianSortedArrays(A, m, l, i - 1, B, n);
    } else {
        return _findMedianSortedArrays(A, m, i + 1, r, B, n);
    }
}
