#include <iostream>

int numDecodings(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    int num_decodings[n + 1];

    num_decodings[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            num_decodings[i] = 0;
            continue;
        }

        num_decodings[i] = num_decodings[i + 1];

        if (i < n - 1) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                num_decodings[i] += num_decodings[i + 2];
        }
    }

    return num_decodings[0];
}
