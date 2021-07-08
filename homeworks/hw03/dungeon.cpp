#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int from, to, weight;

    Edge(int f = 0, int t = 0, int w = 0)
    {
        this->from = f;
        this->to = t;
        this->weight = w;
    }

    bool operator<(const Edge& target) const
    {
        return this->weight < target.weight;
    }
};

int n, m;
Edge edges[(int)1e6];
int parent[(int)1e5], depth[(int)1e5];

int find_root(int node)
{
    if (parent[node] == node)
        return node;

    int root = find_root(parent[node]);

    parent[node] = root;

    return root;
}

void unite(int from, int to)
{
    int root = 0;

    if (depth[from] < depth[to])
    {
        root = find_root(from);

        parent[root] = to;
    }
    else if (depth[from] > depth[to])
    {
        root = find_root(to);

        parent[root] = from;
    }
    else
    {
        root = find_root(to);

        parent[root] = from;

        depth[from]++;
    }
}

void kruskal()
{
    sort(edges, edges + m);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;

        depth[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int root_from = find_root(edges[i].from);
        int root_to = find_root(edges[i].to);

        if (root_from == root_to)
        {
            cout << edges[i].weight << '\n';

            return;
        }

        unite(root_from, root_to);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;

    kruskal();
}