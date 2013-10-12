#include <iostream>
#include <string>

using namespace std;

// 分析:
//   如果其中一个是空串，直接用另一个字符串和s3比较
//   观察个例子:
//     s1 = a b x x, s2 = a d y y , s3 = a d a b y y x x
//
//     s3 a d a b y y x x
//     s1 a ...
//     尝试把s1的第一个字符a和s3中[第一个]a对齐
//     (得到一个子问题)s1 = bxx, s2 = adyy , s3 = dabyyxx, 继续
//
//     s3 d a b y y x x
//     s1     b ...
//     s2 a d ...
//     s1中字符b和s3对齐后, s3前面部分"da"与s2前缀不匹配, 失败
//
//     s3 a d a b y y x x
//     s1     a ...
//     s2 a d ...
//     尝试把s1的第一个字符a和s3中[第二个]a对齐
//     s3前部分"ad"和s2前缀匹配
//     子问题s1 = bxx, s2 = yy, s3 = byyxx
//     ...
//     直至匹配成功
//
//   s_suffix[i]表示字符串s中从下标i开始的后缀子串
//   子问题: s1_suffix[i]和s2_suffix[j]是否可以交叉生成s3_suffix[i + j]
//   原问题转换成s1_suffix[0]和s2_suffix[0]是否可以交叉生成s3_suffix[0]
//
//   分析，给定s1, s2, 可能有多种交叉方式合并成s3,
//          此问题只需要找到一种就可以立即返回
//         另外，从递归版本来看，很多子问题结果查询不到,
//         不考虑至底向上填表计算
//
//   下面实现recursive和memo版本

// Recursive版本, 会重复计算子问题
bool isInterleaveRecursive(string s1, string s2, string s3) {
    if (s1.size() > s2.size())
        return isInterleave(s2, s1, s3);

    if (s1.empty()) return s2 == s3;

    for (int i = 0; i < s3.size(); i++) {
        // 尝试把s1第一个字符和s3对齐
        if (s3[i] == s1[0]) {
            // 测试s2前缀和s3前缀相等
            if (s2.size() > i && s2.substr(0, i) == s3.substr(0, i)) {
                // 递归计算子问题
                if(isInterleave(s1.substr(1), s2.substr(i), s3.substr(i + 1)))
                    return true;
            } else {
                return false;
            }
        }
    }
    return false;
}


// 计算子问题s1_suffix[i1], s2_suffix[i2], s3[i1 + i2]
int _isInterleave(string s1, int i1, string s2, int i2, string s3, int** record) {
    // 其中一个为空串，直接用另一个字符串和s3比较
    if (i1 == s1.size()) {
        if (s2.substr(i2) == s3.substr(i1 + i2))
            return 1;
        else
            return -1;
    }
    if (i2 == s2.size()) {
        if (s1.substr(i1) == s3.substr(i1 + i2))
            return 1;
        else
            return -1;
    }

    // 已计算，直接返回
    if (record[i1][i2]) return record[i1][i2];

    // 计算
    record[i1][i2] = -1;
    for (int i = i1 + i2; i < s3.size(); i++) {
        if (s3[i] == s1[i1]) {
            int l = i - i1 - i2;
            if (s2.size() - i2 >= l && s2.substr(i2, l) == s3.substr(i1 + i2, l)) {
                if (_isInterleave(s1, i1 + 1, s2, i2 + l, s3, record) == 1) {
                    record[i1][i2] = 1;
                    break;
                }
            } else {
                record[i1][i2] = -1;
                break;
            }
        }
    }
    return record[i1][i2];
}

// memo版本
bool isInterleave(string s1, string s2, string s3) {
    // 初始化表格, 0表示没有计算，-1表示失败，1表示成功
    int** record = new int*[s1.size()];
    for (int i = 0; i < s1.size(); i++) {
        record[i] = new int[s2.size()];
        for (int j = 0; j < s2.size(); j++) {
            record[i][j] = 0;
        }
    }

    int result = _isInterleave(s1, 0, s2, 0, s3, record);

    for (int i = 0; i < s1.size(); i++) {
        delete[] record[i];
    }
    delete[] record;

    return result == 1;
}

int main(int argc, char *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    std::cout << s3 << ":" << isInterleave(s1, s2, s3) << std::endl;
    std::cout << s4 << ":" << isInterleave(s1, s2, s4) << std::endl;
    return 0;
}
