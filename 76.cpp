#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int m = s.size(), n = t.size(); // t���ڿ� ������, s���ڿ� ����� ����
        unordered_map<char, int> mp; // �ش� ���ڿ� ������ ���� �����ϴ� ��

        int ans = INT_MAX; // ���� int ����
        int start = 0; // ���� ����

        for (auto x : t) 
            mp[x]++; // �������  map�� (���ڿ�, 1)�� ����

        int count = mp.size(); // ���� ���ڿ��� ������

        int i = 0, j = 0;

        while (j < s.length()) 
        {
            mp[s[j]]--; // map�� �������� ����
            
            if (mp[s[j]] == 0) // �����ؼ� 0�̶�� ī��Ʈ ����
                count--;

            if (count == 0)  //ī��Ʈ�� 0�ε�,
            {
                while (count == 0)  //ī��Ʈ�� 0�ε�,
                {
                    if (ans > j - i + 1) // ������� j���� i�� �� ���� 1�� ���Ѱ� ���� ũ�ٸ�
                    {
                        ans = j - i + 1; // ���� �װɷ� ����
                        start = i; // ������ i�� ����
                    }
                    
                    mp[s[i]]++; // ���� i ��°�� 1����
                    
                    if (mp[s[i]] > 0) // ���� i�� 1���� ũ�ٸ� ī��Ʈ ����
                        count++;

                    i++;// i�߰�
                }
            }
            
            j++; // j �߰�
        }

        if (ans != INT_MAX)//���� ans��  �ʱⰪ�� �ƴ϶��
            return s.substr(start, ans); //s�� ���ڿ����� ���ۺ��� ����κб����� ���ڿ� ����
        else
            return ""; // �ƴ϶�� �� ���ڿ� ��ȯ
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