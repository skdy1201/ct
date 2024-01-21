#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int S(int n, vector<int> a, vector<int> b)
{
	int ans = 0;

	// 두번째 배열을 건드리지 않고 새로 만든다. 내림차순으로
	priority_queue<int, vector<int>> pq;

	// 첫번째 벡터 정렬
	sort(a.begin(), a.end());

	// 반복문을 통해 저장
	for (int i = 0; i < n; ++i)
	{
		pq.push(b[i]);
	}

	//가장 작은 수와 가장 큰수를 차래대로 곱셈.
	for (int j = 0; j < n; ++j)
	{
		ans += a[j] * pq.top();
		pq.pop();
	}
	
	//출력
	cout << ans << endl;

	return ans;

}


int main()
{

	int n = 9;

	vector<int> a = { 5, 15, 100, 31, 39, 0, 0, 3, 26 };
	vector<int> b = { 11, 12, 13, 2, 3, 4, 5, 9, 1 };

	int c = S(n, a, b);

	return 0;
}