#include <vector>

using namespace std;

class Solution {
	public:
		int maxGifts(vector<int> gifts) {
			return _maxGifts(gifts, 0, gifts.size(), 0);
		}
		int _maxGifts(vector<int>& gifts, int i, int j, int gift) {
			if (i >= j) return gift;

			// use i
			int maxone, maxtwo;
			if (i == 0) {
				maxone = _maxGifts(gifts, i + 2, j - 1, gift + gifts[i]);
			} else {
				maxone = _maxGifts(gifts, i + 2, j, gift + gifts[i]);
			}

			// not use i
			maxtwo = _maxGifts(gifts, i + 1, j, gift);
			return maxone > maxtwo ? maxone : maxtwo;
		}
};
