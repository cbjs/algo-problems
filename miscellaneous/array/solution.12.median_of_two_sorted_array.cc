double findMedianSortedArraysOne(int A[], int m, int B[], int n) {
   if ((m + n) % 2 == 0) {
       int k = (m + n) / 2;
       return (findKth(A, m, B, n, k) + findKth(A, m, B, n, k + 1)) / 2.0;
   } else {
       int k = 1 + (m + n) / 2;
       return findKth(A, m, B, n, k);
   }
}

// 假设数组c是a和b合并排序后的数组
// 比较中位数，数组下标从0开始, a有la, b有lb个元素
//  若a[ma] >= b[mb], 在数组c中，b[mb]之前(包括b[mb])的mb + 1个数一定出现在a[ma]之前
//                      则a[ma]之前至少有ma + mb + 1个数
//                    在数组c中, a[ma]之后(包括a[ma])的la - ma个元素一定出现在b[mb]之后
//                      则b[mb]之后至少有(la + lb) - (ma + mb + 1)个数
//    若k <= ma + mb + 1, 则只需在a[0, ma)和b[0, end)中找第K大的数
//    若k > ma + mb + 1, 则在a[0, end]和b[mb + 1, end)中找第K - mb - 1大的数
//  若a[ma] < b[mb]同理分析
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
