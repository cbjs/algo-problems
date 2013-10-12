#include <iostream>

using namespace std;

void cycle_shift(int* arr, int n, int m) {
    m = m % n;
    if (m == 0) return;

    int p = 0, q = m;
    while (q != n) {
        // swap arr[p] and arr[q]
        int tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;

        p++;
        q++;

        if (p == m) {
            m = q;
        } else if (q == n) {
            q = m;
        }
    }
}


// solution of nlog(n)
void log_interleave(int* arr, int n) {
    int m = n / 4;
    if (m == 0) return;

    cycle_shift(arr + m, n / 2, n / 2 - m);

    log_interleave(arr, 2 * m);
    log_interleave(arr + 2 * m, n - 2 * m);
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, -1, -2, -3, -4, -5, -6};
    int n = sizeof(arr) / sizeof(int);

    std::cout << "interleave before:";
    print(arr, n);

    int m = 3;
    log_interleave(arr, n);

    std::cout << "interleave after:";
    print(arr, n);
}
