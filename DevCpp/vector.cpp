#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> myVector;
	vector<int> anotherVector = {2, 4, 5 ,1, 6, 3};
	
	myVector.push_back(25); // add element to a vector
	for (const auto& num : anotherVector) myVector.push_back(num);
	myVector.insert(myVector.begin() + 3, 8); // another way to insert element to vector
	
	myVector.pop_back(); // delete last element of vector
	
	sort(myVector.begin(), myVector.end()); // sort a vector
	
	auto it = find(myVector.begin(), myVector.end(), 8); // iterator to find if 8 is in vector
	if (it != myVector.end()) cout << "found" << endl;
	
	myVector.empty() ? cout << "it's empty" << endl : cout << "it's not empty" << endl; // check if vector is empty
	
	for (const auto& num : myVector) cout << num << endl;
	return 0;	
}
