#include <vector>
using std::vector;


#include <algorithm>
using std::sort;
using std::greater;
using std::max;




class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};


/*
class Solution {
public:
    int rob(vector<int>& nums) {

        int evennum = 0, oddnum = 0;

        for (int i = 0; i < nums.size(); i += 2)
        {
            int j = i + 1;

            evennum += nums[i];

            if(j != nums.size())
             oddnum += nums[j];
        }

        return max(evennum, oddnum);
    }
};*/




int main()
{
    vector<int>nums = { 1,2,3,1 };

    Solution m;

    int res = m.rob(nums);


    int c = 0;

    return 0;
}