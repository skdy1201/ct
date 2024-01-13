#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    string memo = "";
    int count = 0;

    vector<string>memo1;
    vector<string>memo2;
    vector<string>memo3;

    for (int i = 0; i < str1.length(); i++) 
    {
        if (isalpha(str1[i])) 
        {
            str1[i] = toupper(str1[i]);
            memo += str1[i];
        }
        else 
        {
            memo = "";
        }
        if (memo.length() == 2) 
        {
            memo1.push_back(memo);
            memo = str1[i];
        }
    }

    memo = "";

    for (int i = 0; i < str2.length(); i++) 
    {
        if (isalpha(str2[i])) 
        {
            str2[i] = toupper(str2[i]);
            memo += str2[i];
        }
        else 
        {
            memo = "";
        }
        if (memo.length() == 2) {
            memo2.push_back(memo);
            memo = str2[i];
        }
    }

    count = memo1.size() + memo2.size();
    int index1 = 0;
    int index2 = 0;


    while (true) 
    {
        if (index1 == memo1.size()) 
        {
            break;
        }

        if (memo1[index1] == memo2[index2]) 
        {
            memo3.push_back(memo1[index1]);
            memo1.erase(memo1.begin() + index1);
            memo2.erase(memo2.begin() + index2);
            index2 = 0;
        }
        else 
        {

            if (index2 == memo2.size()) 
            {
                index2 = 0;
                index1 += 1;
            }
            else 
            {
                index2 += 1;
            }

        }
    }

    if (memo1.size() + memo2.size() == 0) 
    {
        return 65536;
    }

    count = count - memo3.size();
    answer = floor((memo3.size() * 65536 / count));

    return answer;
}


int main()
{
    string str1 = "aa1+aa2";

    string str2 = "AAAA12";

    int d = solution(str1, str2);

    int z = 0;

    return 0;
}





