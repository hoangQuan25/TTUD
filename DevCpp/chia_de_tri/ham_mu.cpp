#include <bits/stdc++.h>
using namespace std;

int x, n;
// tinh ham mu x^n su dung pp chia de tri
int dc_pow(int x, int n) {
	if (n == 0) return 1;
	if (n % 2 == 0) return dc_pow(x, n / 2) * dc_pow(x, n / 2);
	else return dc_pow(x, n/ 2) * dc_pow(x, n / 2) * x;
}

int main() {
	cin >> x >> n;
	int res = dc_pow(x, n);
	cout << res;
	return 0;
}
