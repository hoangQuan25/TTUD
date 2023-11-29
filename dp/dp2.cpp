// đếm số xâu nhị phân độ dài n sao cho 
// - không chứa hai số 0 liên tiếp nhau
// - các đoạn số 1 liền nhau có độ dài k1 <= l <= k2

// bài toán con: dp(i) = đếm số xâu nhị phân độ dài i
// thỏa mãn yêu cầu

// dp(i, 0) đếm số xâu nhị phân độ dài i kết thúc bởi 0 thỏa mãn yêu cầu
// dp(i, 1) đếm số xâu nhị phân độ dài i kết thúc bởi 1 thỏa mãn yêu cầu

#include <iostream>
#include <cstring>
using namespace std;

const int N = 10000 + 5;
int n, k1, k2;
int mem[N][2];

int dp(int i, int work) {
    if (i == 0) return mem[i][work] = 1;
    if (mem[i][work]) return mem[i][work];
    int res = 0;
    if (!work) {
        res = dp(i - 1, 1);
    } else {
        for (int j = i - k2; j <= i - k1; j++)
            if (j >= 0) res += dp(j, 0);
    }
    return mem[i][work] = res;
}

int main() {
    memset(mem, 0, sizeof(mem));
    cin >> n >> k1 >> k2;
    cout << dp(n, 0) + dp(n, 1) << endl;
    return 0;
}
