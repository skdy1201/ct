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

    // 1. 셔틀이 출발하는 시간을 다 구한다.
    int nowTime = 9 * 60; // 첫 시간 세팅
    
    shuttleTime.push_back(nowTime);
    
    for (int i = 0; i < n - 1; i++) 
    {
        nowTime += t;
        shuttleTime.push_back(nowTime);
    }

    // 2. 사람들의 timetable을 오름차순으로 정렬한다.
    vector<int> numberTimeTable;
    
    for (int i = 0; i < timetable.size(); i++) 
    {
        numberTimeTable.push_back(getTime(timetable[i]));
    }
   
    sort(numberTimeTable.begin(), numberTimeTable.end());

    // 3. 각 셔틀에 탈 수 있는 사람(셔틀 시간보다 작거나 같은 사람)을 구한다.
    // (이 때, 콘이 해당 셔틀에 탈 수 있기 위한 최후의 시간을 구해놓는다.)
    // => 이건 '가장 큰 시간 - 1분'이거나, 셔틀에 사람이 꽉 차지 않는다면 '셔틀 출발 시간'이다.
    vector<int> cornTime;
    
    int idx = 0;
    
    for (int i = 0; i < shuttleTime.size(); i++) 
    { // 10
        int shuttle = shuttleTime[i];
        int shuttleWhole = 0;
        int maxTime = 0;
        // *이미 버스에 탄 인원은 제외해주어야 함
        // *셔틀에 m명 이상 못 타게 해야 함
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
        { // 셔틀 자리 남음
            cornTime.push_back(shuttle);
        }
        else 
        { // 자리 없으면 가장 큰 시간 - 1
            cornTime.push_back(maxTime - 1);
        }
    }

    // 4. 각 셔틀에서의 최후 시간 중 가장 최후 시간을 고른다.
    sort(cornTime.begin(), cornTime.end());
    answer = getTimeString(cornTime.back());

    return answer;
}