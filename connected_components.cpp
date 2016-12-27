#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
#define MAX 1000 
using namespace std;

int connectedComponent(vector < vector <int> >& graph, int n);
void dfs(int v, vector < vector<int> >& graph);
bool visited[MAX+1] = {0};

void dfs(int v, vector < vector<int> >& graph)
{
	visited[v] = true;
	rep(i, 0, (int)graph[v].size())
		if(!visited[graph[v][i]])
			dfs(graph[v][i], graph);
}

int connectedComponent(vector < vector <int> >& graph, int n)
{
	int count = 0;
	rep(i, 1, n + 1) 
	{
		if(!visited[i])
		{
			count++;
			dfs(i, graph);
		}
	}
	return count;
}

int main()
{
	int n, m;
	cin >> n >> m; //n is the number of vertices, m is the number of edges
	vector < vector <int> > graph(n+1);
	rep(i, 0 , m)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << connectedComponent(graph, n);
}


