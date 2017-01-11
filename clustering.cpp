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
#define eps 1e-6
#define inf 1000000007
using namespace std;
typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef pair < int, int > ii;
typedef vector < pair < int, int  > > vii;
typedef vector < vector < ii > > vvii;
typedef vector < vector < pair < int, double > > > gds;
gds formGraph(vii & p);
double dist(ii & p1, ii & p2);
double cluster(gds  & g);


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
 				g[i].push_back(make_pair(j, dist(p[i], p[j])));
 	return g;
}


double dist(ii & p1, ii & p2)
{
	double param = pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2);
	return sqrt(param);
}



double cluster(gds  & g, int k)
{
	int n = (int)(g.size());
	double high = inf;
	double low = 0.0;	
	double med = (high+low)/2;
	int count = 0;
	while(true)
	{
		count++;
		cout << count << "  " << med  << endl;
		
		if((med - low) < eps)
			return med;
		int ncom = n;
		union_find uf(n);
		vector < pair < double, ii> > e;
		rep(i, 0, n)
			tr(g[i], it)
				e.push_back(make_pair(it->second, make_pair(i, it->first)));

		set < pair < double, ii > > es(all(e));
		tr(es, it)
		{
			int u, v;
			double cost;
			u = ((*it).second).first;
			v = ((*it).second).second;
			cost = (*it).first;
		
			if(!uf.connected(u, v))
			{
				if(ncom == k && cost < med)
				{
					high = med;
					med = (low + med)/2;
					break;
				}
				else if(ncom == k && cost >= med)
				{
					low = med;
					med = (med + high)/2;
					break;
				}
				else 
				{
					uf.unite(u, v);
					ncom -= 1;
				}
			}
		}
	}
	return med;
}

int main()
{
	int n;
	cin >> n;
	vii points(n);
	rep(i, 0, n)
		cin >> points[i].first >> points[i].second;
	int k;
	cin >> k;
	gds graph = formGraph(points);
	cout << endl << cluster(graph, k) << endl;
}






















