#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int S(int n, vector<int> a, vector<int> b)
{
	int ans = 0;

	// �ι�° �迭�� �ǵ帮�� �ʰ� ���� �����. ������������
	priority_queue<int, vector<int>> pq;

	// ù��° ���� ����
	sort(a.begin(), a.end());

	// �ݺ����� ���� ����
	for (int i = 0; i < n; ++i)
	{
		pq.push(b[i]);
	}

	//���� ���� ���� ���� ū���� ������� ����.
	for (int j = 0; j < n; ++j)
	{
		ans += a[j] * pq.top();
		pq.pop();
	}
	
	//���
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