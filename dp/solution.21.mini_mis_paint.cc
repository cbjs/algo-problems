#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class MiniPaint {
 public:
   int leastBad(vector<string> picture, int maxStrokes) {
     int m = picture.size(), n = picture[0].size();

     int minBad[m][n][maxStrokes + 1];
     memset(minBad, 0, sizeof(minBad));

     int total = 0, diff = 0;
     for (int i = m - 1; i >= 0; i--) {
       for (int j = n - 1; j >= 0; j--) {
         total += 1;
         diff += 1;
         minBad[i][j][0] = total;
         int a = i, b = j + diff;
         if (b == n) { a += 1; b = 0; }
         for (int k = 1; k < maxStrokes + 1; k++) {
           if (a == m) {
             minBad[i][j][k] = 0;
           } else {
             minBad[i][j][k] = min(minBad[a][b][k - 1], diff + minBad[a][b][k]);
           }
         }
         if (j == 0 || picture[i][j - 1] != picture[i][j]) diff = 0;
       }
     }

     return minBad[0][0][maxStrokes];
   } // end of in leastBad()
};
