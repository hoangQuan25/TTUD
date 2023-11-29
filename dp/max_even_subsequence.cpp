#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Hàm tìm đoạn con có tổng giá trị là số chẵn lớn nhất
vector<int> findMaxEvenSubarray(const vector<int>& arr) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, INT_MIN));
    int maxEvenSum = INT_MIN;
    int endIndex = -1;

    for (int i = 1; i <= n; ++i) {
        int currentElement = arr[i - 1];

        // Cập nhật dp[i][0] là tổng chẵn lớn nhất khi không bao gồm phần tử thứ i
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        // Cập nhật dp[i][1] là tổng chẵn lớn nhất khi bao gồm phần tử thứ i
        if (currentElement % 2 == 0) {
            dp[i][1] = max(dp[i - 1][0] + currentElement, currentElement);
        } else {
            dp[i][1] = dp[i - 1][0]; // Nếu phần tử thứ i là số lẻ, không cộng vào tổng chẵn
        }

        // Cập nhật maxEvenSum và endIndex nếu có sự cải thiện
        if (dp[i][0] > maxEvenSum) {
            maxEvenSum = dp[i][0];
            endIndex = i - 1;
        }
        if (dp[i][1] > maxEvenSum) {
            maxEvenSum = dp[i][1];
            endIndex = i - 1;
        }
    }

    // Nếu không tìm thấy đoạn con
    if (maxEvenSum == INT_MIN) {
        return {};
    }

    // Nếu đoạn con chỉ có một số
    if (maxEvenSum == arr[endIndex]) {
        return {arr[endIndex]};
    }

    // Tìm đoạn con tương ứng với endIndex
    vector<int> result;
    while (endIndex >= 0 && maxEvenSum > 0) {
        result.insert(result.begin(), arr[endIndex]);
        maxEvenSum -= arr[endIndex];
        endIndex--;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = findMaxEvenSubarray(arr);

    // In ra đoạn con có tổng giá trị là số chẵn lớn nhất hoặc thông báo NOT_FOUND
    if (result.empty()) {
        cout << "NOT_FOUND";
    } else {
        cout << "Max Even Sum Subarray: ";
        for (int num : result) {
            cout << num << " ";
        }
    }

    return 0;
}
