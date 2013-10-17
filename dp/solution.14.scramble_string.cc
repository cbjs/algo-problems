class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;

        int n = s1.size();
        bool is_scramble[n][n][n + 1];

        for (int k = 1; k <=n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (k > n - max(i, j)) break;

                    is_scramble[i][j][k] = false;

                    if (k == 1) {
                        is_scramble[i][j][k] = (s1[i] == s2[j]);
                        continue;
                    }

                    for (int l = 1; l < k; ++l) {
                        if ((is_scramble[i][j][l] && is_scramble[i + l][j + l][k - l])
                            || (is_scramble[i][j + k - l][l] && is_scramble[i + l][j][k - l])) {
                                is_scramble[i][j][k] = true;
                                break;
                            }
                    }

                }
            }
        }

        return is_scramble[0][0][n];
    }
};
