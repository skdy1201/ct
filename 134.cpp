#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // ��� �����ҿ��� ��� �������� Ȯ��
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        int start = 0;
        int fuel = 0;

        for (size_t i = 0; i < gas.size(); i++)
        {
            // ���� �����ҿ��� ����� �� ���� ���
            if (gas[i] < cost[i] && fuel + gas[i] < cost[i])
            {
                start = i + 1;  // ��� ������ ���� �������� �������� ����
                fuel = 0;      // ���� �ʱ�ȭ
            }
            else
            {
                fuel += gas[i] - cost[i];  // �����ұ��� �̵�
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