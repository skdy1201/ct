/*#include <iostream>

using namespace std;



int n;
int k;

int MoveCheck(int start, int target)
{
	// ��� ����
	int res = 0;

	//k/2 ���� ���� ���صα�
	int SubGoal = target / 2;

	while(true)
	{
		if (target - start == 1)
		{
			++start;
		}
		else if (target - start == -1)
		{
			--start;
		}
		else
		{


			//2���� ���� �۴ٸ�, ������ ���̶��
			if (start * 2 >= (target-1) && start * 2 <= (target + 1) || start * 2 < target)
			{
				start = start * 2;

			}
			else if (start < SubGoal) // *2�� ������ ���� ���� �̵��� �������� ���� ������ ã�ƾ��Ѵ�.
			{
					++start;

			}
			else if (start > SubGoal)// *2�� ������ ���� ���� �̵��� �������� ���� ������ ã�ƾ��Ѵ�.
			{
					--start;

			}


		}

		++res;

		if (target == start)
		{
			return res;
		}

	}
}


int main()
{
	cin >> n;
	cin >> k;


	int c =MoveCheck(n, k);

	cout << k;

	return 0;
}



//==================
// �� �� ����
//==================

���ϱ��� �̵����� ���� �����Ƿ�,
���� ���� �����̷��� *�� ���� ����Ѵ�.

1.k/2 ���� ã��
2.2x > k�̸�, 2x - k = 1�̸� -1
2x -k = -1�̸� +1


5  17
�ʱ� ��.

17/2 = 8..1

Ȧ���� �ٷ� *2�ؼ� �� ���� ����.
16�̳� 18�� �� �� �ִ�.

���� ���� ���� x���� ũ�ٸ� 2x �̻��� ����


10 17
2x�� k���� ũ�� ������ �Ѿ������.
���� 2x - 17 = 3�̴ϱ� 3ĭ �� �Ѿ ��
�Ѿ� ������ �ڷ� ��ĭ

9 / 17
2x�� k���� ũ�� ������ �Ѿ��.
�׷��� 2x - 17 = 1

18 / 17
-1
�� ���ش�.


2x �� k�� ���� ���ϰ� �ൿ�� ��������.

12 5
10 14

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001; // �ִ� ��ġ

int BFS(int N, int K) {
	vector<int> time(MAX, -1); // �� ��ġ�� �����ϴ� �� �ɸ� �ð��� ����
	queue<int> q;

	time[N] = 0; // ���� ��ġ�� �ð� �ʱ�ȭ
	q.push(N);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == K) {
			return time[current]; // ������ ��ġ�� ������ ���
		}

		// ���� ��ġ Ž��
		int next = current * 2;
		if (next < MAX && time[next] == -1) {
			time[next] = time[current] + 1;
			q.push(next);
		}

		next = current - 1;
		if (next >= 0 && time[next] == -1) {
			time[next] = time[current] + 1;
			q.push(next);
		}

		next = current + 1;
		if (next < MAX && time[next] == -1) {
			time[next] = time[current] + 1;
			q.push(next);
		}
	}

	return -1; // �� �ڵ�� ������� �ʾƾ� ��
}

int main() {
	int N, K;
	cin >> N >> K;


	cout << BFS(N, K) << endl;

	return 0;
}