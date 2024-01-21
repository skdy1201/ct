#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int treecount;
int NeedLengh;
int treetall;
vector<int> treetalls;

void input()
{
	cin >> treecount >> NeedLengh;
	
	for (int i = 0; i < treecount; ++i)
	{
		cin >> treetall;
		treetalls.push_back(treetall);
	}
}

int GetMaxHeight(int treecount, vector<int> treetalls)
{
	sort(treetalls.begin(), treetalls.end());

	int left = treetalls[0];
	int right = treetalls[treetalls.size() - 1];
	int Cutheight =(left + right) / 2;

	int result = 0;

	while(result != NeedLengh)
	{ 

		for (int j = 0; j < treetalls.size(); ++j)
		{
			if (treetalls[j] - Cutheight > 0);
				result += treetalls[j] - Cutheight;

		}

		if (result == NeedLengh)
		{
			cout<< Cutheight;
			return Cutheight;
		}
		else
		{
			if (result < NeedLengh)
			{
				++Cutheight;
			}
			else
			{
				--Cutheight;
			}
		}
	}
}

int main()
{

	input();

	GetMaxHeight(0, treetalls);

	return 0;

}

/*
* 4  / 7
* 20 15 10 17
*10 15 17 20
*
* 15
*
*
*
* 0 += 5
* 5 += 2
*
*
* 5 / 20
* 4 26 40 42 46
*
* 25
*
* 0 1 15 17  21
* 54
*
*
*
*
*
*
* */