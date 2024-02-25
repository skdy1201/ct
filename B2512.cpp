#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateMaxBudget(const vector<int>& requests, int totalBudget) {
    int low = 0, high = *max_element(requests.begin(), requests.end());
    int result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int sum = 0;
        for (int req : requests) {
            sum += min(req, mid);
        }
        if (sum <= totalBudget) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

void distributeBudgetWithBinarySearch(vector<int>& requests, int totalBudget) {
    int maxBudget = calculateMaxBudget(requests, totalBudget);
    cout << maxBudget << endl;
}

int main() {
    int N; // 지방의 수
    cin >> N;
    vector<int> requests(N); // 각 지방의 예산 요청
    for (int i = 0; i < N; ++i) {
        cin >> requests[i];
    }
    int totalBudget; // 총 예산
    cin >> totalBudget;

    distributeBudgetWithBinarySearch(requests, totalBudget);

    return 0;
}



