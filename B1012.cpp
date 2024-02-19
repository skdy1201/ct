#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;

int casecount;
int M; // 가로
int N; // 세로
int K;
pair<int, int> coord;
vector<pair<int, int>> ground;

void printArr(vector<vector<bool>>& check) {
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==========================================" << endl;
}

void bfs(int i, int j, vector<vector<int>>& grass, vector<vector<bool>>& check) {
	int xdir[4] = { -1, 1, 0, 0 };
	int ydir[4] = { 0, 0, -1, 1 };

	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true; // 올바른 방문 표시

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int nextX = temp.first + xdir[d];
			int nextY = temp.second + ydir[d];

			// 배열 범위 검사 추가
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (grass[nextX][nextY] == -2 && !check[nextX][nextY]) {
					q.push(make_pair(nextX, nextY));
					check[nextX][nextY] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> casecount;

	vector<int> ans;

	while (casecount--)
	{
		// 기본 세팅
		//int grass[50][50]{ 0 };
		//bool visited[50][50]{ 0 };
		vector<vector<int>> grass;
		vector<vector<bool>> visited;

		int bug = 0;

		cin >> M >> N >> K;

		grass.resize(N, vector<int>(M, 0));
		visited.resize(N, vector<bool>(M, false));



		for (int j = 0; j < K; ++j)
		{
			cin >> coord.second >> coord.first;
			ground.push_back(coord);
		}

		// 배추 심기
		for (int i = 0; i < K; ++i)
		{
			grass[ground[i].first][ground[i].second] = -2;
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (grass[i][j] == -2 && visited[i][j] == false)
				{
					bfs(i, j, grass, visited);
					++bug;
					printArr(visited);
				}

			}
		}

		ans.push_back(bug);
		bug = 0;

		vector<pair<int, int>> temp;
		ground.swap(temp);

	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}