#include <bits/stdc++.h>
using namespace std;

// tim doan con max  su dung pp quy hoach dong truy vet
// su dung mang mark de danh dau xem gia tri vua tim ra da luu trong bo nho chua
// mang mem dung de luu cac gia tri da tim ra
int n, a[100], mark[100], mem[100];


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(mark, 0, sizeof(mark));
}

int max_sub(int i) {
	if (i == 1) return a[i];
	if (mark[i]) return mem[i];
	
	int res = max(a[i], a[i] + max_sub(i - 1));
	mem[i] = res;
	mark[i] = true;
	return res;
}

int main() {
	freopen("input", "r", stdin);
	input();
	int ans = 0;
	max_sub(n);
	for (int i = 0; i < n; i++) ans = max(ans, mem[i]);
	cout << ans;
	return 0;
}
