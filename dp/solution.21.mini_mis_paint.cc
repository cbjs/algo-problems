#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class MiniPaint {
 public:
   int leastBad(vector<string> picture, int maxStrokes) {
     int m = picture.size(), n = picture[0].size();

     int lastBad[maxStrokes + 1][2];
     int newBad[maxStrokes + 1][2];

     int minBad[maxStrokes + 1];
     int tmpBad[maxStrokes + 1];
     memset(minBad, 0, sizeof(minBad));
     memset(tmpBad, 0, sizeof(tmpBad));

     for (int i = 0; i < m; i++) {
       memset(lastBad, 0, sizeof(lastBad));
       memset(newBad, 0, sizeof(newBad));
       int j = 0, last = -1;
       while (j < n) {
         while (j + 1 < n && picture[i][j + 1] == picture[i][j]) {
            j += 1;
         }

         newBad[0][0] = j + 1;
         newBad[0][1] = j + 1;
         for (int k = 1; k < maxStrokes + 1; k++) {
           // for 'B'
           newBad[k][0] = (picture[i][j] == 'W' ? j - last: 0);
           newBad[k][0] += min(lastBad[k][0], lastBad[k - 1][1]);
           // for 'W'
           newBad[k][1] = (picture[i][j] == 'B' ? j - last: 0);
           newBad[k][1] += min(lastBad[k][1], lastBad[k - 1][0]);
         }

         last = j;
         j += 1;
         memcpy(lastBad, newBad, sizeof(newBad));
       }

       for (int k = 0; k < maxStrokes + 1; k++) {
         minBad[k] = min(newBad[k][0], newBad[k][1]);
       }

       for (int k = maxStrokes; k >= 0; k--) {
         minBad[k] += tmpBad[0];
         for (int i = 1; i < k + 1; i++) {
           if (minBad[k] > (tmpBad[i] + minBad[k - i])) {
             minBad[k] = tmpBad[i] + minBad[k - i];
           }
         }
       }
       memcpy(tmpBad, minBad, sizeof(minBad));
     }
     return minBad[maxStrokes];
   } // end of in leastBad()
};
