#include <iostream>
#include <string>

using namespace std;

int minCut(string s) {
    int n = s.size();
    if (n == 0 || n == 1) return 0;

    int min_cuts[n + 1];
    bool is_palindrome[n][n];

    for (int i = 0; i < n + 1; i++)
        min_cuts[i] = n - i;
    for (int i = 0; i < n; i++) {
        is_palindrome[i][i] = true;
        for (int j = i + 1; j < n; j++)
            is_palindrome[i][j] = false;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 2 || is_palindrome[i + 1][j - 1])) {
                is_palindrome[i][j] = true;
                if (min_cuts[i] > (1 + min_cuts[j + 1])) {
                    min_cuts[i] = 1 + min_cuts[j + 1];
                }
            }
        }
    }
    return min_cuts[0] - 1;
}

int main(int argc, char *argv[])
{
    string s = "aaxxxbbzzz";
    cout << "minCut of " << s << ": " << minCut(s);
    return 0;
}
