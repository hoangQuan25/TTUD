#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's algorithm
int findMaxSubarraySum(const vector<int>& a) {
    int n = a.size();
    int max_sum = a[0];
    int cur_sum = a[0];

    for (int i = 1; i < n; i++) {
        cur_sum = max(a[i], cur_sum + a[i]);
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}

// Function to read input
vector<int> readInput() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    return a;
}

int main() {
    vector<int> a = readInput();
    int result = findMaxSubarraySum(a);
    cout << result << endl;

    return 0;
}

