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
            // 창문 담기
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
            // 윈도우를 벗어난 인덱스 제거
            while (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // 현재 값을 기존 윈도우 내의 작은 값으로 만드는 인덱스 제거
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            // 현재 인덱스 추가
            dq.push_back(i);

            // 윈도우 크기에 도달하면 최댓값 저장
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

    // 결과 출력
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}


