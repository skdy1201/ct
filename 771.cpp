#include <string>
using std::string;

#include <stack>
using std::stack;

int numJewelsInStones(string jewels, string stones) 
{

    stack<char> jewel = {};
    int count = 0;

    for (int i = 0; i < jewels.size(); ++i)
    {
        jewel.push(jewels[i]);
    }

    while(jewel.size() != 0)
    {
        for (int j = 0; j < stones.size(); ++j)
        {
            char stone = stones[j];

            char singlejewels = jewel.top();

            if (stone == singlejewels)
            {
                ++count;
                
                if (j == stones.size() - 1)
                {
                    jewel.pop();
                }

            }
            else
            {
                if (j == stones.size() - 1)
                {
                    jewel.pop();
                }

                continue;
            }
        }
        
    }

    return count;
}

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        
    stack<char> jewel = {};
    int count = 0;

    for (int i = 0; i < jewels.size(); ++i)
    {
        jewel.push(jewels[i]);
    }

    while(jewel.size() != 0)
    {
        for (int j = 0; j < stones.size(); ++j)
        {
            char stone = stones[j];

            char singlejewels = jewel.top();

            if (stone == singlejewels)
            {
                ++count;
                
                if (j == stones.size() - 1)
                {
                    jewel.pop();
                }

            }
            else
            {
                if (j == stones.size() - 1)
                {
                    jewel.pop();
                }

                continue;
            }
        }
        
    }

    return count;
    }
};

int main()
{
    string jewels = "aA";
    string stones = "aAAbbbb";

    int b = numJewelsInStones(jewels, stones);

   

    return 0;
}