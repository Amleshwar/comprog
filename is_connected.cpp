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
int flag = 0;

bool isConnected(int u, int v, vector < vector <int> >& graph)
{
	visited[u] = true;
	if(find(all(graph[u]), v) != graph[u].end())
		return true;
	else
	{
		rep(i, 0, (int)graph[u].size())
		{
			if(!visited[graph[u][i]])
				if(isConnected(graph[u][i], v, graph))
					flag = 1;
		}
		return (flag == 1 ? true : false);
	}
}


int main()
{
	int n, m, u, v;
	cin >> n >> m;
	vector < vector <int> > graph(n + 1);
	rep(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cin >> u >> v;
	if(isConnected(u, v, graph))
		cout << "1" << endl;
	else
		cout << "0" << endl;
}


