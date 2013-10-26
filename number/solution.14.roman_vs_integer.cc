string intToRoman(int num) {
    int rnums[] = {1000, 500, 100, 50, 10, 5, 1};
    char rchar[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int i = 0, n = 7;
    string result("");
    while (num > 0) {
        if (num >= rnums[i]) {
            num -= rnums[i];
            result += rchar[i];
        } else {
            int j = i + 2 - i % 2;
            if (num < rnums[i] && num >= (rnums[i] - rnums[j])) {
                num -= (rnums[i] - rnums[j]);
                result += rchar[j];
                result += rchar[i];
            }
            i++;
        }
    }
    return result;
}

int romanToInt(string s) {
    int rnums[] = {1000, 500, 100, 50, 10, 5, 1};
    char rchar[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int i = 0, j = 0, result = 0;
    while (i < s.size()) {
        while (rchar[j] != s[i]) j++;
        if (j % 2 || j == 0 || i == s.size() - 1 || (s[i + 1] != rchar[j - 1] && s[i + 1] != rchar[j - 2])) {
            result += rnums[j];
            i += 1;
        } else {
            result -= rnums[j];
            if (s[i + 1] == rchar[j - 1]) result += rnums[j - 1];
            else result += rnums[j - 2];
            i += 2;
        }
    }
    return result;
}
