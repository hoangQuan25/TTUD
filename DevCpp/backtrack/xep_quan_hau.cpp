#include <bits/stdc++.h>
using namespace std;

// in ra so sach xep N quan hau tren ban co NxN
// sao cho ko co 2 quan hau nao an nhau

// xay dung cau hinh X = (X1, X2, ... XN) la 1 nghiem cua bai toan
// khi do neu Xi = j thi nghia la xep quan hau in row i column j

// can phai quan ly ko chi cac hang va cot ma con cac duong cheo
// co 2 loai duong cheo la duong cheo xuoi va nguoc
// xuoi: nghieng ve ben trai
// nguoc: nghieng ve been phai
// cac duong cheo duoc danh so tu tren xuong, moi loai co 15  duong cheo

// quan hau o [i][j] quan ly duong cheo xuoi i-j+N
// quan hau o [i][j] quan ly duong cheo nguoc i+j-1

// su dung mang cot[], cx[] va cn[] de danh dau cot, duong cheo xuoi va nguoc
// khi chuan bi xep X[i] vao cot j, can:
// cot[j] = 0; cx[i-j+N] = 0; cn[i+j-1] = 0
// (tuc la cot j, 2 duong cheo chua bi chiem)



int N, X[100], cot[100], cx[100], cn[100], sol;
int a[100][100]; // 2D arraya to print the board
//void print_sol() {
//	++count;
//}

// print out the solutions on board
void print_sol() {
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= N; i++) a[i][X[i]] = 1; // hau hang i cot j = 1
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void xep_hau(int i) {
	// duyet cac kha nang ma X[i] co the nhan duoc
	for (int j = 1; j <= N; j++) {
		// kiem tra cac cot va duong cheo
		if (cot[j] == 0 && cx[i - j + N] == 0 && cn[i + j - 1] == 0) {
			X[i] = j; // hau hang i se quan ly cot j
			cot[j] = cx[i - j + N] = cn[i + j - 1] = 1; // da bi chiem
			if (i == N) { // da duyet xong den hang cuoi cung
				++sol;
				print_sol();
			}
			else xep_hau(i + 1);
			cot[j] = cx[i - j + N] = cn[i + j - 1] = 0;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	sol = 0;
	cin >> N;
	xep_hau(1);
	cout << sol;
	return 0;
}

