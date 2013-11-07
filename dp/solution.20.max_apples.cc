#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
  public:
	  int maxApples(vector<vector<int> >& apples) {
	  	int m = apples.size(), n = apples[0].size();
	  	int M[50][50][50];
	  	memset(M, 0, sizeof(M));

	  	M[0][0][0] = apples[0][0];
	  	for (int s = 1; s < m + n - 1; ++s) {
	  		for (int i = min(n, s + 1) - 1; i >= max(0, s - m + 1); --i) {
	  			for (int j = min(n, s + 1) - 1; j >=i; --j) {
	  				for (int k = min(n, s + 1) - 1; k >= j; --k) {
              // find max M[s - 1]
	  					if (i > 0) {
	  						M[i][j][k] = max(M[i][j][k], M[i - 1][j][k]);
	  						M[i][j][k] = max(M[i][j][k], M[i - 1][j][k - 1]);
	  						M[i][j][k] = max(M[i][j][k], M[i - 1][j - 1][k]);
	  						M[i][j][k] = max(M[i][j][k], M[i - 1][j - 1][k - 1]);
	  					}
	  					if (j > 0) {
	  						M[i][j][k] = max(M[i][j][k], M[i][j - 1][k]);
	  						M[i][j][k] = max(M[i][j][k], M[i][j - 1][k - 1]);
	  					}
	  					if (k > 0) M[i][j][k] = max(M[i][j][k], M[i][j][k - 1]);

              // add apples from current cell
	  					M[i][j][k] += apples[s - i][i];
	  					if (j != i) M[i][j][k] += apples[s - j][j];
	  					if (k != j) M[i][j][k] += apples[s - k][k];
	  				}
	  			}
	  		}
	  	}
	  	return M[n - 1][n - 1][n - 1];
	}
};
