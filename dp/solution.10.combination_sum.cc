#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    vector<vector<int> > result;
    int n = num.size(), backtrace[n + 1][target + 1];

    for (int i = 0; i < n + 1; i++) {
        backtrace[i][0] = 1;
        for (int j = 1; j < target + 1; j++) {
            backtrace[i][j] = 0;
        }
    }

    // sort num array in descending order
    std::sort(num.begin(), num.end(), greater<int>());

    // 0 means false
    // 1 means true with num[i] only
    // 2 means true without num[i] only
    // 3 means true with and without num[i]
    for (int i = 1; i <= n; ++i) {
        for (int t = 1; t <= target; ++t) {
            if (t >= num[i - 1] && backtrace[i - 1][t - num[i - 1]]) backtrace[i][t] = 1;
            if (backtrace[i - 1][t]) {
                if (backtrace[i][t])
                    backtrace[i][t] = 3;
                else
                    backtrace[i][t] = 2;
            }
        }
    }

    for (int i = 0; i < n + 1; i++) {
        if (i > 0) cout << num[i - 1] << " : ";
        for (int j = 0; j < target + 1; j++) {
            cout << "backtrace[" << i << ", " << j << "] = " << backtrace[i][j] << ", ";
        }
        cout << endl;
    }

    if (!backtrace[n][target]) return result;

    result.push_back(vector<int>(1, target));
    for (int i = n; i > 0; --i) {
        cout << "num: " << num[i - 1] << " >> ";
        int m = result.size();
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < result[j].size(); k++) {
                cout << result[j][k] << ", ";
            }
            cout << " --- ";
            int left = result[j].back();

            cout << " | backtrace[" << i << ", " << left << "] = " << backtrace[i][left] << " | ";


            if (!left) continue;

            if (backtrace[i][left]) {
                if (backtrace[i][left] == 3) {
                    result.push_back(vector<int>(result[j]));
                }

                if (backtrace[i][left] != 2) {
                    result[j].back() = num[i - 1];
                    cout << " | back: " << result[j].back() << " | ";
                    result[j].push_back(left - num[i - 1]);
                    cout << " | back: " << result[j].back() << " | ";
                }
            }
            for (int k = 0; k < result[j].size(); k++) {
                cout << result[j][k] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < result.size(); ++i) {
        result[i].pop_back();
    }
    return result;
}

int main(int argc, char *argv[])
{
    int nums[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> num(nums, nums + sizeof(nums) / sizeof(int));
    int target = 8;
    vector<vector<int> > result = combinationSum2(num, target);

    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
