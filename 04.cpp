#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getTime(string timeString) 
{
    auto idx = timeString.find(":");
    int hour = stoi(timeString.substr(0, idx));
    int minute = stoi(timeString.substr(idx + 1, timeString.size()));

    return hour * 60 + minute;
}

string getTimeString(int time) 
{
    string hour = to_string(time / 60);
    string minute = to_string(time % 60);

    if (hour.size() == 1) 
    {
        hour = '0' + hour;
    }
    if (minute.size() == 1) 
    {
        minute = '0' + minute;
    }

    return hour + ":" + minute;
}

string solution(int n, int t, int m, vector<string> timetable) 
{
    string answer = "";
    vector<int> shuttleTime;

    // 1. ��Ʋ�� ����ϴ� �ð��� �� ���Ѵ�.
    int nowTime = 9 * 60; // ù �ð� ����
    
    shuttleTime.push_back(nowTime);
    
    for (int i = 0; i < n - 1; i++) 
    {
        nowTime += t;
        shuttleTime.push_back(nowTime);
    }

    // 2. ������� timetable�� ������������ �����Ѵ�.
    vector<int> numberTimeTable;
    
    for (int i = 0; i < timetable.size(); i++) 
    {
        numberTimeTable.push_back(getTime(timetable[i]));
    }
   
    sort(numberTimeTable.begin(), numberTimeTable.end());

    // 3. �� ��Ʋ�� Ż �� �ִ� ���(��Ʋ �ð����� �۰ų� ���� ���)�� ���Ѵ�.
    // (�� ��, ���� �ش� ��Ʋ�� Ż �� �ֱ� ���� ������ �ð��� ���س��´�.)
    // => �̰� '���� ū �ð� - 1��'�̰ų�, ��Ʋ�� ����� �� ���� �ʴ´ٸ� '��Ʋ ��� �ð�'�̴�.
    vector<int> cornTime;
    
    int idx = 0;
    
    for (int i = 0; i < shuttleTime.size(); i++) 
    { // 10
        int shuttle = shuttleTime[i];
        int shuttleWhole = 0;
        int maxTime = 0;
        // *�̹� ������ ź �ο��� �������־�� ��
        // *��Ʋ�� m�� �̻� �� Ÿ�� �ؾ� ��
        for (; idx < numberTimeTable.size() && shuttleWhole != m; idx++) 
        { // 2000
            if (numberTimeTable[idx] <= shuttle) 
            {
                shuttleWhole++;
                
                if (maxTime < numberTimeTable[idx]) maxTime = numberTimeTable[idx];
            }
            else 
            {
                break;
            }
        }
        if (shuttleWhole < m) 
        { // ��Ʋ �ڸ� ����
            cornTime.push_back(shuttle);
        }
        else 
        { // �ڸ� ������ ���� ū �ð� - 1
            cornTime.push_back(maxTime - 1);
        }
    }

    // 4. �� ��Ʋ������ ���� �ð� �� ���� ���� �ð��� ����.
    sort(cornTime.begin(), cornTime.end());
    answer = getTimeString(cornTime.back());

    return answer;
}