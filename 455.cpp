#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <algorithm>
using std::sort;
using std::min;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int kid = 0;
        int cookie = 0;
        while (kid < s.size() && cookie < g.size()) {
            if (s[kid] >= g[cookie])
                ++cookie;
           
            kid++;
        }
        return cookie;
    }
};














/*int findContentChildren(vector<int>& g, vector<int>& s) {

    int satisfiedchild = 0;

    if (s.size() == 0)
        return 0;

    int Childnum = g.size() - 1;
    int Cookienum = s.size() - 1;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());


    while (Childnum >= 0 && Cookienum >= 0)
    {
        if (g[Childnum] <= s[Cookienum])
        {
            ++satisfiedchild;
            --Childnum;
            --Cookienum;
        }
        else
        {
            --Childnum;
        }
    }

    return satisfiedchild;
}*/

