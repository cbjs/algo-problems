#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
            continue;
        }
        if (st.empty()
                || (s[i] == ')' && st.top() != '(')
                || (s[i] == '}' && st.top() != '{')
                || (s[i] == ']' && st.top() != '['))
            return false;
        st.pop();
    }
    return st.empty();
}

int main(int argc, char *argv[])
{
    string s = "()";
    cout << s << " is valid: " << isValid(s);
    return 0;
}
