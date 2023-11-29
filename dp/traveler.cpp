#include <iostream>
#include <cstring>

using namespace std;
const int MAX_CITIES = 20;
const int INF = 1000000000;  // or use INT_MAX from <climits>
int real_cities;
int C[MAX_CITIES][MAX_CITIES], mem[MAX_CITIES][1 << MAX_CITIES];

int dynamic_programming(int curr_city, int visited_cities) {
    if (visited_cities == (1 << real_cities) - 1) return mem[curr_city][visited_cities] = C[curr_city][0];

    if (mem[curr_city][visited_cities] != -1) return mem[curr_city][visited_cities];

    int res = INF;
    for (int j = 1; j <= real_cities; j++) {
        if (visited_cities & (1 << j)) continue;
        res = min(res, C[curr_city][j] + dynamic_programming(j, visited_cities | (1 << j)));
    }
    return mem[curr_city][visited_cities] = res;
}

void trace(int curr_city, int visited_cities) {
    cout << curr_city << " -> ";
    if (visited_cities == (1 << real_cities) - 1) {
        cout << 0 << endl;
        return;
    }
    for (int j = 1; j <= real_cities; j++) {
        if (visited_cities & (1 << j)) continue;
        if (mem[curr_city][visited_cities] == C[curr_city][j] + dynamic_programming(j, visited_cities | (1 << j))) {
            trace(j, visited_cities | (1 << j));
            break;
        }
    }
}

void input() {
    cin >> real_cities;
    for (int i = 0; i < real_cities; i++) {
        for (int j = 0; j < real_cities; j++) cin >> C[i][j];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(mem, -1, sizeof(mem));
    input();
    cout << dynamic_programming(0, 1) << endl;
    trace(0, 1);
    return 0;
}
