#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;

vector<int> adj[MAXN];
vector<int> order;
bool visited[MAXN];
int dp[MAXN];

void dfs_topo(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs_topo(v);
    }
    order.push_back(u);
}

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    int cnt = 1; // include self
    for (int v : adj[u]) {
        cnt += dfs(v);
    }
    return dp[u] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Topo sort
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs_topo(i);
    }

    reverse(order.begin(), order.end());

    // DP
    fill(dp, dp + n + 1, -1);
    for (int u : order) {
        if (dp[u] == -1)
            dfs(u);
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
