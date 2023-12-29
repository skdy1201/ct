#include <vector>
using std::vector;

#include<algorithm>
using std::pair;


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<pair<int, vector<int>>> distances;

    for (const auto& point : points) {
        int distance = point[0] * point[0] + point[1] * point[1];
        distances.push_back({ distance, point });
    }

    sort(distances.begin(), distances.end());

    vector<vector<int>> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(distances[i].second);
    }

    return result;
}



