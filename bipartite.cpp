#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <functional>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
#define MAX 1000
#define INF 2000000000
using namespace std;
bool visited[MAX+1] = {0};
bool processed[MAX+1] = {0};
int bipartite(int v, vector < vector <int> >& graph)
{
	visited[v] = true;
	queue <int> q;
	q.push(v);
	while(!q.empty())
	{
		int current = q.front();
		rep(i, 0,(int)(graph[current].size()))
			if(!visited[graph[current][i]])
			{
				visited[graph[current][i]] = true;
				q.push(graph[current][i]);
			}
			else if(visited[graph[current][i]] && !processed[graph[current][i]])
				return 0;
		processed[current] = true;
		q.pop();
	}
	return 1;
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
		graph[y].push_back(x);
	}

	rep(i, 1, (int)(graph.size()))
		if(!visited[i])
			cout << bipartite(i, graph) << endl;

}


