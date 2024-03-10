#include <iostream>
#include <vector>

using namespace std;



int main()
{

	int N; //¹Ù±¸´Ï °¹¼ö
	int M; //°ø °¹¼ö

	cin >> N >> M;

	vector<int> basket;

	basket.resize(N + 1, 0);

	for (int z = 0; z < M; ++z)
	{

		int i, j, k;


		cin >> i >> j >> k;

		for (int x = i; x <= j; ++x)
		{
			basket[x] = k;
		}

	}

	for (int i = 1; i < N + 1; ++i)
	{
		cout << basket[i] << " ";
	}

	return 0;
}