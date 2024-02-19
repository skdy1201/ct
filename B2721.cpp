#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> n;
vector<int> DP;

void input()
{
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int temp;
		cin >> temp;
		n.push_back(temp);
	}

}

int getT(int n)
{
	int res = 0;

	for (int i = 1; i < n + 1; ++i)
	{
		res += i;
	}


	return res;
}

int dp(int n)
{
	DP.push_back(0);

	int temp = 0;

	for (int i = 1; i <= n; ++i)
	{
		temp = getT(i + 1);

		temp *= i;

		temp += DP[i - 1];

		DP.push_back(temp);

	}
	return temp;


}


int main()
{
	input();
	;
	for (int i = 0; i < n.size(); ++i)
	{
		int d = dp(n[i]);

		DP.clear();

		cout << d << endl;
	}


	return 0;
}