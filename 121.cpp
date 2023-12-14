#include <vector>
using std::vector;


int maxProfit(vector<int>& prices) {

    //���� ����, 
    int Dailymaxprofit = -1;

    //��¥ ����
    vector<int> day;

    //��¥ ��Ƶα�
    for (int i = 0; i < prices.size(); ++i)
    {
        day.push_back(i);
    }


    //��¥��ŭ �ݺ�
    for (int i = 0; i < day.size(); ++i)
    {
        //j�� ������ ���� �����ؾ��Ѵ�.
        int j = (i + 1);

        //�� ��¥���� ��� �ִ� ���� ���ϱ�
        while (j < prices.size())
        {
            //i���� �� �ֽ��� j���� ���ݺ��� ũ�ٸ� ������ �����Ƿ�, ��¥�� �ѱ��.
            if (prices[i] > prices[j])
            {
                ++j;


            }
            else//������ ���°��
            {
                if (Dailymaxprofit != -1 && prices[j] - prices[i] > Dailymaxprofit) // �̹� �� ������ �ִµ�, ���ο� ������ �� ū ��� ����
                {
                    Dailymaxprofit = prices[j] - prices[i];
                    
                }
                else if (Dailymaxprofit == -1 && prices[j] - prices[i] > Dailymaxprofit)//����� ������ ���µ�, ������ ����ٸ�
                {
                    Dailymaxprofit = prices[j] - prices[i];

                    if (day.size() == 2 && prices[j] - prices[i] > 0) // 2�Ϲۿ� ���µ� ������ ���ٸ�
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

        //���� ����, 
        int Dailymaxprofit = -1;

        //�� ��¥���� ����ִ� ����
        int OnedayMaxprofit = -1;

        //������ ���� ū ��
        int Maxday;

        //��¥ ����
        vector<int> day;

        //��¥ ��Ƶα�
        for (int i = 0; i < prices.size(); ++i)
        {
            day.push_back(i);
        }

        //��¥��ŭ �ݺ�
        for (int i = 0; i < day.size(); ++i)
        {
            //j�� ������ ���� �����ؾ��Ѵ�.
            int j = (i + 1);

            //�� ��¥���� ��� �ִ� ���� ���ϱ�
            while (j < prices.size())
            {
                //i���� �� �ֽ��� j���� ���ݺ��� ũ�ٸ� ������ �����Ƿ�, ��¥�� �ѱ��.
                if (prices[i] > prices[j])
                {
                    ++j;
                }
                else//������ ���°��
                {
                    if (Dailymaxprofit != -1 && prices[j] - prices[i] > Dailymaxprofit) // �̹� �� ������ �ִµ�, ���ο� ������ �� ū ��� ����
                    {
                        Dailymaxprofit = prices[j] - prices[i];
                        Maxday = j;
                    }
                    else//����� ������ ���ٸ� �ִ´�.
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