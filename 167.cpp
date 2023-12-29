#include <vector>
using std::vector;

#include <algorithm>
using std::pair;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return { left + 1, right + 1 }; 
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       vector<pair<int,int>> sort;
       vector<int> ans;

        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] < target)
            {
                pair<int, int> temp;
                temp.first = numbers[i];
                temp.second = i;
                sort.push_back(temp);
           }
        }

        for (int i = 0; i < sort.size(); ++i)
        {
            for (int j = i + 1; j < sort.size(); ++j)
            {
                if (sort[i].first + sort[j].first == target)
                {
                    ans.push_back(sort[i].second);
                    ans.push_back(sort[j].second);
                    return ans;
                }
                
            }
        }
    }
};