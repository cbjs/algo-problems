int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    if (!n) return -1;
    int sum[n];
    for (int i = 0; i < n; ++i) sum[i] = triangle[n - 1][i];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < i + 1; j++) {
            sum[j] = triangle[i][j] + (sum[j] < sum[j + 1] ? sum[j] : sum[j + 1]);
        }
    }
    return sum[0];
}
