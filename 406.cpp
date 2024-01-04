#include <vector>
#include <algorithm>
using namespace std;


//idea
//먼저 키순으로 정렬
//같다면 뒤를 비교해서 정렬


class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) 
    { 
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    // 비교해주는 함수. 키순으로 비교를 한 뒤, 앞이 같다면 뒤를 비교해준다.

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), comp);  //정렬
        
        vector<vector<int>> ans;                   //반환 벡터
        
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

//원하는 답 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

//  70 71 61 50 52 44로 정렬
// 70 61 71 이런식으로 들어간다.
// 50 70  61 71
// 이중벡터의 뒤 인자를 통해서 들어갈 위치를 선정하는것.
// vector을 정렬한 상태이기 때문에 가능하다.