bool wordBreak(string s, unordered_set<string> &dict) {
    int n = s.size();
    bool is_valid[n + 1];
    is_valid[n] = true;
    for (int i = n - 1; i >= 0; --i) {
        is_valid[i] = false;
        for (int j = i + 1; j <= n; ++j) {
            if (is_valid[j] && dict.find(s.substr(i, j - i)) != dict.end()) {
                is_valid[i] = true;
                break;
            }
        }
    }
    return is_valid[0];
}
