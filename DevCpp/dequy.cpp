#include <bits/stdc++.h>
using namespace std;

// stack (int STL lib)
// stack.push(a) // them a vao stack
// stack.pop() // xoa pt tren cung cua stack


// vd
int tong(int n) {
	if (n == 1) return 1; // break point
	else return n + tong(n - 1);
}

// giai thua
int gt(int n) {
	if (n == 0) return 1;
	return n * gt(n - 1);
}

// fibonacci
long long fibo(int n) {
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}

// to hop chap k cua n
// nCk = 1 if k = 0 or n = k
// else nCk = (n-1)C(k-1) + (n-1)Ck
int nCk(int n, int k) {
	if (k == 0 || n == k) return 1;
	return nCk(n - 1, k - 1) + nCk(n - 1, k);
}

// ucln (gcd)
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// luy thua (voi dpt log(n))
int binpow(int a, int b) {
	if (b == 0) return 1;
	
	int x = binpow(a, b / 2);
	if (b % 2 == 1) return a * x * x;
	else return x * x;
}

// dem so luong chu so 1 so
int count(long long n) {
	if (n < 10) return 1;
	return 1 + count(n / 10);
}

int main() {
	long long n;
	cin >> n;
	cout << count(n) << endl;
	return 0;
}
