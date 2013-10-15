// I II III IV(4) V VI VII VIII IX(9) X
// XIX(19) XX(20)
// XL(40) XLI(41)
// XC(90)
// 观察规律
// 1. 大部分罗马数字从左到右，从大到小排列, 如VII(7), XXI(21)
// 2. 剩下小部分例外，IV(4), IX(9), XL(40), XLI(41), XC(90)
//  4   : 5    - 1
//  9   : 10   - 1
//  40  : 50   - 10
//  90  : 100  - 10
//  400 : 500  - 100
//  900 : 1000 - 100
// 算法：
//      给定数n, 罗马数字从大到小测试,
//          1. 若大于等于当前罗马数字，直接减掉，并拼接字符
//             如: 1402, 先减1000, 拼接'M'
//          2. 若小于当前罗马数字, 再测试是否满足规律2
//             如: 402, 小于1000，也不在[900, 1000)范围内, 继续测试下一个500
//                 在范围[400, 500)内，减掉400，拼接'CD'
class Solution {
public:
    string intToRoman(int num) {
        int rnums[] = {1000, 500, 100, 50, 10, 5, 1};
        char rchar[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int i = 0, n = 7;
        string result("");
        while (num > 0) {
            if (num >= rnums[i]) {
                num -= rnums[i];
                result += rchar[i];
            } else {
                int j = i + 2 - i % 2;
                if (num < rnums[i] && num >= (rnums[i] - rnums[j])) {
                    num -= (rnums[i] - rnums[j]);
                    result += rchar[j];
                    result += rchar[i];
                }
                i++;
            }
        }
        return result;
    }
};
