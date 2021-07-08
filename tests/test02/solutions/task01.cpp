#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MOD = 1000000021;

int n, m, q;
vector<pair<int, int>> g[560];
bool visited[560];

int dist[560][560], paths_to[560][560];

void dijkstra_modified(int from)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fill(visited, visited + n, false);
    fill(dist[from], dist[from] + n, INT_MAX);
    fill(paths_to[from], paths_to[from] + n, 0);

    dist[from][from] = 0;
    paths_to[from][from] = 1;

    pq.push({ 0,from });

    while (pq.empty() == false)
    {
        int node = pq.top().second;

        pq.pop();

        if (visited[node] == true)
            continue;

        visited[node] = true;

        for (auto neighbor : g[node])
        {
            if (dist[from][node] + neighbor.second > dist[from][neighbor.first])
                continue;

            if (dist[from][node] + neighbor.second == dist[from][neighbor.first])
                paths_to[from][neighbor.first] = ((paths_to[from][neighbor.first] % MOD) + (paths_to[from][node] % MOD)) % MOD;
            else
            {
                paths_to[from][neighbor.first] = paths_to[from][node];

                dist[from][neighbor.first] = dist[from][node] + neighbor.second;

                pq.push({ dist[from][neighbor.first],neighbor.first });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int from, to, weight;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> weight;

        g[from - 1].push_back({ to - 1, weight });
        g[to - 1].push_back({ from - 1, weight });
    }

    cin >> q;

    for (int i = 0; i < n; i++)
        dijkstra_modified(i);

    for (int i = 0; i < q; i++)
    {
        cin >> from >> to;

        cout << paths_to[from - 1][to - 1] << ' ';
    }
}