// one pass, O(n) time, O(1) space
int longestValidParentheses(string s) {
    stack<int> lefts;
    int last = -1, max_len = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            lefts.push(i);
        } else {
            if (lefts.empty()) {
                last = i;
            } else {
                lefts.pop();
                if (lefts.empty()) {
                    max_len = max(max_len, i - last);
                } else {
                    max_len = max(max_len, i - lefts.top());
                }
            }
        }
    }
    return max_len;
}


// two passes, O(n) time, O(1) space
int longestValidParentheses(string s) {
        int max_len = 0, l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') l++;
            else {
                if (l > r) {
                    r++;
                    if (l == r) {
                        max_len = max(max_len, 2 * l);
                    }
                } else {
                    l = 0; r = 0;
                }
            }
        }

        l = 0; r = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') r++;
            else {
                if (r > l) {
                    l++;
                    if (l == r) {
                        max_len = max(max_len, 2 * r);
                    }
                } else {
                    l = 0; r = 0;
                }
            }
        }
        return max_len;
    }
