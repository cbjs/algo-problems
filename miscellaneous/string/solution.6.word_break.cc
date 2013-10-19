#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<vector<string> > breaks;
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        vector<string> sentence;
        for (int j = i + 1; j <= n; ++j) {
            if (dict.find(s.substr(i, j - i)) != dict.end()) {
                if (j == n) {
                    sentence.push_back(s.substr(i));
                } else if (!breaks[n - 1 - j].empty()) {
                    for (string t : breaks[n - 1 - j]) {
                        sentence.push_back(s.substr(i, j - i) + " " + t);
                    }
                }
            }
        }
        breaks.push_back(sentence);
    }
    return breaks.back();
}

int main(int argc, char *argv[])
{
    string s = "catsanddog";
    string str[] = {"cat","cats","and","sand","dog"};
    unordered_set<string> dict(str, str + 5);
    vector<string> result = wordBreak(s, dict);
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}
