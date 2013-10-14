#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    int cur_index = 0, cur_words_len = 0, cur_words_num = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (cur_words_len + words[i].size() + cur_words_num > L) {
            result.push_back(packWords(words, cur_index, cur_words_num, L - cur_words_len));
            cur_words_num = 1;
            cur_words_len = words[i].size();
            cur_index = i;
        } else {
            cur_words_len += words[i].size();
            cur_words_num ++;
        }
    }

    if (cur_words_num + cur_words_len <= L) {
        result.push_back(packWords(words, cur_index, cur_words_num, cur_words_num));
    } else {
        result.push_back(packWords(words, cur_index, cur_words_num, cur_words_num - 1));
    }
    return result;
}

string packWords(vector<string> &words, int startIndex, int wordNum, int spaceNum) {
    string result("");
    int base = 0, mod = 0;
    if (wordNum == 1) base = spaceNum;
    else {
        base = spaceNum / (wordNum - 1);
        mod = spaceNum % (wordNum - 1);
    }
    while (wordNum-- > 0) {
        result += words[startIndex++];
        if (spaceNum > 0) {
            result += string(base, ' ');
            spaceNum -= base;
            if (mod-- > 0) {
                result += " ";
                spaceNum -= 1;
            }
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    vector<string> words;
    words.push_back("");
    return 0;
}
