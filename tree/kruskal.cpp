// // Thuật toán Kruskal là một thuật toán tham lam (greedy algorithm) được sử dụng để tìm cây bao trùm 
// (minimum spanning tree) của một đồ thị có trọng số. Cây bao trùm là một cây con của đồ thị mà nó bao 
// phủ tất cả các đỉnh và có tổng trọng số nhỏ nhất.

// Dưới đây là miêu tả ngắn về thuật toán Kruskal:

// Sắp xếp cạnh:

// Sắp xếp tất cả các cạnh của đồ thị theo thứ tự tăng dần của trọng số.
// Tạo cây rỗng:

// Khởi tạo cây bao trùm là một tập hợp các đỉnh đơn (cây rỗng).
// Chọn cạnh nhỏ nhất:

// Lặp qua danh sách các cạnh theo thứ tự đã sắp xếp.
// Chọn cạnh có trọng số nhỏ nhất, nhưng đảm bảo rằng việc thêm cạnh này vào cây không tạo ra chu trình (không tạo thành đồ thị có chu trình).
// Thêm cạnh vào cây:

// Thêm cạnh đã chọn vào cây bao trùm.
// Lặp lại:

// Lặp lại bước 3 và 4 cho đến khi cây bao trùm chứa tất cả các đỉnh.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;
int n, m;
struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) :
    u(_u), v(_v), w(_w) {}
};

vector<edge> edges;

struct UnionFind {
    vector<int> parent;
    UnionFind(int n) {
        parent = vector<int>(n);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Unite(int x, int y) {
        parent[Find(x)] = Find(y);
    }
};

bool edgeCmp(const edge& a, const edge& b) {
    return a.w < b.w;
}

vector<edge> kruskal(int n, vector<edge> edges) {
    sort(edges.begin(), edges.end(), edgeCmp);
    UnionFind uf(n);
    vector<edge> res;
    for (const auto &e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (uf.Find(u) != uf.Find(v)) {
            res.push_back(e);
            uf.Unite(u, v);
        }
    }
    return res;
}

void input() {
    cin >> n >> m;
    int u, v , w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }
}

int main() {
    freopen("dothi.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    int ans = 0;
    vector<edge> res = kruskal(n, edges);
    for (const edge& e : res) {
        ans += e.w;
        cout << e.u << ' ' << e.v << ' ' << e.w << ' ' << endl;
    }
    cout << "MST: " << ans << endl;
    return 0;
}