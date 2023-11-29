// Thuật toán Prim cũng là một thuật toán tham lam (greedy algorithm) được sử dụng để tìm cây bao trùm 
// (minimum spanning tree) của một đồ thị có trọng số. Tương tự như thuật toán Kruskal, thuật toán Prim
//  bắt đầu với một đỉnh bất kỳ và mở rộng cây bao trùm bằng cách thêm cạnh có trọng số nhỏ nhất liên kết
//   một đỉnh trong cây với một đỉnh ngoại vi.

// Dưới đây là miêu tả ngắn về thuật toán Prim:

// Khởi tạo:

// Chọn một đỉnh bắt kỳ làm đỉnh xuất phát và thêm nó vào cây bao trùm.
// Chọn cạnh nhỏ nhất:

// Lặp lại cho đến khi cây bao trùm chứa tất cả các đỉnh:
// Chọn cạnh có trọng số nhỏ nhất mà một đỉnh của nó thuộc cây bao trùm và đỉnh kia không thuộc cây.
// Thêm đỉnh và cạnh:

// Thêm đỉnh kết nối bởi cạnh đã chọn vào cây bao trùm.
// Lặp lại:

// Lặp lại bước 2 và 3 cho đến khi cây bao trùm chứa tất cả các đỉnh.
// Thuật toán Prim đảm bảo rằng mỗi bước chỉ chọn một cạnh có trọng số nhỏ nhất để kết nối một đỉnh 
// trong cây với một đỉnh ngoại vi. Cuối cùng, nó tạo ra một cây bao trùm có tổng trọng số nhỏ nhất.

// Một điểm khác biệt giữa thuật toán Kruskal và Prim là cách chúng chọn cạnh để thêm vào cây bao trùm: 
// Kruskal chọn cạnh theo trọng số nhỏ nhất, còn Prim chọn cạnh theo đỉnh đã có trong cây và trọng số nhỏ nhất.

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9 + 5;
int n, m;

struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<vector<edge>> adj;

void input() {
    cin >> n >> m;
    adj.resize(n + 1);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(edge(u, v, w));
        adj[v].push_back(edge(v, u, w));
    }
}

vector<edge> prim(int start, const vector<vector<edge>> &adj) {
    vector<bool> inTree(N, false);
    vector<int> dist(N, INF);
    vector<int> near(N, -1);
    vector<edge> res;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inTree[u])
            continue;

        inTree[u] = true;

        if (near[u] != -1)
            res.push_back(edge(near[u], u, dist[u]));

        for (const edge &e : adj[u]) {
            int v = e.v, w = e.w;
            if (!inTree[v] && w < dist[v]) {
                dist[v] = w;
                near[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return res;
}

int main() {
    freopen("dothi.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    int ans = 0;
    vector<edge> res = prim(1, adj); // Assuming starting node is 1
    for (const edge &e : res) {
        ans += e.w;
        cout << e.u << ' ' << e.v << ' ' << e.w << ' ' << endl;
    }
    cout << "MST: " << ans << endl;
    return 0;
}
