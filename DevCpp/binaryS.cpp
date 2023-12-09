#include <bits/stdc++.h>
using namespace std;

// binary search
// cac pt trong mang phai dc sap xep

bool bs(int a[], int n, int x ) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) return true;
		
		// x < mid => left = mid + 1
		else if (a[mid] < x) left = mid + 1;
		
		//x > mid
		else right = mid - 1;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, e; cin >> n, x;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> e;
		a.push_back(e);
	} 
	sort(a.begin(), a.end()); //sort a vector
	bool found = binary_search(a.begin(), a.end(), x); // binary search default of algorithm library
	if (found) cout << "found";
	else cout << "not found";
	return 0;
}





