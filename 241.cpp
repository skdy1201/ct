#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        //결과 벡터
        vector<int> result;
        
        //문자열 사이즈
        int size = input.size();
        
        
        for (int i = 0; i < size; i++) 
        {
            //현재 문자를 넣는다.
            char cur = input[i];
            
            //만약 문자가 연산자라면
            if (cur == '+' || cur == '-' || cur == '*') 
            {
            
                // 연산자를 기준으로 앞 뒤를 쪼갠다.(0 ~ i번째까지)
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                
                //substr에 인자가 없다는 것은 해당 부분부터 마지막 까지
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                
                //auto반복문
                //vec1에는 연산자 기준 왼쪽 숫자, vec2에는 연산자 기준 오른쪽 숫자
                // cur에 있는 연산자에 따라 연산한 값을 res vec에 넣는다.
                for (auto n1 : result1) 
                {
                    
                    for (auto n2 : result2) 
                    {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // 만약 반복문을 거치지 않고 결과가 비어있다면, 숫자만 들어있으니까, atoi로 문자열을 숫자로 바꿔서 넣고 반환
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};

//재귀로 뒤부터 쪼개서 올라온다.
//2 -1 -1이라면
// 2를 때고 1-1이 다시 들어가서
// 2 - (1-1)의 계산을 한다.
//
// 그 결과를 vec에 담는다.

//그리고 가장 큰 for문에서 다시 반복을 하며 1이 들어가면
// 2-1과 1로 나뉘어서 다시 연산
// // 그래서 0이 나온다.
// 나오는 결과를 추가

//그리고 다시 반복을 돌아서 1이 들어가지만
//result엔 이미 결과가 있기때문에 추가하지 않고 반목문은 종료하며  return된다.

int main()
{

    string s = "2-1-1";

    Solution q;

    vector<int> a = q.diffWaysToCompute(s);


    int w = 0;


    return 0;
}