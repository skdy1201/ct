#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>


using namespace std;

int N;

vector<vector<int>>  map;
vector<vector<bool>> visited;

vector<int> ans;


void printArr(vector<vector<bool>>& check) {
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==========================================" << endl;
}

int bfs(vector<vector<int>>& map, vector<vector<bool>>& check, int startx, int starty)
{
	int res = 1;

	int x[4] = { 0, 0, 1, -1 };
	int y[4] = { 1, -1, 0, 0 };

	pair<int, int> start = { startx, starty };
	queue<pair<int, int>> q;

	check[startx][starty] = true;

	q.push(start);

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			if (temp.first + x[i] >= 0 && temp.second + y[i] >= 0
				&& temp.first + x[i] < N && temp.second + y[i] < N
				&& map[temp.first + x[i]][temp.second + y[i]] == 1
				&& check[temp.first + x[i]][temp.second + y[i]] == false)
			{
				pair<int, int> next = make_pair(temp.first + x[i], temp.second + y[i]);
				q.push(next);
				check[next.first][next.second] = true;
				++res;
				printArr(visited);
			}
		}
	}

	return res;


}

int main()
{
	cin >> N;

	map.resize(N, vector<int>(N, 0));
	visited.resize(N, vector<bool>(N, 0));

	for (int i = 0; i < N; ++i)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < N; ++j)
		{
			if (temp[j] == '1')
			{
				map[i][j] = 1;
			}
		}
	}

	printArr(visited);

	for (int z = 0; z < N; ++z)
	{
		for (int x = 0; x < N; ++x)
		{
			if (map[z][x] == 1 && visited[z][x] == false)
			{
				int one = bfs(map, visited, z, x);
				ans.push_back(one);
			}
		}
	}

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}