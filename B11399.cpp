#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N; // ATM 대기자
vector<int> line; // 인출 대기 목록
vector<int> dp;

int main()
{
	//초기 세팅
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;

		line.push_back(temp);
	}

	sort(line.begin(), line.end());

	dp.resize(N, 0);
	dp[0] = line.front();


	for (int j = 1; j < N; ++j)
	{
		dp[j] = dp[j - 1] + line[j];
	}

	int res = 0;

	for (int l = 0; l < (int)dp.size(); ++l)
	{
		res += dp[l];
	}

	cout << res;


	return 0;
}