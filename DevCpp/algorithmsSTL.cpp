#include <bits/stdc++.h>
using namespace std;

//min and max of a vector
void minmax() {
	vector<int> vec = {1, 2, 3, 5, 7};
	// min/max_element return an iterator (adress) so we must use * operator (dereferencing operator)
	cout << *min_element(vec.begin(), vec.end());
	cout << *max_element(vec.begin(), vec.end());
}


// sum of a vector
void a_sum() {
	vector<int> vec = {1, 2, 3, 5, 6};
	int sum = accumulate(vec.begin(), vec.end(), 0); // we can change the first and last index, with 0 is the initialized value
	cout << sum;
}


// swap value
// swap(a, b) // can be used to swap 2 pairs or even 2 vectors

//merge 2 vectors
void a_merge() {
	vector<int> a = {1, 2, 3, 4 ,5};
	vector<int> b = {6, 7, 8, 9, 10};
	vector<int> ans(10);  // must initialize the size of the target vector
	merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin()); // merge which part from a with which part from b and put where in ans
	for (const int& x : ans) cout << x << " ";
}


// fill: to fill all elements in a vector 
void a_memset() {
	vector<int> a(5);
	fill(a.begin(), a.end(), 5);
	for (const int& x : a) cout << x << " ";
}

int main() {
	a_memset();
	return 0;
}
