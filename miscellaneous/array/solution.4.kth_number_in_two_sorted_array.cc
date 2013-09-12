#include <iostream>

using namespace std;

// 假设数组c是a和b合并排序后的数组
// 比较中位数，数组下标从0开始, a有la, b有lb个元素
//  若a[ma] >= b[mb], 在数组c中，b[mb]之前(包括b[mb])的mb + 1个数一定出现在a[ma]之前
//                      则a[ma]之前至少有ma + mb + 1个数
//                    在数组c中, a[ma]之后(包括a[ma])的la - ma个元素一定出现在b[mb]之后
//                      则b[mb]之后至少有(la + lb) - (ma + mb + 1)个数
//    若k <= ma + mb + 1, 则只需在a[0, ma)和b[0, end)中找第K大的数
//    若k > ma + mb + 1, 则在a[0, end]和b[mb + 1, end)中找第K - mb - 1大的数
//  若a[ma] < b[mb]同理分析
int kth_num(int arra[], int as, int ae, int arrb[], int bs, int be, int k) {
  // 如果其中一个数组为空，返回另外一个数组中第k大的数
  if (bs >= be) return arra[as + k - 1];
  if (as >= ae) return arrb[bs + k - 1];

  // m,n为两个数组大小
  int m = ae - as;
  int n = be - bs;

  // 比较中位数
  if (arra[as + m/2] >= arrb[bs + n/2]) {
    if (k <= (m/2 + n/2 + 1)) {
      return kth_num(arra, as, as + m/2, arrb, bs, be, k);
    } else {
      return kth_num(arra, as, ae, arrb, bs + n/2 + 1, be, k - n/2 -1);
    }
  } else {
    if (k <= (m/2 + n/2 + 1)) {
      return kth_num(arra, as, ae, arrb, bs, bs + n/2, k);
    } else {
      return kth_num(arra, as + m/2 + 1, ae, arrb, bs, be, k - m/2 - 1);
    }
  }
}

int main(int argc, const char *argv[])
{
  int a[] = {1, 2, 3, 4};
  int b[] = {4, 5, 6};
  for (int i = 0; i < 6; i++) {
    std::cout << (i + 1) << "th num:"
              << kth_num(a, 0, sizeof(a)/sizeof(int), b, 0, sizeof(b) / sizeof(int), i + 1)
              << std::endl;
  }
  return 0;
}
