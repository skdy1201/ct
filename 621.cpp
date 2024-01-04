#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


//idea
//인자로 들어온 vector에서 task 분류
//순회하면서 작업을 한번씩 뺀다.
//n번째 작업을 했을때 다음 작업으로 idle을 넣는다.


//덱을 사용해야한다고 생각했는데, gpt도 코드를 구현하지 못했다. - a-b-c 순으로 작업을 순차적으로 빼는 것이라서 앞뒤로 데이터를 넣을 수 있는 deque를 써야 한다고 생각
//대부분의 풀이는 우선순위 큐였다.


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq; // 우선순위 큐 변수
        vector<int>mp(26, 0); // int vector - a ~ z까지 작업이 존재

        for (char i : tasks) 
        {
            mp[i - 'A']++;  
        }
        // char 변수로 범위 반복문을 돌면서 task의 vecotr에서 i 번째의 인자에서 아스키코드를 빼서 int 큐에 담아둔다.
        //만약 i가 a라면 a -a 이므로, 작업vector의 0번 idx에 tasks의 a 작업 횟수가 들어갈 것이다.
        
        for (int i = 0; i < 26; ++i)
        {
            if (mp[i])
                pq.push(mp[i]);
        }
        //반복문을 돌면서 우선순위 큐에 작업 벡터에서 각 작업에 대한 횟수를 넣는다.
        //작업이 존재한다면 mp[i]가 0이 아닐것이다.

        int time = 0; // 작업 횟수를 저장하는 변수
        
        while (!pq.empty()) // 큐가 비어있지 않다면 반복
        {
            vector<int>remain; // 남은 작업을 저장하는 벡터

            int cycle = n + 1;  //  한 작업을 다 돌린다면 idle 상태가 되어야 하니까 n+1

            while (cycle && !pq.empty())  //  사이클이 0이 아니고, 큐가 비어있지 않는다면 반복
            {
                int max_freq = pq.top(); // 최대 빈도변수는 큐의 가장 높은 것을 저장. 우선순위 큐니까 가장 많은 작업이 들어간다.

                pq.pop(); // 최대 빈도 변수에 저장하고 큐에서는 뺀다.

                if (max_freq > 1) // 가장 높은 빈도 작업이 1보다 크다면,
                { 
                    remain.push_back(max_freq - 1); // 잔여 작업 벡터에 최대 빈도에서 하나를 빼고 넣는다.
                }

                ++time; // 시간을 더한다.

                --cycle; // 사이클을 하나 뺀다.
            }

            for (int count : remain)  // remain 벡터를 순회하면서
            {
                pq.push(count); // 큐에 다시 작업을 집어넣는다.
            }

            if (pq.empty()) // 만약 큐가 비었다면
                break; // 반복문 탈출

            time += cycle; // 작업 횟수에 사이클을 더한다.
        }
        return time;
    }
};


int main()
{
    vector<char> a = { 'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;
   
    Solution w;
    
    int b = w.leastInterval(a, n);

    int c = 0;


    return 0;
}

// mp의 0에 3, 1에 3이 들어갔다.
// pq에도 똑같이 들어갔다.
// cycle은 3
// 이상황에선 a b 둘다 3이라서 b를 먼저 뺀것 같다. (이건 정확하진 않음)
// task 하나를 수행하고 remain에 넣으면 pq에는 작업이 하나 남아있고 cycle은 하나 줄어있다.
// 각각 작업을 한번씩 빼고, 다시 remain에 집어넣었다. pq는 빈 상황이다.
// pq가 비었으니 remain vecotr에서 다시 순회하면서 pq에 집어넣는다.
// 다시 pq에 2,2가 들어가고, pq가 비지 않았으므로, 횟수에 사이클을 집어넣는다. n+1이니까 qp를 비우면서 작업이 한번씩 끝났다면, 마지막은 pq가 빈상태에서 cycle만 1이 남으니 그것이 idle
// 그래서 8이 나온다.
// 큐가 비었을때 탈출하는 조건이 횟수에 사이클을 더한것보다 위에 있기 때문에, 마지막에 cycle이 남아도 더해지지않고 탈출이 가능하다.