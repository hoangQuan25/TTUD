#include <bits/stdc++.h>
using namespace std;

// chia M keo cho N em be, sao cho em be nao cung co keo
// dua ve bai toan giai pt tuyen tinh: x1+x2+...+xN = M
// gia su da xay dung loi giai bo phan: (x1, x2, ..., xK-1)
// f = (sigma sum) cua xi (i = 1 -> k-1) la so keo da chia cho be 1 -> k-1
// p = N - k: so luong em be con phai chia
// m0 = M - f - p: so luong keo toi da co the chia cho em k

int M, N, m0, f;
int X[100];

void print_sol() {
	for (int i = 1; i <= N; i++) {
		cout << X[i] << " ";
	}
	cout << endl;
}

void chia_keo(int k) {
	if (k == N + 1) {
//		X[k] = m0 - f;
		print_sol();
		return;
	}
	
	m0 = M - f - (N - k);
	for (int v = 1; v <= m0; v++) {
		X[k] = v;
		f = f + v;
		chia_keo(k + 1);
		f = f - v;
	}
}

int main() {
	cin >> M >> N;
	chia_keo(1);
	return 0;
}


