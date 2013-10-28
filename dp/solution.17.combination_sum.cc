#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > result;
    sort(candidates.begin(), candidates.end());

    vector<int> solution;
    _combinationSum(candidates, target, 0, result, solution);

    return result;
}

void _combinationSum(vector<int> &candidates, int target, int i, vector<vector<int> >& result, vector<int>& solution) {
    if (target == 0) {
        result.push_back(solution);
        return;
    }

    if (i == candidates.size()) return;

    int n = 0;
    while (target - n * candidates[i] >= 0) {
        _combinationSum(candidates, target - n * candidates[i], i + 1, result, solution);
        solution.push_back(candidates[i]);
        n += 1;
    }

    while (n-- > 0) solution.pop_back();
}
