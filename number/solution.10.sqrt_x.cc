#include <iostream>

using namespace std;

int sqrt(int x) {
    int l = 0, r = x, m = x / 2, mm = 0;

    while (true) {
        mm = m * m;
        if (mm > x) r = m;
        else if (m * m == x) return m;
        else l = m;

        m = (l + r) / 2;
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; i++) {
        int x = (i + 12) * (i + 12);
        std::cout << "sqrt(" << x << ") = " << sqrt(x) << std::endl;
    }
    return 0;
}
