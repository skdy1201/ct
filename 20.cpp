#include <string>
using std::string;

#include <map>
using std::map;

#include  <stack>
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> open;
     
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{')
            {
                open.push(c);
            }
            else if(open.empty() == true)
            {
                return false;
            }

        

             char first = open.top();
             open.pop();

             if (c == '(' && first != ')' ||
                 c == '{' && first != '}' ||
                 c == '[' && first != ']')
             {
                 return false;
             }
        }

    }
};