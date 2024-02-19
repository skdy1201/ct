#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;


int main()
{
	priority_queue<int> pq;
	vector<int> res;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (pq.size() > 0)
			{
				res.push_back(pq.top());
				pq.pop();
			}
			else
				res.push_back(0);

		}
		else
		{
			pq.push(temp);
		}
	}

	for (int i = 0; i < (int)res.size(); ++i)
	{

		printf("%d\n", res[i]);
	}


	return 0;
}