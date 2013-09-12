#include <iostream>

using namespace std;

int kth_num(int arra[], int as, int ae, int arrb[], int bs, int be, int k) {
  // 如果其中一个数组为空，返回另外一个数组中第k大的数
  if (bs >= be) return arra[as + k - 1];
  if (as >= ae) return arrb[bs + k - 1];

  int m = ae - as;
  int n = be - bs;
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
