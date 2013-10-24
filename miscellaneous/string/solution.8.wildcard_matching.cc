class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s && !p) return true;
        if (!s || !p) return false;

        const char *ss = nullptr, *sp = nullptr;
        while (*s) {
            if (*p == '?' || *s == *p) {
                s++;
                p++;
                continue;
            } else if (*p == '*') {
                while (*p == '*') p++;
                if (!*p) return true;

                ss = s;
                sp = p;
            } else if (sp) {
                s = ++ss;
                p = sp;
            } else return false;
        }

        while (*p) {
            if (*p++ != '*') return false;
        }
        return true;
    }
};
