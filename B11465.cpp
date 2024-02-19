#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n; // �� ��ȣ�� ����
int k; // �������� �ΰ� ���� ��ȣ�� ����
int b; // ���峭 ��ȣ�� ����

vector<int> broken; // ���峭 ��ȣ�� ��ȣ ����Ʈ

int fix = 100000;

void input()
{
	cin >> n;
	cin >> k;
	cin >> b;


	for (int i = 0; i < b; ++i)
	{
		int temp;
		cin >> temp;
		broken.push_back(temp);
	}

}

void countfix(vector<int> _count)
{
	deque<int> window;
	int temp = 0;
	int lastidx;

	for (int i = 0; i < k; ++i)
	{
		window.push_back(_count[i]);

		if (_count[i] == -1)
			++temp;
	}

	fix = min(temp, fix);
	lastidx = k;

	while (lastidx < n)
	{
		//temp = fix;

		if (window.front() == -1)
			--temp;

		window.pop_front();

		if (_count[lastidx] == -1)
			++temp;


		window.push_back(_count[lastidx]);



		fix = min(temp, fix);
		++lastidx;
	}


}



int main()
{
	input();

	vector<int> fullnum;

	fullnum.resize(n, 0);

	for (int i = 0; i < broken.size(); ++i)
	{
		fullnum[broken[i] - 1] = -1;
	}

	countfix(fullnum);

	cout << fix << endl;

	return 0;
}