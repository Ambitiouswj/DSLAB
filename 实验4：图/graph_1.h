#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define endl '\n'
#define N 510
#define M 200010
#define INF 0x3f3f3f3f
#define PII pair<int,int>
using namespace std;

int d[N]; // 距离连通块的距离
extern bool st[N];

class Graph
{
private:
	int n; // 点数量
	int m; // 边数量
	int e[N][N]; // 邻接矩阵
public:
	Graph(); // 构造函数
	Graph(int n, int m); // 构造函数 | 初始化点数量
	void addEdge(int p, int x, int c); // 加边
	void bfs(); // BFS
	int prim(); // Prim求最小生成树
};

Graph::Graph()
{
	memset(e, INF, sizeof(e));
	n = 0, m = 0;
}

Graph::Graph(int n, int m)
{
	this->n = n, this->m = m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = INF;
}

void Graph::addEdge(int p, int x, int c)
{
	e[p][x] = min(e[p][x], c);
}

int Graph::prim()
{
	memset(d, INF, sizeof(d));
	memset(st, 0, sizeof(st));
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || d[t] > d[j]))
				t = j;
		}
		if (i > 1 && d[t] == INF) return INF;
		if (i > 1) ans += d[t];
		st[t] = true;
		for (int j = 1; j <= n; j++)
		{
			d[j] = min(d[j], e[t][j]);
		}
	}
	return ans;
}

void Graph::bfs()
{
	memset(d, INF, sizeof(d));
	queue<int> que;
	que.push(1);
	d[1] = 0;
	while (que.size())
	{
		int t = que.front();
		que.pop();
		for (int j = 1; j <= n; j++)
		{
			if (e[t][j] && d[j] > d[t] + 1)
			{
				d[j] = d[t] + 1;
				que.push(j);
			}
		}
	}
}

