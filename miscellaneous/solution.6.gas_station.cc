#include <vector>
#include <iostream>

using namespace std;

// startIndex记录开始位置，gas_in_tank记录当前车中油量
//  从任意一个位置startIndex = i开始向前试探
//  如果走到位置j后, gas_in_tank为负，将开始位置startIndex从i向后移动直到gas_in_tank大于0
//  再继续从j向前试探，直到走完一圈，所有的station只经过一次
//  返回startIndex值
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    if (gas.empty()) return -1;
    int startIndex = 0, curIndex = 0;
    int gas_in_tank = 0;
    do {
        if (gas_in_tank >= 0) {
            gas_in_tank += (gas[curIndex] - cost[curIndex]);
            curIndex = (curIndex + 1) % gas.size();
        } else {
            startIndex = (startIndex - 1 + gas.size()) % gas.size();
            gas_in_tank += (gas[startIndex] - cost[startIndex]);
        }
    } while (curIndex != startIndex);

    if (gas_in_tank >= 0) return startIndex;
    return -1;
}

int main(int argc, char *argv[])
{
    std::vector<int> gas;
    std::vector<int> cost;
    for (int i = 0; i < 10; i++) {
        gas.push_back(i + 1);
        cost.push_back(10 - i);
    }

    std::cout << "start at:" << canCompleteCircuit(gas, cost);
    return 0;
}
