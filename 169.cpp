#include <vector>
#include <algorithm>
using namespace std;


// ??? 
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        int res = nums[nums.size() / 2];

        return res;    
    }
};



/*class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int res = 0;

        int checkelement = 0;
        
        checkelement = nums[0];

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == checkelement)
                ++res;
        }

        if (res > nums.size() / 2)
            return checkelement;
        else
        {
            int j = 0;

            while (true)
            {
                if (nums[j] != checkelement)
                {
                    res = nums[j];
                    return res;
                }

                ++j;
            }
        }
    }
};
*/

int main()
{

    vector<int> a = { 2,2,1,1,1,2,2 };

    Solution s;

    int b = s.majorityElement(a);

    int c = 0;



    return 0;
}