#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size();
        
        int maxLen = 0; // 문자의 최대 길이

        int maxCount = 0;  // 현재 부분 문자열에서 가장 많이 등장한 문자의 개수

        vector<int> count(26, 0);  // 각 알파벳의 등장 횟수를 저장하는 배열

        int left = 0, right = 0;

        while (right < n) {
            count[s[right] - 'A']++;  // 현재 문자의 등장 횟수 증가

            maxCount = max(maxCount, count[s[right] - 'A']);  // 현재 부분 문자열에서 가장 많이 등장한 문자의 개수 갱신

            // 현재 부분 문자열의 길이에서 가장 많이 등장한 문자의 개수를 뺀 값이 k보다 크다면
            // 부분 문자열을 조절하여 k번까지 문자를 바꿀 수 있도록 함
            if (right - left + 1 - maxCount > k) 
            {
                count[s[left] - 'A']--;  // 부분 문자열에서 가장 왼쪽에 있는 문자의 등장 횟수 감소
                left++;  // 왼쪽 포인터 이동
            }

            maxLen = max(maxLen, right - left + 1);  // 최대 길이 갱신
            right++;  // 오른쪽 포인터 이동
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    cout << solution.characterReplacement("ABAB", 2) << endl;  // Output: 4
    return 0;
}
