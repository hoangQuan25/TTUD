#include <bits/stdc++.h>
using namespace std;

int main1() {
	vector<int> a = {1, 4, 2, 6, 3, 9, 5, 7};
	vector<int> b = {7, 8, 3, 1, 9};
	
	// sort default
//	sort(a.begin(), a.end());
	// decresing sort
	sort(b.begin(), b.end(), greater<int>());
	// sort from index x to index y -> a[x, y - 1] vd 1 -> 6
	sort(a.begin() + 1, a.begin() + 5);
	
	// sort a vector of pairs, by default it will sort by the value of first 
	vector<pair<int, int>> pairs;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pairs.push_back(make_pair(a, b));
	}
	sort(pairs.begin(), pairs.end());
	for (const auto& it : pairs) {
//		cout << it.first << " " << it.second << endl;
	}
}
	
	
// stable_sort(): sort but keeps the order of elements that are not moved (like in insertion or bubble sort)
// exercise: sort an arrays of numbers by the absolute value eg: 1 -1 2 -2 3 -4 5 -5 
// we will make a comparator
bool cmp(int a, int b) {
	return abs(a) < abs(b); // find absolute value then sort by increasing order
}

int main() {
	vector<int> vec = {1, -1, 2, 5, -2, -5, 1, 4};
	stable_sort(vec.begin(), vec.end(), cmp);
	for (const int& num : vec) cout << num << " ";
	return 0;
}
	






