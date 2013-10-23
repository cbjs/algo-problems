class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int n = S.size(), m = L.size(), k = L[0].size();
        map<string, int> words, count;
        for (int i = 0; i < L.size(); ++i)
            words[L[i]] += 1;
        vector<int> result;

        for (int i = 0; i < k; ++i) {
            int p = i, q = i, found = 0;
            count.clear();
            while (p + m * k <= n && q + k <= n) {
                string cur = S.substr(q, k);
                if (words.find(cur) == words.end()) {
                    count.clear();
                    q += k;
                    p = q;
                    found = 0;
                    continue;
                }

                if (count[cur] < words[cur]) {
                    found += 1;
                    count[cur] += 1;
                    if (found == m) {
                        result.push_back(p);
                        count[S.substr(p, k)] -= 1;
                        found -= 1;
                        p += k;
                    }
                } else {
                    // skip all other words
                    while (S.substr(p, k) != cur) {
                        count[S.substr(p, k)] -= 1;
                        found -= 1;
                        p += k;
                    }
                    // skip string 'cur'
                    p += k;
                }
                q += k;
            }
        }
        return result;
    }
};
