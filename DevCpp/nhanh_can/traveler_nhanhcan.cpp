#include <bits/stdc++.h>
using namespace std;

// bai toan nguoi du lich su dung nhanh va can
// ghi nhan 1 ki luc gia tri vao ans
// khi re nhanh, danh gia xem cac nhanh "co the" dem ve 1 gia tri better than ki luc ans hay khong
// neu khong, khong tiep tuc quay lui o nhanh do

int n, c[105][105], X[100], visited[105];
int d = 0, ans = INT_MAX, cmin = INT_MAX; // luu chi phi da su dung va chi phi duong di toi uu

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] != 0) cmin = min(cmin, c[i][j]);
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
            	// cap nhat ket qua
                ans = min(ans, d + c[X[n]][1]); // can phai cong them chi phi tu tp n quay ve tp 1
            } else if (d + (n - i + 1) * cmin < ans){ // danh gia can, neu tiep tuc quay lui "khong chac chan" dem lai loi giai worse than ans
                Try(i + 1); 						  // thi tiep tuc quay lui
            }
            // backtrack, giai phong j 
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
