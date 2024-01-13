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
        // 箭磊 贸府
        if (isdigit(dartResult[i])) {
            int num = dartResult[i] - '0';

            // 10 贸府
            if (num == 1 && dartResult[i + 1] == '0') {
                num = 10;
                ++i;
            }

            Nums.push_back(num);
        }

        // S, D, T 贸府
        if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            pow.push_back(dartResult[i]);
        }

        // *, # 贸府
        if (dartResult[i] == '*' || dartResult[i] == '#') {
            Operator.push_back(dartResult[i]);
        }
    }

    // 拌魂
    for (size_t i = 0; i < Nums.size(); i++) {
        int num = Nums[i];

        // 力蚌 拌魂
        if (pow[i] == 'D') {
            num = num * num;
        }
        else if (pow[i] == 'T') {
            num = num * num * num;
        }

        // 可记 拌魂
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
    cout << solution(dartResult) << endl;  // 免仿: 9

    return 0;
}
