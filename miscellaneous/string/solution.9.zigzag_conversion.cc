class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string result;
        for (int i = 0; i < nRows; ++i) {
            int j = i; bool down = (i < nRows - 1);
            while (j < s.size()) {
                result.push_back(s[j]);
                if (down) {
                    j += (nRows - i - 1) * 2;
                } else {
                    j += i * 2;
                }
                if (i > 0 && i < nRows - 1) down = !down;
            }
        }
        return result;
    }
};
