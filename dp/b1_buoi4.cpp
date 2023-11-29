#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDemand(int n, int l1, int l2, const vector<int>& demands) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int maxVal = demands[i - 1];

        if (i > l1) {
            maxVal = max(maxVal, dp[i - 1]);
        }

        if (i > l2) {
            maxVal = max(maxVal, dp[i - l1 - 1] + demands[i - 1]);
        }

        if (i >= l1 + 1) {
            maxVal = max(maxVal, dp[i - l1 - 1]);
        }

        if (i >= l2 + 1) {
            maxVal = max(maxVal, dp[i - l2 - 1] + demands[i - 1]);
        }

        dp[i] = maxVal;
    }

    return dp[n];
}

int main() {
    int n, l1, l2;
    cin >> n >> l1 >> l2;

    vector<int> demands(n);
    for (int i = 0; i < n; ++i) {
        cin >> demands[i];
    }

    int result = maxDemand(n, l1, l2, demands);
    cout << result << endl;

    return 0;
}
