#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// par -> tree
vector<vector<int>> tree;

// We can re-use the NLR type traversal on root with
// markers for the subtree start and end (calculated using
// starts and sizes)
vector<int> globalPath;
vector<int> starts;
vector<int> sizes;

void preprocess(int node) {
    // This is the same as having a int cur in preprocess
    // and using that but since it'll always be latest
    // node, we can can just do .size()
    starts[node] = globalPath.size();
    globalPath.push_back(node);
    sizes[node] = 1;

    for(const auto& child : tree[node]) {
        preprocess(child);
        // For the end marker ...
        sizes[node] += sizes[child];
    }
}

void solve() {
    int n, q, par;
    cin >> n >> q;

    tree.resize(n + 1);
    globalPath.resize(n + 1);
    starts.resize(n + 1);
    sizes.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        cin >> par;
        tree[par].push_back(i);
    }

    preprocess(1);

    for(int i = 0; i < q; ++i) {
        int u, k;
        cin >> u >> k;
        if(k > sizes[u]) cout << -1 << "\n";
        else cout << globalPath[starts[u] + k - 1] << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
