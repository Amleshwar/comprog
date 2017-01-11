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
#include <functional>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define MAX 1000
using namespace std;
bool visited[MAX+1] = {0};
bool discovered[MAX+1] = {0};

vector < pair <int, int> > post((MAX+1), make_pair(0, 0));
vector < pair <int, int> > pre((MAX+1), make_pair(0, 0));

int t =  0;


void explore(int v, vector < vector <int> >& graph);
void dfs(int v, vector < vector <int> >& graph);
int scc(vector < vector <int> >& graph);
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b);

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b)
{
       return (a.first > b.first);
}
 
void dfs(int v, vector < vector <int> >& graph)
{
	visited[v] = true;
	pre[v].first = ++t;
	rep(i, 0, (int)(graph[v].size()))
		if(!visited[graph[v][i]])
			dfs(graph[v][i], graph);
	
	post[v].first = ++t;	
}



void explore(int v, vector < vector <int> >& graph)
{
	discovered[v] = true;
	rep(i, 0, (int)(graph[v].size()))
		if(!discovered[graph[v][i]])
			explore(graph[v][i], graph);
}


int scc(vector < vector <int> >& graph)
{
	int count = 0;
	sort(all(post), sortinrev); 
	rep(i, 0, int(graph.size() - 1))
		cout << "first" << post[i].first << " " << "second" << post[i].second << " " ;

	rep(i, 0, int(graph.size()-1))
		if(!discovered[post[i].second])
		{
			explore(post[i].second, graph);
			count ++;
		}
	return count;

}




int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector <int> > graph(n+1);
	vector < vector <int> > graphr(n+1);

	rep(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graphr[y].push_back(x);
	}

	rep(i, 0, int(MAX+1))
		post[i].second = pre[i].second = i;

	rep(i, 1 , n+1)
		if(!visited[i])
			dfs(i, graphr);

	cout << "The number of strongly connected components are" << scc(graph) << endl;
}

