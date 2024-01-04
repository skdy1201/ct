#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size();
        
        int maxLen = 0; // ������ �ִ� ����

        int maxCount = 0;  // ���� �κ� ���ڿ����� ���� ���� ������ ������ ����

        vector<int> count(26, 0);  // �� ���ĺ��� ���� Ƚ���� �����ϴ� �迭

        int left = 0, right = 0;

        while (right < n) {
            count[s[right] - 'A']++;  // ���� ������ ���� Ƚ�� ����

            maxCount = max(maxCount, count[s[right] - 'A']);  // ���� �κ� ���ڿ����� ���� ���� ������ ������ ���� ����

            // ���� �κ� ���ڿ��� ���̿��� ���� ���� ������ ������ ������ �� ���� k���� ũ�ٸ�
            // �κ� ���ڿ��� �����Ͽ� k������ ���ڸ� �ٲ� �� �ֵ��� ��
            if (right - left + 1 - maxCount > k) 
            {
                count[s[left] - 'A']--;  // �κ� ���ڿ����� ���� ���ʿ� �ִ� ������ ���� Ƚ�� ����
                left++;  // ���� ������ �̵�
            }

            maxLen = max(maxLen, right - left + 1);  // �ִ� ���� ����
            right++;  // ������ ������ �̵�
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    cout << solution.characterReplacement("ABAB", 2) << endl;  // Output: 4
    return 0;
}
