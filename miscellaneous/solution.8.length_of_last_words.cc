#include <iostream>

// p指向最后一个单词的最后一个字母
// q指向最后一个单词第一个字母之前一个位置
int lengthOfLastWord(const char *s) {
    if (!s || !*s) return 0;
    const char* p = s, *q = s;
    while(*p) p++;
    p -= 1;
    while (p >= s && *p == ' ') p--;
    q = p;
    while (q >= s && *q != ' ') q--;
    return p - q;
}

int main(int argc, char *argv[])
{
    const char* s = "abc def g ";
    std::cout << lengthOfLastWord(s);
    return 0;
}
