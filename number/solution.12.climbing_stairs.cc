class Solution {
public:
    int climbStairs(int n) {
        return fibonacci(n + 1);
    }

    int fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int k = n / 2;
        int a = fibonacci(k);
        int b = fibonacci(k + 1);

        if (n % 2 == 1) {
            return a * a + b * b;
        } else {
            return a * (2 * b - a);
        }
    }
};
