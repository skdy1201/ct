#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int m = s.size(), n = t.size(); // t문자열 사이즈, s문자열 사이즈를 저장
        unordered_map<char, int> mp; // 해당 문자와 문자의 수를 저장하는 맵

        int ans = INT_MAX; // 정답 int 변수
        int start = 0; // 시작 변수

        for (auto x : t) 
            mp[x]++; // 순서대로  map에 (문자열, 1)로 저장

        int count = mp.size(); // 목적 문자열의 사이즈

        int i = 0, j = 0;

        while (j < s.length()) 
        {
            mp[s[j]]--; // map의 정수값을 감소
            
            if (mp[s[j]] == 0) // 감소해서 0이라면 카운트 감소
                count--;

            if (count == 0)  //카운트가 0인데,
            {
                while (count == 0)  //카운트가 0인데,
                {
                    if (ans > j - i + 1) // 결과값이 j에서 i를 뺀 값에 1을 더한것 보다 크다면
                    {
                        ans = j - i + 1; // 값을 그걸로 변경
                        start = i; // 시작을 i로 변경
                    }
                    
                    mp[s[i]]++; // 맵의 i 번째에 1증가
                    
                    if (mp[s[i]] > 0) // 만약 i가 1보다 크다면 카운트 증가
                        count++;

                    i++;// i추가
                }
            }
            
            j++; // j 추가
        }

        if (ans != INT_MAX)//만약 ans가  초기값이 아니라면
            return s.substr(start, ans); //s의 문자열에서 시작부터 정답부분까지의 문자열 추출
        else
            return ""; // 아니라면 빈 문자열 반환
    }
};

int main()
{
    Solution q;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string b = q.minWindow(s, t);

    int c = 0;


    return 0;
}