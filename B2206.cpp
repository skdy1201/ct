#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int row, col;
vector<vector<int>> Matrix;

struct Node
{
    int x, y, dist, change;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs()
{
    vector<vector<vector<bool>>> visited(row, vector<vector<bool>>(col, vector<bool>(2, false)));
    queue<Node> q;
    q.push({ 0, 0, 1, 1 }); // 시작 위치, 거리 1, 변경 가능 횟수 1

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        if (current.x == row - 1 && current.y == col - 1)
        {
            return current.dist;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < row && ny >= 0 && ny < col)
            {
                if (Matrix[nx][ny] == 0 && !visited[nx][ny][current.change])
                {
                    visited[nx][ny][current.change] = true;
                    q.push({ nx, ny, current.dist + 1, current.change });
                }
                else if (Matrix[nx][ny] == 1 && current.change > 0 && !visited[nx][ny][current.change - 1])
                {
                    visited[nx][ny][current.change - 1] = true;
                    q.push({ nx, ny, current.dist + 1, current.change - 1 });
                }
            }
        }
    }

    return -1; // 경로를 찾지 못한 경우
}

int main()
{
    cin >> row >> col;

    Matrix.resize(row, vector<int>(col));
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            char input;
            cin >> input;
            Matrix[i][j] = input - '0';
        }
    }

    cout << bfs() << endl;

    return 0;
}


