#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//���� �� ���� ���� �� �ִ�.
// 3��°���� ���ô��� �ȸ��ô��ķ� ��������.
// �׷��� 4��°���� ������ ���� �� �ִ�.
// 1,2 , 4 �� ���ô� ���
// 3���� ���� ���
// 1 ,3 ,4 ���� ���Ű��


int main() {
    int num; // �� ����
    cin >> num;

    vector<int> list(num + 1, 0); // ������
    for (int i = 1; i <= num; ++i) {
        cin >> list[i];
    }

    vector<int> dp(num + 1, 0); // �ִ� ������
    dp[1] = list[1];
    if (num > 1) {
        dp[2] = list[1] + list[2];
    }

    for (int i = 3; i <= num; ++i) {
        dp[i] = max({ dp[i - 1], dp[i - 2] + list[i], dp[i - 3] + list[i - 1] + list[i] });
    }

    cout << dp[num];

    return 0;
}
