#include <iostream>
#include <vector>

using namespace std;

// song - �뷡 ��, Stime - �뷡 �Ѱ� �ð�, Ctime - ��ȭ ���� ����

int song;
int Stime;
int Ctime;


void input()
{
	cin >> song >> Stime >> Ctime;
}

int main()
{

	input();

	vector<bool>albumtimeline;

	//visible album
	for (int i = 0; i < song; ++i)
	{
		for (int j = 0; j < Stime; ++j)
		{
			albumtimeline.push_back(true);
		}

		for (int l = 0; l < 5; ++l)
		{
			if (i != song - 1)
			{
				albumtimeline.push_back(false);
			}
		}
	}


	//�ð� üũ
	int check = Ctime;

	while (true)
	{

		if (check > albumtimeline.size())
		{
			break;
		}


		if (albumtimeline[check] == false)
		{
			break;
		}
		else
		{
			check += Ctime;
		}

	}


	cout << check;

	return 0;
}