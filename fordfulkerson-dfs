#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<vector<long long>> residual;
vector<bool> visited;

long long dfs(int u, int t, long long flow) {
    if (u == t) return flow;

    visited[u] = true;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && residual[u][v] > 0) {
            long long pushed =
                dfs(v, t, min(flow, residual[u][v]));

            if (pushed > 0) {
                residual[u][v] -= pushed;
                residual[v][u] += pushed;
                return pushed;
            }
        }
    }

    return 0;
}

long long fordFulkerson(int s, int t) {
    if (s == t) return 0;

    long long maxFlow = 0;

    while (true) {
        visited.assign(n, false);

        long long pushed = dfs(s, t, LLONG_MAX);

        if (pushed == 0) break;

        maxFlow += pushed;
    }

    return maxFlow;
}

int main() {
    int m, s, t;

    cin >> n >> m;
    cin >> s >> t;

    residual.assign(n, vector<long long>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        long long capacity;

        cin >> u >> v >> capacity;

        residual[u][v] += capacity;
    }

    cout << "Max flow = " << fordFulkerson(s, t) << '\n';

    return 0;
}
