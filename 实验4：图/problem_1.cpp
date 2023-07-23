#include "graph_1.h"

int n, m;

void solve()
{
	cin >> n >> m;
	Graph g(n, m);
	int a, b, c;
	while (m--)
	{
		g.addEdge(a, b, c);
		g.addEdge(b, a, c);
	}
	int ans = g.prim();
	if (ans > INF / 2) cout << "impossible" << endl;
	else cout << ans << endl;
}

signed main()
{
	solve();
	return 0;
}