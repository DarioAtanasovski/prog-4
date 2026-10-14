#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> mat;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 1; v <= n; v++) {
        if (mat[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;

    mat.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int start;
    cin >> start;

    dfs(start);

    return 0;
}
