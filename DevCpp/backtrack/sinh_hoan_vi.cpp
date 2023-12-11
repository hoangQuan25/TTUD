#include <bits/stdc++.h>
using namespace std;

int N, X[100], mark[100]; // array mark de danh dau so nay da dc in ra chua


void print_sol() {
	for (int i = 1; i <= N; i++) {
		cout << X[i] << " ";
	}
	cout << endl;
}

void sinh_hoan_vi(int k) {
	for (int i = 1; i <= N; i++) {
		if (!mark[i]) {
			X[k] = i;
			mark[i] = true; // so nay da duoc in ra // 1 phan tu khong the xuat hien 2 lan trong cau hinh
			if (k == N) print_sol();
			else sinh_hoan_vi(k + 1);
			mark[i] = false; // lui lai 1 so
		}
	}
}

int main() {
	cin >> N;
	memset(mark, 0, sizeof(mark));
	sinh_hoan_vi(1);
	return 0;
}
