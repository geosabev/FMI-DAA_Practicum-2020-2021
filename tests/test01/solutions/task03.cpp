#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m, result = 0, single_components = 0;
map<int, vector<int>> g;
vector<bool> visited;

void DFS(int node)
{
    visited[node] = true;

    for (size_t i = 0; i < g[node].size(); i++)
    {
        if (visited[g[node][i]] == false)
        {
            DFS(g[node][i]);
        }
    }
}

void solve()
{
    visited.resize(n, false);

    for (auto v : g)
    {
        if (visited[v.first] == false)
        {
            DFS(v.first);

            result++;
        }
    }

    cout << result + single_components << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;

    cin >> n >> m;

    for (int j = 0; j < m; j++)
    {
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    if ((int)g.size() < n)
        single_components = n - g.size();

    solve();
}