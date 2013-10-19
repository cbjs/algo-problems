class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> s;   // length of sequence start with num[i]
        unordered_map<int, int> e;   // length of sequence end with num[i]
        int max = 0;
        for (int i = 0; i < num.size(); ++i) {
            // skip duplicated ones
            if (s[num[i]]) continue;

            // compute sequence length starting and end with num[i]
            s[num[i]] = s[num[i] + 1] + 1;
            e[num[i]] = e[num[i] - 1] + 1;

            // keep track of max length
            if (s[num[i]] + e[num[i]] - 1 > max) max = s[num[i]] + e[num[i]] - 1;

            // update length of two ends
            e[num[i] + s[num[i]] - 1] = s[num[i]] + e[num[i]] - 1;
            s[num[i] - e[num[i]] + 1] = s[num[i]] + e[num[i]] - 1;
        }
        return max;
    }
};
