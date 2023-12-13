#include <vector>
using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i + 1])
            {
                if (profit != 0)
                {
                    if (diff > prices[i + 1] - prices[i])
                    {
                        continue;
                    }
                }

                diff = prices[i + 1] - prices[i];
                profit = prices[i + 1];
            }
        }

        return profit;
    }
};