#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 모든 주유소에서 출발 가능한지 확인
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        int start = 0;
        int fuel = 0;

        for (size_t i = 0; i < gas.size(); i++)
        {
            // 현재 주유소에서 출발할 수 없는 경우
            if (gas[i] < cost[i] && fuel + gas[i] < cost[i])
            {
                start = i + 1;  // 출발 지점을 현재 주유소의 다음으로 변경
                fuel = 0;      // 연료 초기화
            }
            else
            {
                fuel += gas[i] - cost[i];  // 주유소까지 이동
            }
        }

        return start;

    }
};

int main()
{
    Solution q;

    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = { 3,4,5,1,2 };

    int s = q.canCompleteCircuit(gas, cost);

    int b = 0;


    return 0;
}