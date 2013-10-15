#include <iostream>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

string minWindow(string S, string T) {
    unordered_map<char, int> dict;
    for (int i = 0; i < T.size(); ++i) {
        dict[T[i]] += 1;
    }
    int l = T.size();
    int p = -1, q = 0, min_len = S.size(), min_p = -1;
    while (q < S.size()) {
        char c = S[q];
        if (dict.find(c) == dict.end()) { q++; continue; }

        // first found
        if (p == -1) p = q;

        dict[c] -= 1;
        if (dict[c] >= 0) l--;

        // found a window
        while (l == 0) {
            // update min len
            if (min_len >= (q - p + 1)) {
                min_len = q - p + 1;
                min_p = p;
            }
            // move p forward
            dict[S[p]] += 1;
            if (dict[S[p]] > 0) l += 1;
            while (p < q && dict.find(S[++p]) == dict.end());
        }

        q++;
    }
    if (min_p >= 0) return S.substr(min_p, min_len);
    else return "";
}

int main(int argc, char *argv[])
{
    string S = "axxcxxxaxcdxxxd";
    string T = "acd";
    cout << "minWindow of (" << S << "," << T << ") = "
         << minWindow(S, T) << endl;
    return 0;
}
