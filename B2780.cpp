#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <string>

using namespace std;

int N;
int dp[1001][10];

int pass(int leng, int now) {
    if (leng == 1)return 1;
    if (dp[leng][now] != -1)return dp[leng][now];

    int val;

    switch (now)
    {
    case 0:
        val = pass(leng - 1, 7) % 1234567;
        dp[leng][now] = val;
        return val;
    case 1:
        val = pass(leng - 1, 2) % 1234567 + pass(leng - 1, 4) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 2:
        val = pass(leng - 1, 1) % 1234567 + pass(leng - 1, 3) % 1234567 + pass(leng - 1, 5) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 3:
        val = pass(leng - 1, 2) % 1234567 + pass(leng - 1, 6) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 4:
        val = pass(leng - 1, 1) % 1234567 + pass(leng - 1, 5) % 1234567 + pass(leng - 1, 7) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 5:
        val = pass(leng - 1, 2) % 1234567 + pass(leng - 1, 4) % 1234567 + pass(leng - 1, 6) % 1234567 + pass(leng - 1, 8) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 6:
        val = pass(leng - 1, 3) % 1234567 + pass(leng - 1, 5) % 1234567 + pass(leng - 1, 9) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 7:
        val = pass(leng - 1, 4) % 1234567 + pass(leng - 1, 8) % 1234567 + pass(leng - 1, 0) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 8:
        val = pass(leng - 1, 5) % 1234567 + pass(leng - 1, 7) % 1234567 + pass(leng - 1, 9) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    case 9:
        val = pass(leng - 1, 6) % 1234567 + pass(leng - 1, 8) % 1234567;
        dp[leng][now] = val % 1234567;
        return dp[leng][now];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[1000][10], -1);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum = (sum % 1234567 + pass(N, i) % 1234567) % 1234567;
        }
        cout << sum << '\n';
    }


}

















#/*include <iostream>
#include <vector>
#define MOD 1234567

using namespace std;

vector<int> ans;

vector<vector<int>> dial = {
    {7}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7},
    {2, 4, 6, 8}, {3, 5, 9}, {4, 8, 0}, {5, 7, 9}, {6, 8}
};

int res = 0;

void dfs(int length, int startnum, int currentLength)
{

    if (currentLength == length)
    {
        res = (res + 1) % MOD;
        return;
    }

    for (int i = 0; i < dial[startnum].size(); ++i)
    {
        int nextnum = dial[startnum][i];
        dfs(length, nextnum, currentLength + 1);
    }
}

int main() {
    int tc, PwLength;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        cin >> PwLength;
        res = 0; // 결과 초기화
        for (int num = 0; num <= 9; ++num) { // 모든 숫자에서 시작
            dfs(PwLength, num, 1);
        }

        ans.push_back(res);
    }

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }

    return 0;
}*/


//실패 원인

// 나머지 처리를 깜빡함
// dfs를 나름 비슷하게 구현하려 했지만, 아직 익숙하지 않은듯