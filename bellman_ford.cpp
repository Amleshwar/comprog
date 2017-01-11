#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <math.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <functional>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define MAX 1000
#define eps 1e-7
#define inf 1000000007
using namespace std;
typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef pair < int, int > ii;
typedef vector < pair < int, int  > > vii;
typedef vector < vector < ii > > vvii;

vi d(MAX+1);
vi parent(MAX + 1);
void negativeCycles(int s, vvii & graph);
void recur(int v, vvii & g);
void dfs(int v, vvii & g);

queue <int>	q;
bool visited[MAX] = {0};

void recur(int v, vvii & g)
{
	int x = v;
	rep(i, 0, (int)(g.size()))
	{
		cout << x << " ";
		x = parent[x];
	}
	cout << endl;
}

void dfs(int v, vvii & g)
{
	visited[v] = true;
	rep(i, 0, (int)(g[v].size()))
	{
		if(!visited[g[v][i].first])
			dfs(g[v][i].first, g);
	}
}

void negativeCycles(int s, vvii & graph)
{
	fill(all(d), inf);
	d[s] = 0;
	parent[s] = -1;
	int n = graph.size();
	rep(i, 0, n)
	{
		vi cd(all(d));
		rep(j, 0, n)
		{
			int u = j;
			tr(graph[j], it)
			{
				int v = it-> first;
				int cost = it -> second;
				if((cd[v] > cd[u] + cost) && i == n-1) 
					q.push(v);
				else if(cd[v] > cd[u] + cost)
				{
					d[v] = d[u] + cost;	
					parent[v] = u;
				}
			}
		}
	}
	queue < int > q2 = q;
	while(!q2.empty())
	{
		int top = q2.front();
		q2.pop();
		dfs(top, graph);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vvii g(n);
	rep(i , 0 , m)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		g[x-1].push_back(make_pair(y-1, weight));
	}
	

	fill(all(d), inf);
	cout << endl;
	int s;
	cin >> s;
	negativeCycles((s-1), g);
	queue <int> q1 = q;
	rep(i, 0, n)
		if(!visited[i])
			cout << d[i] << " ";
		else 
			cout << "_" << " " ;
	cout << endl;
}
