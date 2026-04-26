#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int,int>>> adj(n + 1);
    vector<pair<int,int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> ans(n - 1, -1);
    int label = 0;

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= 3) {
            for (auto &p : adj[i]) {
                ans[p.second] = label++;
            }
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (ans[i] == -1) {
            ans[i] = label++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}