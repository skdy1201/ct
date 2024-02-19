#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int				n;
vector<char>	p;


void input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char temp;
		cin >> temp;
		p.push_back(temp);
	}

}




int main()
{
	input();

	int snum = 0;
	int lnum = 0;

	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == 'S')
		{
			++snum;
		}
	}

	lnum = p.size() - snum;

	++snum;
	lnum /= 2;

	if (n <= snum + lnum)
		cout << n;
	else
		cout << (snum + lnum);

	return 0;
}