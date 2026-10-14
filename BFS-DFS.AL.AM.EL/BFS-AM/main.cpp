#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> mat;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v = 1; v <= n; v++) {
            if (mat[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
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

    bfs(start);

    return 0;
}
