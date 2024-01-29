#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include <string>
#include <cmath>

using namespace std;

//�Ҽ� üũ
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

//�縰��� üũ
bool CheckPD(int Prime)
{


	// ��Ʈ�� �ϳ�
	string origin = to_string(Prime);

	string Lnum = ""; // ���� �� ��Ʈ��
	string Rnum = ""; // ������ �� ��Ʈ��

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