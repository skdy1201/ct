#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include <string>
#include <cmath>

using namespace std;

//소수 체크
bool CheckPrimeNum(int num)
{
	if (num == 1)
		return false;

	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false; // CheckPrimeNum(num + 1);
		}
	}

	return true;
}

//펠린드롬 체크
bool CheckPD(int Prime)
{


	// 스트링 하나
	string origin = to_string(Prime);

	string Lnum = ""; // 왼쪽 비교 스트링
	string Rnum = ""; // 오른쪽 비교 스트링

	Lnum = origin;
	Rnum = origin;

	reverse(Rnum.begin(), Rnum.end());


	if (Lnum != Rnum)
		return false;
	else
		return true;
}



int main()
{
	int n;
	cin >> n;


	for (int i = n; ; ++i)
	{
		if (CheckPrimeNum(i) && CheckPD(i))
		{
			cout << i;
			break;
		}
	}

	return 0;
}