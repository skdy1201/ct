#include <algorithm>
#include <vector>

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 1; i < n; ++i) {
            
            int profit = prices[i] - prices[i - 1];

           
            if (profit > 0) {
                maxProfit += profit;
            }
        }

        return maxProfit;
    }
};

int main()
{

    vector<int> prices = { 7,1,5,3,6,4 };

    Solution s;

    int b = s.maxProfit(prices);

    int c = 0;




    return 0;
}