#include <vector>
#include <algorithm>
using namespace std;


//idea
//���� Ű������ ����
//���ٸ� �ڸ� ���ؼ� ����


class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) 
    { 
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    // �����ִ� �Լ�. Ű������ �񱳸� �� ��, ���� ���ٸ� �ڸ� �����ش�.

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), comp);  //����
        
        vector<vector<int>> ans;                   //��ȯ ����
        
        for (auto man : people) 
        {
            ans.insert(ans.begin() + man[1], man);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> people = { {7, 0} ,{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };

    Solution q;

    vector<vector<int>> a = q.reconstructQueue(people);


    int c = 0;




    return 0;
}

//���ϴ� �� [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

//  70 71 61 50 52 44�� ����
// 70 61 71 �̷������� ����.
// 50 70  61 71
// ���ߺ����� �� ���ڸ� ���ؼ� �� ��ġ�� �����ϴ°�.
// vector�� ������ �����̱� ������ �����ϴ�.