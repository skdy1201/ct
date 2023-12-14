#include <vector>
using std::vector;


int maxProfit(vector<int>& prices) {

    //일일 수익, 
    int Dailymaxprofit = -1;

    //날짜 벡터
    vector<int> day;

    //날짜 담아두기
    for (int i = 0; i < prices.size(); ++i)
    {
        day.push_back(i);
    }


    //날짜만큼 반복
    for (int i = 0; i < day.size(); ++i)
    {
        //j는 다음날 부터 시작해야한다.
        int j = (i + 1);

        //한 날짜에서 얻는 최대 수익 구하기
        while (j < prices.size())
        {
            //i날에 산 주식이 j날의 가격보다 크다면 수익이 없으므로, 날짜를 넘긴다.
            if (prices[i] > prices[j])
            {
                ++j;


            }
            else//수익이 나는경우
            {
                if (Dailymaxprofit != -1 && prices[j] - prices[i] > Dailymaxprofit) // 이미 전 수익이 있는데, 새로운 수익이 더 큰 경우 갱신
                {
                    Dailymaxprofit = prices[j] - prices[i];
                    
                }
                else if (Dailymaxprofit == -1 && prices[j] - prices[i] > Dailymaxprofit)//담겨진 수익이 없는데, 수익이 생긴다면
                {
                    Dailymaxprofit = prices[j] - prices[i];

                    if (day.size() == 2 && prices[j] - prices[i] > 0) // 2일밖에 없는데 수익이 난다면
                    {
                        Dailymaxprofit = prices[j] - prices[i];
                        break;
                    }
                    else if ((day.size() == 2) && prices[i] == prices[j])
                    {
                        Dailymaxprofit = 0;
                        break;
                    }
                    
                }
                ++j;
            }

        }
    }

    if (Dailymaxprofit == -1)
    {
        return 0;
    }

    return Dailymaxprofit;
}

    int main()
    {
        vector<int>prices = { 1,4,2 };

        int d = maxProfit(prices);

        int c = 0;

        return 0;
    }


/*class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //일일 수익, 
        int Dailymaxprofit = -1;

        //한 날짜에서 얻는최대 수익
        int OnedayMaxprofit = -1;

        //수익이 가장 큰 날
        int Maxday;

        //날짜 벡터
        vector<int> day;

        //날짜 담아두기
        for (int i = 0; i < prices.size(); ++i)
        {
            day.push_back(i);
        }

        //날짜만큼 반복
        for (int i = 0; i < day.size(); ++i)
        {
            //j는 다음날 부터 시작해야한다.
            int j = (i + 1);

            //한 날짜에서 얻는 최대 수익 구하기
            while (j < prices.size())
            {
                //i날에 산 주식이 j날의 가격보다 크다면 수익이 없으므로, 날짜를 넘긴다.
                if (prices[i] > prices[j])
                {
                    ++j;
                }
                else//수익이 나는경우
                {
                    if (Dailymaxprofit != -1 && prices[j] - prices[i] > Dailymaxprofit) // 이미 전 수익이 있는데, 새로운 수익이 더 큰 경우 갱신
                    {
                        Dailymaxprofit = prices[j] - prices[i];
                        Maxday = j;
                    }
                    else//담겨진 수익이 없다면 넣는다.
                    {
                        Dailymaxprofit = prices[j] - prices[i];
                        Maxday = j;
                    }

                }

            }

            return j;

        }



    }
};*/