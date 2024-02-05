#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int Comcount;
int link;

int first;
int second;
pair<int, int> LinkCom;
pair<int, int> ComArray[100];


void input()
{
	cin >> Comcount;
	cin >> link;

	for (int i = 0; i < link; ++i)
	{
		cin >> LinkCom.first >> LinkCom.second;
		ComArray[i] = LinkCom;
		cin >> ComArray[i].first >> ComArray[i].second;
	}

}

int bfs()
{
	int linknum1 = 0;
	int visited[100]{ 0 };
	queue<int> q;
	vector<pair<int, int>> templink;

	sort(ComArray, ComArray + link);


	q.push(ComArray[0].first);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (int i = 0; i < link; ++i)
		{
			if (ComArray[i].first == temp && visited[ComArray[i].second] != -1)
			{
				q.push(ComArray[i].second);
			}
			else if (ComArray[i].first > temp)
			{
				break;
			}
		}

		if (visited[temp] == 0)
		{
			++linknum1;
			visited[temp] = -1;
		}

	}


	return linknum1 - 1;
}

int main()
{
	input();

	int res = bfs();

	cout << res;

	return 0;
}