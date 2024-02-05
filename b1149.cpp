#include <iostream>
#include <vector>

using namespace std;

int housecount;
vector<int> housecost[100];
int RGB[3];

void input()
{
	cin >> housecount;

	for (int i = 0; i < housecount; ++i)
	{
		cin >> RGB[0] >> RGB[1] >> RGB[2];

		housecost[i] = { RGB[0], RGB[1], RGB[2] };

	}

}

int dp()
{
	vector<int> Indivisulal_cost;
	int res = 0;

	for (int i = 0; i < housecount; ++i)
	{
		int tempcost = 0;

		//최솟값 구하기
		tempcost = min(housecost[i][0], housecost[i][1]);
		tempcost = min(tempcost, housecost[i][2]);

		// 한 집에 대해 최솟값에 맞는 색 넣기
		//첫번째집은 그냥 넣기
		if (Indivisulal_cost.size() == 0)
		{
			if (tempcost == housecost[i][0])
			{
				Indivisulal_cost.push_back(0);
			}
			else if (tempcost == housecost[i][1])
			{
				Indivisulal_cost.push_back(1);
			}
			else
			{
				Indivisulal_cost.push_back(2);
			}
		}
		//첫번째가 아닐땐 이전과 비교하기
		else
		{
			if (tempcost == housecost[i][0])
			{
				//이전 집과 비교
				if (Indivisulal_cost[i - 1] != 0)
				{
					Indivisulal_cost.push_back(0);
				}
				else
				{
					tempcost = min(housecost[i][1], housecost[i][2]);

					if (tempcost == housecost[i][1])
					{
						Indivisulal_cost.push_back(1);
					}
					else
					{
						Indivisulal_cost.push_back(2);
					}
				}
			}
			else if (tempcost == housecost[i][1])
			{

				//이전 집과 비교
				if (Indivisulal_cost[i - 1] != 1)
				{
					Indivisulal_cost.push_back(1);
				}
				else
				{
					tempcost = min(housecost[i][0], housecost[i][2]);

					if (tempcost == housecost[i][0])
					{
						Indivisulal_cost.push_back(0);
					}
					else
					{
						Indivisulal_cost.push_back(2);
					}
				}
			}
			else if (tempcost == housecost[i][2])
			{
				//이전 집과 비교
				if (Indivisulal_cost[i - 1] != 2)
				{
					Indivisulal_cost.push_back(2);
				}
				else
				{
					tempcost = min(housecost[i][0], housecost[i][1]);

					if (tempcost == housecost[i][0])
					{
						Indivisulal_cost.push_back(0);
					}
					else
					{
						Indivisulal_cost.push_back(1);
					}
				}
			}
		}


	}

	for (int i = 0; i < Indivisulal_cost.size(); ++i)
	{
		res += housecost[i][Indivisulal_cost[i]];
	}

	return res;
}

int main()
{
	input();

	int c = dp();

	int d = 0;

	return 0;
}