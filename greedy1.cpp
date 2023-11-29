#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> intervals(n);

    // Nhập thông tin các đoạn thời gian
    for (int i = 0; i < n; ++i) {
        std::cin >> intervals[i].first >> intervals[i].second;
    }

    // Sắp xếp các đoạn thời gian theo thứ tự tăng dần của bi
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) {
                  return a.second < b.second;
              });

    // Tìm tập con lớn nhất không giao nhau
    std::vector<std::pair<int, int>> result;
    int lastEnd = 0;  // Kết thúc của đoạn thời gian cuối cùng được chọn

    for (const auto& interval : intervals) {
        if (interval.first >= lastEnd) {
            // Đoạn thời gian không giao nhau với đoạn đã chọn trước đó
            result.push_back(interval);
            lastEnd = interval.second;
        }
    }

    // In số lượng phần tử của tập con lớn nhất
    std::cout << result.size() << std::endl;

    // for (const auto& interval : result) {
    //     std::cout << interval.first << " " << interval.second << std::endl;
    // }

    return 0;
}
