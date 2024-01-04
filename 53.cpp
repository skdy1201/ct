#include <algorithm>
#include <vector>
#include <deque>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int result = INT_MIN; //-1;
        int temp = 0;

        if (nums.size() == 1)
            return nums[0];



        for (size_t i = 0; i < nums.size(); ++i)
        {
            temp += nums[i];
            

            if (temp > result)
            {
                result = temp;
            }
            
            if (temp < 0)
            {
                temp = 0;
            }
           
        }
      
        return result;

    }
};


int main()
{

    vector<int> nums = { 5, 4, -1, 7, 8 };

    Solution s;

    int d = s.maxSubArray(nums);

    int c = 0;

    return 0;
}