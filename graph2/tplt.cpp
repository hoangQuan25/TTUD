// Một đồ thị có hướng là liên thông mạnh nếu như có đường từ bất kì đỉnh nào tới bất kì đỉnh nào khác. 
// Một thành phần liên thông mạnh của một đồ thị có hướng là một đồ thị con tối đại liên thông mạnh. 

#include <bits/stdc++.h>
using namespace std;
const int N =1e4+5;
int n,m;
vector<int> adj[N];
vector<int> low(N), num(N,-1);
vector<bool> connect(N,false);
stack<int> stk;
int curNum = 0;
void scc(int u){
    stk.push(u);
    connect[u] = true;
    low[u] = num[u] = ++curNum;
    for (int v: adj[u]){
        if (num[v] == -1){
            scc(v);
            low[u] = min(low[u],low[v]);
        }else {
            if (connect[v]){
                low[u] = min(low[u],num[v]);
            }
        }
    }
    if (low[u] == num[u]){
        cout << "TPLT: ";
        while(true){

            int v = stk.top();
            stk.pop();
            connect[v] = false;
            cout << v << ' ';
            if (v==u) break;
        }
        cout << endl;
    }
}
void input(){
    cin >> n >> m;
    int u,v;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
}
int main(){
    freopen("scc.inp","r",stdin);
    input();
    for (int u=1;u<=n;u++){
        if (num[u] == -1) scc(u);
    }
    return 0;
}