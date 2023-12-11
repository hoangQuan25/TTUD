#include <bits/stdc++.h>
using namespace std;

// in ra cac to hop chap K cua tap N phan tu tu 1 -> N
int N, K, X[100];

void print_sol() {
	for (int i = 1; i <= K; i++) cout << X[i] << " ";
	cout << endl;
}

void nCk(int i) {
	for (int j = X[i - 1] + 1; j <= N - K + i; j++) { // gioi han khoang chay tu X[i-1] den N - K + i
		X[i] = j;
		if (i == K) print_sol();
		else nCk(i + 1);
	}
}

int main() {
	cin >> N >> K;
	nCk(1);
	return 0;
}
