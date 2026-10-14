#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int a, b;
};

int n, m;
vector<Edge> edges;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int i = 0; i < m; i++) {
            int a = edges[i].a;
            int b = edges[i].b;

            if (a == u && !visited[b]) {
                visited[b] = true;
                q.push(b);
            }
            else if (b == u && !visited[a]) {
                visited[a] = true;
                q.push(a);
            }
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

    bfs(start);

    return 0;
}
