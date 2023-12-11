#include <bits/stdc++.h>
using namespace std;

// pseudo code for backtracking:
//function backtrack(candidate):
//    if candidate is a solution:
//        // Process the solution or add it to the result
//        process_solution(candidate)
//        return
//
//    for next_candidate in generate_candidates(candidate):
//        // Explore the next candidate
//        backtrack(next_candidate)
//
//// Example usage
//backtrack(initial_candidate)


// bai 1: sinh xau nhi phan do dai n
int N, X[100];

// print each solution
void print_sol() {
	for (int i = 1; i <= N; i++) cout << X[i];
	cout << endl;
}

void sinh_xau_nhi_phan(int i) {
	// duyet cac kha nang cua x[i];
	for (int j = 0; j <= 1; j++) {
		X[i] = j;
		if (i == N) print_sol();
		else sinh_xau_nhi_phan(i + 1);
	}
}

int main() {
	cin >> N;
	sinh_xau_nhi_phan(1);
	return 0;
}

