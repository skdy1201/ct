#include <algorithm>
using std::swap;

#include <vector>
using std::vector;


void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{

    vector<int> nums = { 2, 0, 2, 1, 1, 0 };

    sortColors(nums);


    int b = 0;

    return 0;
}