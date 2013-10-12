#include <iostream>
#include <string>

using namespace std;

int _isInterleave(string s1, int i1, string s2, int i2, string s3, int** record) {
    if (i1 == s1.size()) {
        if (s2.substr(i2) == s3.substr(i1 + i2))
            return 1;
        else
            return -1;
    }
    if (i2 == s2.size()) {
        if (s1.substr(i1) == s3.substr(i1 + i2))
            return 1;
        else
            return -1;
    }

    if (record[i1][i2]) return record[i1][i2];

    record[i1][i2] = -1;
    for (int i = i1 + i2; i < s3.size(); i++) {
        if (s3[i] == s1[i1]) {
            int l = i - i1 - i2;
            if (s2.size() - i2 >= l && s2.substr(i2, l) == s3.substr(i1 + i2, l)) {
                if (_isInterleave(s1, i1 + 1, s2, i2 + l, s3, record) == 1) {
                    record[i1][i2] = 1;
                    break;
                }
            } else {
                record[i1][i2] = -1;
                break;
            }
        }
    }
    return record[i1][i2];
}

bool isInterleaveRecursive(string s1, string s2, string s3) {
    if (s1.size() > s2.size())
        return isInterleave(s2, s1, s3);

    if (s1.empty()) return s2 == s3;

    for (int i = 0; i < s3.size(); i++) {
        if (s3[i] == s1[0]) {
            if (s2.size() > i && s2.substr(0, i) == s3.substr(0, i)) {
                if(isInterleave(s1.substr(1), s2.substr(i), s3.substr(i + 1)))
                    return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
    int** record = new int*[s1.size()];
    for (int i = 0; i < s1.size(); i++) {
        record[i] = new int[s2.size()];
        for (int j = 0; j < s2.size(); j++) {
            record[i][j] = 0;
        }
    }

    int result = _isInterleave(s1, 0, s2, 0, s3, record);

    for (int i = 0; i < s1.size(); i++) {
        delete[] record[i];
    }
    delete[] record;

    return result == 1;
}

int main(int argc, char *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    std::cout << s3 << ":" << isInterleave(s1, s2, s3) << std::endl;
    std::cout << s4 << ":" << isInterleave(s1, s2, s4) << std::endl;
    return 0;
}
