#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_profit(int saving, vector<int>& currentValue, vector<int>& futureValue) {
    vector<pair<int, int>> items;
    for (size_t i = 0; i < currentValue.size(); ++i) {
        int profit = futureValue[i] - currentValue[i];
        if (profit > 0) {
            items.push_back({currentValue[i], profit});
        }
    }

    vector<int> dp(saving + 1, 0);

    for (auto& item : items) {
        int cost = item.first, profit = item.second;
        for (int w = saving; w >= cost; --w) {
            dp[w] = max(dp[w], dp[w - cost] + profit);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int saving = 250;
    vector<int> currentValue = {175, 133, 109, 210, 97};
    vector<int> futureValue = {200, 125, 128, 228, 133};

    cout << "Maximum Profit: " << max_profit(saving, currentValue, futureValue) << endl;  // Output: 55

    return 0;
}
