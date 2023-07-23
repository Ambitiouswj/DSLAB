#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define endl '\n'
#define N 510
#define M 200010
#define INF 0x3f3f3f3f
#define PII pair<int,int>
using namespace std;

bool st[N]; 
int f[N], d[6][N];

class Graph
{
private:
	int n; // 点数量
	int m; // 边数量
	int h[N], e[M], w[M], ne[M], idx; // 数组模拟邻接表
public:
	Graph(); // 构造函数
	Graph(int n, int m); // 构造函数 | 初始化点数量
	void addEdge(int p, int x, int c); // 加边
	int dfs(int u, int start, int dist); // DFS
	void dijkstra(int start, int ds[]); // Dijkstra求最短路
	void spfa(int start, int ds[]); // Spfa求最短路
};

Graph::Graph()
{
	memset(h, -1, sizeof(h));
}

Graph::Graph(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        h[i] = -1;
    }
    this->n = n, this->m = m;
}

void Graph::addEdge(int p, int x, int c)
{
	e[idx] = x;
	w[idx] = c;
	ne[idx] = h[p];
	h[p] = idx++;
}

void Graph::dijkstra(int start, int ds[])
{
    memset(st, 0, sizeof(st));
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    ds[start] = 0;
    heap.push({0, start});
    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();

        int u = t.second, dist = t.first;
        if (st[u]) continue;
        st[u] = true;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (ds[j] > dist + w[i])
            {
                ds[j] = dist + w[i];
                heap.push({ds[j], j});
            }
        }
    }
}

void Graph::spfa(int start, int ds[])
{
    memset(st, 0, sizeof(st));
    queue<int> que;
    ds[start] = 0;
    que.push(start);
    st[start] = true;
    while (que.size())
    {
        int t = que.front();
        que.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (ds[j] > ds[t] + w[i])
            {
                ds[j] = ds[t] + w[i];
                if (!st[j])
                {
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int Graph::dfs(int u, int start, int dist)
{
    if (u > 5) return dist;
    int ans = INF;
    for (int i = 1; i <= 5; i++)
    {
        if (!st[i])
        {
            int next = f[i];
            st[i] = true;
            ans = min(ans, dfs(u + 1, i, dist + d[start][next]));
            st[i] = false;
        }
    }
    return ans;
}