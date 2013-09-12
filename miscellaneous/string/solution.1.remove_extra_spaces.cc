#include <iostream>

using namespace std;

char* remove_extra_spaces(char* str) {
  char* i = str;
  char* j = str;

  // strip spaces at the begining
  while (*j && *j == ' ') ++j;

  // remove spaces in the middle
  while(*j) {
    if ((*j != ' ') || (*(i-1) != ' ')) {
      *i++ = *j;
    }
    j++;
  }

  // strip spaces at the end
  if (*(i-1) == ' ') *(i-1) = '\0';
  else *i = '\0';
  return str;
}

int main(int argc, const char *argv[])
{
  char str[] = "  abc def   aga ada   xxx    ";
  std::cout << "before:" << str << "$" << std::endl;
  std::cout << "after:" << remove_extra_spaces(str) << "$" << std::endl;
  return 0;
}
