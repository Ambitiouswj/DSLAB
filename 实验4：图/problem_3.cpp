#include "graph_2.h"

int n, m;

void solve()
{
    cin >> n >> m;
    Graph g(n, m);
    f[0] = 1;
    for (int i = 1; i <= 5; i++)
    {
        cin >> f[i];
    }
    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
        g.addEdge(b, a, c);
    }
    memset(d, INF, sizeof(d));
    for (int i = 0; i <= 5; i++)
    {
        g.dijkstra(f[i], d[i]);
    }

    memset(st, 0, sizeof(st));
    cout << g.dfs(1, 0, 0) << endl;
}

signed main()
{
	solve();
	return 0;
}