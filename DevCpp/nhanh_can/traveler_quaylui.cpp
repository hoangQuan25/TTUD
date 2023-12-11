#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// bai toan nguoi di du lich
// n thanh pho danh so tu 1 -> n, cac doan duong 2 chieu giua chung
// c[i][j] = c[j][i] la chi phi di lai giua i va j
// chi phi giua thanh pho i va chinh no la 0
// 1 nguoi xuat phat tu thanh pho 1, muon di qua tat ca cac thanh pho dung 1 lan va quay ve 1
// tinh chi phi it nhat


int n, c[105][105], X[100], visited[105];
ll d = 0, ans = INT_MAX; // luu chi phi da su dung va chi phi duong di toi uu

// loi giai: X1, X2, X3, ..., XN
// X[i]: so thu tu thanh pho thu i ma nguoi du lich di qua
// tuong tu bai toan sinh quay lui hoan vi, moi thanh pho chi duoc di qua 1 lan
// => can 1 mang danh dau visited[]

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    memset(visited, 0, sizeof(visited)); // chua di qua thanh pho nao
}

void Try(int i) {
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            X[i] = j;
            d += c[X[i - 1]][X[i]];
            if (i == n) {
                ans = min(ans, d + c[X[n]][1]); // can phai cong them chi phi tu tp n quay ve tp 1
            } else {
                Try(i + 1);
            }
            // giai phong j 
            visited[j] = 0;
            d -= c[X[i - 1]][X[i]]; // tru thanh pho vua duyet di
        }
    }
}

int main() {
	freopen("input", "r", stdin);
    input();
    X[1] = 1;
    visited[1] = 1; // luon luon bat dau tu 1
    Try(2);
    cout << ans << endl;
    return 0;
}
