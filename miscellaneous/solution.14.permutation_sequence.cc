#include <string>
#include <iostream>

using namespace std;

string getPermutation(int n, int k) {
    char chars[n];
    int t = 1, nums[n];
    for (int i = 0; i < n; ++i) {
        chars[i] = '0' + i + 1;
        t *= (i + 1);
        nums[n - i - 1] = t;
    }

    k -= 1;
    for (int i = 0; i < n - 1; ++i) {
        int a = k / nums[i + 1] + i;
        k %= nums[i + 1];
        if (a) {
            while (a != i) {
                char t = chars[a];
                chars[a] = chars[a - 1];
                chars[a - 1] = t;
                a -= 1;
            }
        }
    }
    return string(chars, chars + n);
}

int main(int argc, char *argv[])
{
    cout << getPermutation(8, 31492) << endl;
    return 0;
}
