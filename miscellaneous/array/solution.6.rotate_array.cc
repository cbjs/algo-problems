#include <iostream>

using namespace std;

void rotate(int* arr, int n, int m) {
    m = m % n;
    if (m == 0) return;

    int p = 0, q = m, middle = m;
    while(q != n) {
        // swap arr[p] and arr[q]
        int tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;

        p++;
        q++;

        if (p == middle) {
            middle = q;
        } else if (q == n) {
            q = middle;
        }
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    std::cout << "rotate before:";
    print(arr, n);

    int m = 3;
    rotate(arr, n, m);

    std::cout << "rotate after:";
    print(arr, n);
}
