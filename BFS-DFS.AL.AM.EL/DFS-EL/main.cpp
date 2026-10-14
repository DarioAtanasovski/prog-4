#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int a, b;
};

int n, m;
vector<Edge> edges;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;

        if (a == u && !visited[b]) {
            dfs(b);
        }
        else if (b == u && !visited[a]) {
            dfs(a);
        }
    }
}

int main() {
    cin >> n >> m;

    edges.resize(m);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b;
    }

    int start;
    cin >> start;

    dfs(start);

    return 0;
}
