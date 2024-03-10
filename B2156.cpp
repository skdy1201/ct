#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//연속 두 잔을 마실 수 있다.
// 3번째부터 마시느냐 안마시느냐로 나눠진다.
// 그러니 4번째부터 기준을 나눌 수 있다.
// 1,2 , 4 를 마시는 경우
// 3잔을 마신 경우
// 1 ,3 ,4 잔을 마신경우


int main() {
    int num; // 잔 개수
    cin >> num;

    vector<int> list(num + 1, 0); // 포도주
    for (int i = 1; i <= num; ++i) {
        cin >> list[i];
    }

    vector<int> dp(num + 1, 0); // 최대 포도주
    dp[1] = list[1];
    if (num > 1) {
        dp[2] = list[1] + list[2];
    }

    for (int i = 3; i <= num; ++i) {
        dp[i] = max({ dp[i - 1], dp[i - 2] + list[i], dp[i - 3] + list[i - 1] + list[i] });
    }

    cout << dp[num];

    return 0;
}
