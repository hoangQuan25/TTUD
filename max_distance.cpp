#include <iostream>
#include <vector>
#include <algorithm>

bool isFeasible(const std::vector<int>& arr, int n, int c, int d) {
    int count = 1;
    int lastPos = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] - lastPos >= d) {
            lastPos = arr[i];
            count++;
        }
    }

    return count >= c;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, C;
        std::cin >> N >> C;

        std::vector<int> arr(N);

        for (int i = 0; i < N; ++i) {
            std::cin >> arr[i];
        }

        // Sắp xếp lại mảng
        std::sort(arr.begin(), arr.end());

        // Tìm kiếm nhị phân để tìm giá trị tối ưu d
        int low = 0;
        int high = arr[N - 1] - arr[0];
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isFeasible(arr, N, C, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
