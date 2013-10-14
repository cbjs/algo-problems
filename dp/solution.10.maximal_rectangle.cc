int maximalRectangle(vector<vector<char> > &matrix) {
    int m = matrix.size();
    if (!m) return 0;
    int n = matrix[0].size();
    if (!n) return 0;

    int h[n], l[n], r[n];
    for (int i = 0; i < n; ++i) {
        h[i] = l[i] = r[i] = 0;
    }

    int max_area = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                h[j] += 1;
            } else {
                h[j] = 0;
            }
        }

        for (int j = 0; j < n; ++j) {
            l[j] = j;
            while (l[j] >= 1 && h[l[j] - 1] >= h[j])
                l[j] = l[j] - 1;
        }

        for (int j = n - 1; j >= 0; --j) {
            r[j] = j;
            while (r[j] < n - 1 && h[r[j] + 1] >= h[j])
                r[j] = r[j] + 1;
        }

        for (int j = 0; j < n; ++j) {
            int tmp_area = h[j] * (r[j] - l[j] + 1);
            if (tmp_area > max_area) max_area = tmp_area;
        }
    }
    return max_area;
}
