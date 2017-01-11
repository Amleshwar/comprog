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
typedef vector < vector < pair < int, double > > > gds;

double d[MAX] = {0};
gds formGraph(vii & p);
double dist(ii & p1, ii & p2);
double mst(gds  & g);

struct union_find
{
	vi p, r;
	union_find(int n)
	: p(n, -1), r(n, -1)
	{ 
		make_set(n);
	};

	void make_set(int n)
	{
		rep(i, 0, n)
		{
			p[i] = i;
			r[i] = 0;
		}
	}

	int fin(int x)
	{
		if(p[x] != x)
			p[x] = fin(p[x]);
		return p[x];
	}
	
	void unite(int x, int y)
	{
		int x_id, y_id;
		x_id = fin(x);
		y_id = fin(y);
		if(r[x_id] < r[y_id])
			p[x_id] = y_id;
		else
		{
			p[y_id] = x_id;
			if(r[x_id] == r[y_id])
				r[x_id] = r[x_id]+1;
		}
	}

	bool connected(int x, int y)
	{
		return fin(x) == fin(y);
	}
};

gds formGraph(vii & p)
{
 	int n = (int)(p.size());
 	gds g(n);
 	cout << endl;
 	rep(i, 0, n)
 		rep(j, 0, n)
 			if(i != j)
 			{
 				cout << dist(p[i], p[j]) << endl;
 				g[i].push_back(make_pair(j, dist(p[i], p[j])));
 			
 			}
 	return g;
}

double dist(ii & p1, ii & p2)
{
	double param = pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2);
	return sqrt(param);
}

double mst(gds  & g)
{
	double res = 0;
	union_find uf((int(g.size())));
	vector < pair < double, ii> > e;
	rep(i, 0, (int)(g.size()))
		tr(g[i], it)
			e.push_back(make_pair(it->second, make_pair(i, it->first)));
	set < pair < double, ii > > es(all(e));
	cout << endl;
	tr(es, it)
		cout << ((*it).second).first << "->  "<< ((*it).second).second << " 	" << (*it).first << endl;
	cout << endl;
	tr(es, it)
	{
		int u, v;
		double	cost;
		u = ((*it).second).first;
		v = ((*it).second).second;
		cost = (*it).first;
		
		if(!uf.connected(u, v))
		{
			res += cost; 
			uf.unite(u, v);
		}
	}

	return res;
}

int main()
{
	int n;
	cin >> n;
	vii points(n);
	rep(i, 0, n)
		cin >> points[i].first >> points[i].second;
	gds graph = formGraph(points);
	cout << endl << mst(graph) << endl;
}
