#include <bits/stdc++.h>
using namespace std;

int main() {
	pair<int,int> v = make_pair(2,5); // tao pair
	pair<int, string> a = {6, "hello"}; // another way to make a pair
	pair<pair<int, int>, int> c = {{3, 4}, 5}; // long 2 pair
	
	cout << v.first << v.second << endl;
	cout << a.first << a.second << endl;
	cout << c.first.first << c.first.second << c.second << endl;
	return 0;
}
