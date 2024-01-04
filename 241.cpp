#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        //��� ����
        vector<int> result;
        
        //���ڿ� ������
        int size = input.size();
        
        
        for (int i = 0; i < size; i++) 
        {
            //���� ���ڸ� �ִ´�.
            char cur = input[i];
            
            //���� ���ڰ� �����ڶ��
            if (cur == '+' || cur == '-' || cur == '*') 
            {
            
                // �����ڸ� �������� �� �ڸ� �ɰ���.(0 ~ i��°����)
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                
                //substr�� ���ڰ� ���ٴ� ���� �ش� �κк��� ������ ����
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                
                //auto�ݺ���
                //vec1���� ������ ���� ���� ����, vec2���� ������ ���� ������ ����
                // cur�� �ִ� �����ڿ� ���� ������ ���� res vec�� �ִ´�.
                for (auto n1 : result1) 
                {
                    
                    for (auto n2 : result2) 
                    {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // ���� �ݺ����� ��ġ�� �ʰ� ����� ����ִٸ�, ���ڸ� ��������ϱ�, atoi�� ���ڿ��� ���ڷ� �ٲ㼭 �ְ� ��ȯ
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};

//��ͷ� �ں��� �ɰ��� �ö�´�.
//2 -1 -1�̶��
// 2�� ���� 1-1�� �ٽ� ����
// 2 - (1-1)�� ����� �Ѵ�.
//
// �� ����� vec�� ��´�.

//�׸��� ���� ū for������ �ٽ� �ݺ��� �ϸ� 1�� ����
// 2-1�� 1�� ����� �ٽ� ����
// // �׷��� 0�� ���´�.
// ������ ����� �߰�

//�׸��� �ٽ� �ݺ��� ���Ƽ� 1�� ������
//result�� �̹� ����� �ֱ⶧���� �߰����� �ʰ� �ݸ��� �����ϸ�  return�ȴ�.

int main()
{

    string s = "2-1-1";

    Solution q;

    vector<int> a = q.diffWaysToCompute(s);


    int w = 0;


    return 0;
}