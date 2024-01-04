#include <vector>

using std::vector;
#include <algorithm>
using std::sort;
using std::greater;


/*


// time out case
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> window = {};

        vector<int> result = {};

        for (int j = 0; j < nums.size() - k + 1; ++j)
        {
            // â�� ���
            for (int i = j; i < k + j; ++i)
            {
                window.push_back(nums[i]);
            }

            sort(window.begin(), window.end(), greater<int>());

            result.push_back(window.front());

            window.clear();

        }

        return result;
    }
};

*/


#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq;
        std::vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // �����츦 ��� �ε��� ����
            while (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // ���� ���� ���� ������ ���� ���� ������ ����� �ε��� ����
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            // ���� �ε��� �߰�
            dq.push_back(i);

            // ������ ũ�⿡ �����ϸ� �ִ� ����
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    std::vector<int> result = solution.maxSlidingWindow(nums, k);

    // ��� ���
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}


