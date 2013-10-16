// 同minimum_window_substring
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dict;
        int p = -1, q = 0, max_len = 0;
        while (q < s.size()) {
            char c = s[q];
            if (dict.find(c) != dict.end()) {
                while (s[++p] != c) dict.erase(s[p]);
            }
            dict.insert(c);
            if (q - p > max_len) max_len = q - p;
            q++;
        }
        return max_len;
    }
};
