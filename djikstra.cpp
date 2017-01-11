#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
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
typedef vector < vector < ii > > vvii;

int dist[MAX + 1];
void djikstra(int s, vvii & graph);


void djikstra(int s, vvii & graph)
{
	dist[s] = 0;
	set < ii > Q;
	Q.insert(ii(0,s));
	while(!Q.empty())
	{
		ii top = *Q.begin();
		int v1 = top.second;
		Q.erase(Q.begin());
		tr(graph[v1], it)
		{
			ii curr = *it;
		    int v2 = curr.first;
			int cost = curr.second;
			if(dist[v2] > dist[v1] + cost)
			{
				if(dist[v2] != inf)
					Q.erase(Q.find(ii(dist[v2], v2)));

				dist[v2] = dist[v1] + cost;
				Q.insert(ii(dist[v2], v2));
			}	
		}
	}
}


int main()
{
	fill(dist, dist + sizeof(dist)/sizeof(dist[0]),  inf);
	int n, m;
	cin >> n >> m;
	vvii graph(n+1);
	rep(i, 0, m)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		ii node = make_pair(y, weight);
		graph[x].push_back(node);
	}

	int s,t;
	cin >> s >> t;

	djikstra(s, graph);

	cout << dist[t] << endl;
}


