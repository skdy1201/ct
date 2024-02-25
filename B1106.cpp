#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX_N 21
#define MAX_C 1001
#define LL long long
#define INF 1e9

using namespace std;
int C, N;
int Cost[MAX_N], Client[MAX_N];
int DP[MAX_C * 101];

void Input() {
	cin >> C >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Cost[i] >> Client[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {

		int d = 0;

		for (int j = 1; j <= 100000; j++) {
			if (j - Cost[i] >= 0) {
				DP[j] = max(DP[j], DP[j - Cost[i]] + Client[i]);
			}
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= 100000; i++) {
		if (DP[i] >= C) {
			cout << i << "\n";
			break;
		}
	}
}

int main() {
	FASTIO
		Input();
	Settings();
	Find_Answer();

	return 0;
}

//돈 dp를 만들어서 끝까지 담은다음에 업데이트를 했다.
//범위가 한정되어 있어서 이렇게 해도 작동하는듯

//끝까지 한 가격으로 쭉 갱신하고
// 다음 가격으로 같은 dp를 돌면서 새로 들어가는 가격과 추가하는 손님을 더한 값을 idx로 하고 저장

// 3원이라면 idx가 3이 늘 동안은 같은 고객이다.
//새로 들어가는 cost는 현재 idx와 다르게 늘어나니 들어갈 자리에서 새로운 cost에 대한 계산을 해준 값에다
//늘어날 손님을 더한 값이 현재 값보다 큰지 비교하는 것.
