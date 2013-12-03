string equal_by_multiplying_2(vector <int> A)
{
    if (A.size() <= 1) return "YES";

    for (int i = 1; i < A.size(); i++) {
      int min_v = min(A[i], A[i - 1]);
      int max_v = max(A[i], A[i - 1]);

      if (max_v % min_v != 0) return "NO";

      int quotient = max_v / min_v;
      if (quotient & (quotient - 1)) return "NO";
    }
    return "YES";
}
