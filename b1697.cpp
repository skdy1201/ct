/*#include <iostream>

using namespace std;



int n;
int k;

int MoveCheck(int start, int target)
{
	// 결과 변수
	int res = 0;

	//k/2 지점 먼저 구해두기
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


			//2배한 값이 작다면, 윈도우 사이라면
			if (start * 2 >= (target-1) && start * 2 <= (target + 1) || start * 2 < target)
			{
				start = start * 2;

			}
			else if (start < SubGoal) // *2를 했을때 가장 많이 이동할 수있으니 절반 지점을 찾아야한다.
			{
					++start;

			}
			else if (start > SubGoal)// *2를 했을때 가장 많이 이동할 수있으니 절반 지점을 찾아야한다.
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
// 고 백 점프
//==================

곱하기의 이동량이 제일 많으므로,
제일 적게 움직이려면 *를 많이 써야한다.

1.k/2 지점 찾기
2.2x > k이며, 2x - k = 1이면 -1
2x -k = -1이면 +1


5  17
초기 값.

17/2 = 8..1

홀수는 바로 *2해서 갈 수가 없다.
16이나 18을 갈 수 있다.

또한 나눈 수가 x보다 크다면 2x 이상의 범위


10 17
2x가 k보다 크니 지점을 넘어버린것.
또한 2x - 17 = 3이니까 3칸 더 넘어간 것
넘어 갔으니 뒤로 한칸

9 / 17
2x가 k보다 크니 지점을 넘어섰다.
그런데 2x - 17 = 1

18 / 17
-1
을 해준다.


2x 와 k를 먼저 비교하고 행동이 정해진다.

12 5
10 14

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001; // 최대 위치

int BFS(int N, int K) {
	vector<int> time(MAX, -1); // 각 위치에 도달하는 데 걸린 시간을 저장
	queue<int> q;

	time[N] = 0; // 시작 위치의 시간 초기화
	q.push(N);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == K) {
			return time[current]; // 동생의 위치에 도달한 경우
		}

		// 다음 위치 탐색
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

	return -1; // 이 코드는 실행되지 않아야 함
}

int main() {
	int N, K;
	cin >> N >> K;


	cout << BFS(N, K) << endl;

	return 0;
}