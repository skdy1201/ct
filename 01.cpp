#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i)
    {
        string temp(n, ' ');
        
        for (size_t j = 0; j < n; j++)
        {
            int ar1 = arr1[i] >> j & 1;

            int ar2 = arr2[i] >> j & 1;

            if (ar1 || ar2)
                temp[(n - 1) - j] = '#';
            else
                temp[(n - 1) - j] = ' ';

        }
      
        
        answer.push_back(temp);
    }

    return answer;
}


int main()
{

    int n = 5;
    vector<int> arr1 = { 9,20,28,18,11 };
    vector<int> arr2 = { 30,1,21,17,28 };

    vector<string> q = solution(n, arr1, arr2);

    for (size_t i = 0; i < q.size(); i++)
    {
        cout << q[i] << endl;
    }
   



    return 0;
}