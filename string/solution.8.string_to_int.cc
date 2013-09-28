#include <iostream>

using namespace std;

long string_to_long(const char* s) {
    long ret = 0, flag = 1;
    if (s && *s++ == '-') flag = -1;
    while(*s++) ret = ret * 10 + *(s - 1) - '0';
    return ret * flag;
}

int main(int argc, char *argv[])
{
    std::cout << string_to_long("123456") << std::endl;
    std::cout << string_to_long("0") << std::endl;
    std::cout << string_to_long("-124") << std::endl;
    return 0;
}
