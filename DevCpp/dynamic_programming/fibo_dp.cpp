#include <bits/stdc++.h>
using namespace std;

// in ra so fibonacci thu n su dung pp quy hoach dong
// su dung 1 map de luu chi so va gia tri cac so fibo da tinh
int n;
map<int, int> mem; // luu tru cac ket qua da tinh ra

int fib(int n) {
	if (n <= 2) return 1;
	if (mem.find(n) != mem.end()) return mem[n]; // neu so fibo thu n da ton tai trong mem thi in ra
	
	int res = fib(n - 2) + fib(n - 1);
	mem[n] = res;
	return res;	
}

int main() {
	cin >> n;
	cout << fib(n);
	return 0;
}
