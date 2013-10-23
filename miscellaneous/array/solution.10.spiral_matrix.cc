class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int direction = 0; // 0, 1, 2, 3
        vector<vector<int> > result;
        for (int i = 0; i < n; i++) {
            result.push_back(vector<int>(n, 0));
        }

        int i = 0, j = -1, k = 1;
        while (k <= n * n) {
            if (direction == 0 && j + 1 < n && result[i][j + 1] == 0) {
                j += 1;
            } else if (direction == 1 &&i + 1 < n && result[i + 1][j] == 0) {
                i += 1;
            } else if (direction == 2 && j - 1 >=0 && result[i][j - 1] == 0) {
                j -= 1;
            } else if (direction == 3 && i - 1 >= 0 && result[i - 1][j] == 0) {
                i -= 1;
            } else {
                direction = (direction + 1) % 4;
                continue;
            }

            result[i][j] = k;
            k += 1;
        }

        return result;
    }
};
