#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int unlistencount;
	int unwatchedcount;

	cin >> unlistencount >> unwatchedcount;

	vector<string> NoListened;
	vector<string> NoWatched;

	vector<string> result;

	for (int i = 0; i < unlistencount; ++i)
	{
		string temp;
		cin >> temp;

		NoListened.push_back(temp);
	}

	for (int j = 0; j < unwatchedcount; ++j)
	{
		string temp;
		cin >> temp;

		NoWatched.push_back(temp);
	}

	sort(NoListened.begin(), NoListened.end());
	sort(NoWatched.begin(), NoWatched.end());

	int i = 0;
	int j = 0;

	while (i < unlistencount && j < unwatchedcount)
	{
		if (NoListened[i] == NoWatched[j])
		{
			result.push_back(NoListened[i]);
			++i;
			++j;
		}
		else if (NoListened[i] < NoWatched[j])
		{
			++i;
		}
		else
		{
			++j;
		}
	}



	cout << result.size() << endl;



	for (int c = 0; c < result.size(); ++c)
	{
		cout << result[c] << endl;
	}

	return 0;
}