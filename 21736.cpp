
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int res = 0;
char map[601][601]; // map ����
int visited[601][601]; // �湮 ���� üũ
pair<int, int> I_pos; // ������ ��ġ

// ���� �迭(�����¿�)
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// BFS (�ʺ� �켱 Ž��) �˰���
void bfs()
{
	// �������� queue�� ���� (������ : �������� ��ġ)
	queue<pair<int, int>> q;
	q.push(I_pos);
	visited[I_pos.first][I_pos.second] = 1; // �湮 ���� üũ

	// �� �̻� �� ������ ���� �� ���� ���� �ݺ�
	while (!q.empty())
	{
		// ���� ��ġ
		pair<int, int> cur = q.front();
		q.pop();

		// ���� �迭(dy[], dx[])�� ���� �����¿� üũ
		for (int i = 0; i < 4; i++)
		{
			// �̵��� ��ġ
			pair<int, int> next = { cur.first + dy[i], cur.second + dx[i] };

			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue; // map ���� ��� ���, ��ŵ
			if (map[next.first][next.second] == 'X') continue; // ���� ���, ��ŵ
			if (visited[next.first][next.second] == 1) continue; // �̹� �湮�� ��ġ�� ���, ��ŵ

			if (map[next.first][next.second] == 'P') res++; // �ش� ��ġ�� ����� ���� ���, ī����

			// ���� ��ġ ���� �� �湮 ���� üũ
			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ķ�۽� ũ�� �Է�
	cin >> N >> M;

	// ķ�۽� ���� �Է�
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];

			// �������� ��ġ ����
			if (map[y][x] == 'I')
			{
				I_pos.first = y;
				I_pos.second = x;
			}
		}
	}

	// BFS �˰����� ���� �����̰� ���� �� �ִ� ����� �� ���
	bfs();

	// �����̰� ���� �� �ִ� ����� ���� ��� 
	// �ƹ��� ������ ������ ���, TT�� ���
	if (res == 0) cout << "TT";
	else cout << res;

	return 0;
}


4. ������ ������ �˰���
1) BFS �˰���(�ʺ� �켱 Ž��)
// BFS (�ʺ� �켱 Ž��) �˰���
void bfs()
{
	// �������� queue�� ���� (������ : �������� ��ġ)
	queue<pair<int, int>> q;
	q.push(I_pos);
	visited[I_pos.first][I_pos.second] = 1; // �湮 ���� üũ

	// �� �̻� �� ������ ���� �� ���� ���� �ݺ�
	while (!q.empty())
	{
		// ���� ��ġ
		pair<int, int> cur = q.front();
		q.pop();

		// ���� �迭(dy[], dx[])�� ���� �����¿� üũ
		for (int i = 0; i < 4; i++)
		{
			// �̵��� ��ġ
			pair<int, int> next = { cur.first + dy[i], cur.second + dx[i] };

			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue; // map ���� ��� ���, ��ŵ
			if (map[next.first][next.second] == 'X') continue; // ���� ���, ��ŵ
			if (visited[next.first][next.second] == 1) continue; // �̹� �湮�� ��ġ�� ���, ��ŵ

			if (map[next.first][next.second] == 'P') res++; // �ش� ��ġ�� ����� ���� ���, ī����

			// ���� ��ġ ���� �� �湮 ���� üũ
			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
}

