#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;


int day; // �����
int result; // ���
vector<int> term; // �Ⱓ
vector<int> pay; // �޿�


void input() // �����͸� �ִ� �Լ�
{
	cin >> day; // ���� �ֱ�
	for (int i = 0; i < day; ++i) // �ݺ����� ���鼭
	{
		int temp1, temp2; // �ӽú���
		cin >> temp1 >> temp2; // �ð�, ���� �ֱ�
		term.push_back(temp1);
		pay.push_back(temp2);
	}
}

void makeResult(int idx, int totalPay) // ��� ��ȯ �Լ�
{

	if (idx > day) return; // ����Ϻ��� ũ�� ��ȯ


	if (idx == day)  // ������̶��
	{
		if (totalPay > result) result = totalPay; // �� ������ ������� ũ�ٸ� ���� ����
		return;
	}


	makeResult(idx + term[idx], totalPay + pay[idx]); // ��¥ + �ش� ����� �Ⱓ, �Ѽ��� + �ش� ������� ����

	makeResult(idx + 1, totalPay);  // ����� �ǳʶٰ� �Ѽ���
}

void printResult() {
	cout << result << "\n";
}

int main() 
{
	//input();

	//makeResult(0, 0);
	
	day = 7;

	term = { 3,   5,   1,   1,   2,   4,    2 };

	pay = {  10,  20,  10,  20,  15,  40,  200 };

	printResult();	
}
/*
1ȸ�� / 3.  10
2ȸ�� / 4, 30
3ȸ�� / 6, 45
4ȸ�� / 7 , 45 return







*/

