#include <iostream>

using namespace std;

char* remove_extra_spaces(char* str) {
  if (!str || !*str) return str;

  char* i = str;
  char* j = str;

  // strip spaces at the begining
  while (*j == ' ') ++j;

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

char* remove_extra_spaces_arr(char* str) {
  if (!str || !*str) return str;

  int i = -1;
  int j = 0;
  while (str[j] == ' ') ++j;

  while(str[j]) {
    if (str[j] != ' ' || str[i] != ' ') {
      str[++i] = str[j];
    }
    j++;
  }

  if (i != -1 && str[i] == ' ') str[i] = '\0';
  else str[i + 1] = '\0';
  return str;
}

int main(int argc, const char *argv[])
{
  char str[] = "  abc def   aga ada   xxx    ";
  std::cout << "before:" << str << "$" << std::endl;
  std::cout << "after:" << remove_extra_spaces(str) << "$" << std::endl;

  char str1[] = "  abc def   aga ada   xxx    ";
  std::cout << "before:" << str1 << "$" << std::endl;
  std::cout << "after:" << remove_extra_spaces_arr(str1) << "$" << std::endl;
  return 0;
}
