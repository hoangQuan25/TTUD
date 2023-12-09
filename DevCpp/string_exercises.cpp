#include <bits/stdc++.h>
using namespace std;

// 1. dem so tu trong 1 xau (co nhieu dau cach) vd: hello     i  am    quan
//output 4
void b1() {
	string s;
	getline(cin, s);
	stringstream ss(s); // define a stringstream object, and assign it with string s
	// stringstream is a stream like cin/cout but working with string
	// stringstream can read single words, and ignore blankets between them
	
	string word;
	int count = 0;
	vector<string> v;
	// extract operator <<
	while (ss >> word) { // each time ss extracts a string into word (note: word just reads one word each time)
		++count;
		v.push_back(word); // so we can add the read word into vector each time
	}
	cout << count << endl;
	for (string x : v) cout << x << endl;
}


// b2. delete a word in a sentence (with many blankets between words) and return the sentence with just 1 blanket between words
void b2() {
	string s, word;
	getline(cin, s); cin >> word;
	stringstream ss(s);
	string token; // to save the extracted word from s
	vector<string> v;
	while (ss >> token) {
		if (token != word) v.push_back(token);  // save the extracted words into a vector except the deleted words
	}
	for (int i = 0; i < v.size(); i++){ // print out the sentence after deleting, but note: the end of the sentence can't be a blanket
		cout << v[i];
		if (i != v.size() - 1) cout << " ";
	}
}



//b3. create email from names
// input line 1: nums of testcases, line 2 and after: names
// example: NgUYEn    VaN    mANH    => manhnv@gmail.com
void b3() {
	int t; cin >> t;
	cin.ignore(); // each testcase starts with an 'enter' so needs to be ignored
	while(t--) {
		string s;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]); // convert each char to lowercase
		
		vector<string> v; // save extracted words
		stringstream ss(s);
		string tmp; // token to save each extracted word
		while (ss >> tmp) v.push_back(tmp);
		cout << v.back();
		for (int i = 0; i < v.size() - 1; i++) cout << v[i][0];
		cout << "@gmail.com" << endl;
	}
}



// b4. the same as b3, but now if a person with the name "A" already exists, then another one with name "A" create email
// then that person's email needs to have order number 
// eg. manhnv@gmail.com
// manhnv2@gmail.com
// manhnv3@gmail.com
void b4() {
	int t; cin >> t;
	cin.ignore(); // each testcase starts with an 'enter' so needs to be ignored
	map<string, int> mp; // duty: count how many times each full name appeared
	
	// a map contains pairs of keys - values
	// keys must be unique
	
	while(t--) {
		string s;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]); // convert each char to lowercase
		
		vector<string> v; // save extracted words
		stringstream ss(s);
		string tmp; // token to save each extracted word
		string ans = ""; // to save the email names // eg. manhnv, linhnt
		while (ss >> tmp) v.push_back(tmp);
		ans += v.back();
		for (int i = 0; i < v.size() - 1; i++) ans += v[i][0];
		
		if (mp.find(ans) == mp.end()) cout << ans << "@gmail.com";
		else cout << 
		cout << "@gmail.com" << endl;
	}
}

int main() {
	b3();
	return 0;
}
