#include "graph_1.h"

int n, m;
vector<int> stop;

void solve()
{
	Graph g;
    cin >> n >> m;
    string s;
    getline(cin, s);
    while (m--)
    {
        getline(cin, s);
        stringstream ssin(s);
        int p;
        while (ssin >> p)
        {
            stop.push_back(p);
        }
        int cnt = stop.size();
        for (int i = 0; i < cnt; i++)
        {
            for (int j = i + 1; j < cnt; j++)
            {
                g.addEdge(stop[i], stop[j], 1);
            }
        }
        stop.clear();
    }
    g.bfs();
    if (d[n] > INF / 2) cout << "impossible" << endl;
    else if (d[n] == 0) cout << 0 << endl;
    else cout << d[n] - 1 << endl;
}

signed main()
{
	solve();
	return 0;
}