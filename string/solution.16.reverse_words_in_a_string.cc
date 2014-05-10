class Solution {
public:
    void reverseString(string& s, int begin, int end) {
        if (begin >= end || begin >= s.size()) return;

        for (int i = begin, j = end; i < j; i++, j--)  {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }

    void reverseWords(string &s) {
        int begin = 0, end = 0, p = -1;


        for (int i = 0; i < s.size(); ++i) {

            if (s[i] != ' ') {

                if (p != -1 && i != 0 && s[i - 1] == ' ') {
                    s[++p] = ' ';

                    end = p - 1;
                    reverseString(s, begin, end);
                    begin = p + 1;
                }

                s[++p] = s[i];
            }
        }

        reverseString(s, begin, p);
        reverseString(s, 0, p);
        s.resize(p + 1);
    }
};
