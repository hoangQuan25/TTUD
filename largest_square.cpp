#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int index = 0;

    while (index < heights.size()) {
        if (s.empty() || heights[index] >= heights[s.top()]) {
            s.push(index);
            index++;
        } else {
            int top = s.top();
            s.pop();
            int width = s.empty() ? index : index - s.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int width = s.empty() ? index : index - s.top() - 1;
        maxArea = max(maxArea, heights[top] * width);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = maximalRectangle(matrix);
    cout << result << endl;

    return 0;
}
