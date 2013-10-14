#include <iostream>

 bool isPalindrome(int x) {
    if (x < 0) return false;
    int y = x, r_x = 0;
    while (y > 0) {
        r_x = r_x * 10 + y % 10;
        y /= 10;
    }
    return x == r_x;
}

int main(int argc, char *argv[])
{
    std::cout << isPalindrome(123321);
    return 0;
}
