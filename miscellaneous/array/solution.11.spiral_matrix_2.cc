class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty()) return vector<int>();
        int m = matrix.size(), n = matrix[0].size();
        // d = 0, 1, 2, 3 -> right, down, left, up
        // l, levels
        int d = 0, l = 0, i = 0, j = -1, k = 0;
        vector<int> result;
        while (k < m * n) {
            if (d == 0 && j + 1 < n - l) {
                j += 1;
            } else if (d == 1 && i + 1 < m - l) {
                i += 1;
            } else if (d == 2 && j - 1 >= l) {
                j -= 1;
            } else if (d == 3 && i - 1 >= l) {
                i -= 1;
            } else {
                d = (d + 1) % 4;
                if (d == 3) l += 1;
                continue;
            }

            result.push_back(matrix[i][j]);
            k += 1;
        }
        return result;
    }
};
