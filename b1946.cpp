#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int t;
int n;
int f;
int s;

int GetPass(vector<pair<int, int>> grades)
{
	int result = 1;
	sort(grades.begin(), grades.end());

	int bestInterviewRank = grades[0].second;

	for (int i = 1; i < grades.size(); ++i)
	{
		if (grades[i].second < bestInterviewRank)
		{
			++result;
			bestInterviewRank = grades[i].second;
		}
	}

	return result;
}


int main()
{
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> grades;

		for (int i = 0; i < n; ++i)
		{
			int f, s;
			cin >> f >> s;
			grades.push_back(pair<int, int>(f, s));
		}

		cout << GetPass(grades) << endl;
	}


	return 0;
}