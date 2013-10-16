#include <string>
#include <iostream>

using namespace std;
int numDistinct(string S, string T) {
    // num_distinct[i][j] = num_distinct[i][j - 1], if S[i - 1] != T[j - 1]
    // num_distinct[i][j] = num_distinct[i - 1][j - 1] + num_distinct[i][j - 1], otherwise
    int num_distinct[T.size() + 1][S.size() + 1];
    for (int i = 0; i <= T.size(); ++i) num_distinct[i][0] = 0;
    for (int i = 0; i <= S.size(); ++i) num_distinct[0][i] = 1;

    for (int i = 1; i <= T.size(); ++i) {
        for (int j = 1; j <= S.size(); ++j) {
            if (T[i - 1] == S[j - 1]) {
                num_distinct[i][j] = num_distinct[i - 1][j - 1] + num_distinct[i][j - 1];
            } else {
                num_distinct[i][j] = num_distinct[i][j - 1];
            }
        }
    }

    return num_distinct[T.size()][S.size()];
}

int main(int argc, char *argv[])
{
    string T = "a";
    string S = "b";
    cout << S << ", " << T << " : " << numDistinct(S, T) << endl;
    return 0;
}
