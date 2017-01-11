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
vi parent(MAX);
vi drank(MAX);

struct Query
{
	string type;
	int x, y;
};

struct union_find
{
	int req;
	vi p, r;
	union_find(int n, int m)
	: p(n, -1), r(n, -1)
	{ 
		req = m;
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

	int find(int x)
	{
		if(parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}
	
	void unite(int x, int y)
	{
		int x_id, y_id;
		x_id = find(x);
		y_id = find(y);
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
		return find(x) == find(y);
	}

	Query readQuery() const
	{
		Query query;
		cin >> query.type;
		if(query.type == "u")//u stands for union
			cin >> query.x >> query.y;
		else if(query.type == "c")//c stands for connected
			cin >> query.x >> query.y;
		else //The last case is that of find
			cin >> query.x;

		return query;
	}

	void processQuery(const Query & query)
	{
		if(query.type == "u")
			unite(query.x, query.y);
		else if(query.type == "c")



	
	
	
	}

};

