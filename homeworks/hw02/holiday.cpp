#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int to, weight, equipment;

    Edge(int t = 0, int w = 0, int e = 0)
    {
        this->to = t;
        this->weight = w;
        this->equipment = e;
    }
};

typedef pair<int, int> pi;

int n, m, k, min_cap = INT_MAX, max_cap = INT_MIN;
vector<Edge> g[(int)1e5];

bool dijkstra(int from, int to, int cap)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<int> dist(n, INT_MAX);
    vector<bool> used(n, false);

    pq.push(make_pair(0, from));

    dist[from] = 0;

    while (pq.empty() == false)
    {
        int u = pq.top().second;

        pq.pop();

        used[u] = true;

        for (const auto& x : g[u])
        {
            int v = x.to;
            int weight = x.weight;
            int equipment = x.equipment;

            if (equipment <= cap && (used[v] == false && dist[v] > dist[u] + weight))
            {
                dist[v] = dist[u] + weight;

                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[to] == INT_MAX)
        return false;

    if (dist[to] < k)
        return true;

    return false;
}

int bs(int from, int to)
{
    int l = 1, r = max_cap, mid = 0, result = INT_MAX;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (dijkstra(from, to, mid) == true)
        {
            r = mid - 1;

            result = mid;
        }
        else
            l = mid + 1;
    }

    if (result == INT_MAX)
        return -1;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, t;

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        Edge to_add;

        cin >> a >> b >> c >> t;

        to_add.to = b - 1;
        to_add.equipment = c;
        to_add.weight = t;

        if (c < min_cap)
            min_cap = c;

        if (c > max_cap)
            max_cap = c;

        g[a - 1].push_back(to_add);
    }

    cout << bs(0, n - 1);
}