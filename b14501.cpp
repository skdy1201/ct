#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;


int day; // 퇴사일
int result; // 결과
vector<int> term; // 기간
vector<int> pay; // 급여


void input() // 데이터를 넣는 함수
{
	cin >> day; // 일자 넣기
	for (int i = 0; i < day; ++i) // 반복문을 돌면서
	{
		int temp1, temp2; // 임시변수
		cin >> temp1 >> temp2; // 시간, 수익 넣기
		term.push_back(temp1);
		pay.push_back(temp2);
	}
}

void makeResult(int idx, int totalPay) // 결과 반환 함수
{

	if (idx > day) return; // 퇴사일보다 크면 반환


	if (idx == day)  // 퇴사일이라면
	{
		if (totalPay > result) result = totalPay; // 총 수익이 결과보다 크다면 수익 갱신
		return;
	}


	makeResult(idx + term[idx], totalPay + pay[idx]); // 날짜 + 해당 상담의 기간, 총수익 + 해당 상담일의 수익

	makeResult(idx + 1, totalPay);  // 상담을 건너뛰고 총수익
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
1회차 / 3.  10
2회차 / 4, 30
3회차 / 6, 45
4회차 / 7 , 45 return







*/

