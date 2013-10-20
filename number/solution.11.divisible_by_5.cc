#include <iostream>

using namespace std;

bool isDivisibleByFive(int n) {
    if (n < 0) n = abs(n);

    int i = 0;
    while (n >= 5) {
        int m = n - (5 << i);
        if (m < 0) {
            i = 0;
        } else {
            n = m;
            i++;
        }
    }

    return n == 0;
}

int main(int argc, char *argv[])
{
    for (int i = -100; i < 100; i++) {
        cout << i << "isDivisibleByFive:" << isDivisibleByFive(i) << endl;
    }
    return 0;
}
