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
bool visited[MAX+1] = {0};
bool processed[MAX+1] = {0};
int flag = 0;
void cyclicity(vector < vector<int> >& graph);
void dfs(int v, vector < vector <int> >& graph);

void dfs(int v, vector < vector <int> >& graph)
{
	visited[v] = true;
	rep(i, 0, int(graph[v].size()))
	{
		if(!visited[graph[v][i]])
			dfs(graph[v][i], graph);
	}
	processed[v] = true;
	cout << v << "  ";
}


void topsort(vector < vector<int> >& graph)
{
	rep(i, 1, int(graph.size()))
		if(!visited[i])
			dfs(i, graph);
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector <int> > graph(n+1);
	rep(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	topsort(graph);
}
