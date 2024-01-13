#include <string>
#include <vector>

#include <iostream>
#include <vector>

using namespace std;


int solution(string dartResult) {
    int answer = 0;

    vector<int> Nums = {};
    vector<char> pow = {};
    vector<char> Operator = {};

    for (size_t i = 0; i < dartResult.size(); i++) {
        // ���� ó��
        if (isdigit(dartResult[i])) {
            int num = dartResult[i] - '0';

            // 10 ó��
            if (num == 1 && dartResult[i + 1] == '0') {
                num = 10;
                ++i;
            }

            Nums.push_back(num);
        }

        // S, D, T ó��
        if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            pow.push_back(dartResult[i]);
        }

        // *, # ó��
        if (dartResult[i] == '*' || dartResult[i] == '#') {
            Operator.push_back(dartResult[i]);
        }
    }

    // ���
    for (size_t i = 0; i < Nums.size(); i++) {
        int num = Nums[i];

        // ���� ���
        if (pow[i] == 'D') {
            num = num * num;
        }
        else if (pow[i] == 'T') {
            num = num * num * num;
        }

        // �ɼ� ���
        if (!Operator.empty()) {
            char op = Operator[i];

            if (op == '*') {
                num *= 2;
                if (i > 0) {
                    Nums[i - 1] *= 2;
                }
            }
            else if (op == '#') {
                num *= -1;
            }
        }

        answer += num;
    }

    return answer;
}

int main() {
    string dartResult = "1D2S#10S";
    cout << solution(dartResult) << endl;  // ���: 9

    return 0;
}
