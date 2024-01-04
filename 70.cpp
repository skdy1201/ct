#include <vector>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
       
        if (n <= 3) {
            return n;
        }

        vector<int> dp(45,0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i < n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

/*
class Solution {
public:
    int climbStairs(int n) {

        int res = 0;

        switch (n)
        { 
            case 1:
                res = 1;
                break;
            case 2:
                res = 2;
                break;
            case 3:
                res = 3;
                break;
        }

        if (res == 1 || res == 2 || res == 3)
            return res;
       
        res = climbStairs(n - 1) + climbStairs(n - 2);

        return res;
    }
};*/