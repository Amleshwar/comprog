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
#define push_back pb
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define MAX 1000
#define epsilon 1e-7
using namespace std;

typedef vector <int> vi;
typedef vector < vector <int> > vii;

struct point
{
	double x, y;

	bool operator < (const point& p) const
	{
		if(x < (p.x - epsilon))
			return true;
		if(x > (p.x + epsilon))
			return false;
		if(y < (p.y -epsilon))
			return true;
		if(y > (p.y + epsilon))
			return false;

		return false;
	}
};

int main()
{
	int n;
	cout << "Enter the number of elements:" << endl;
	cin >> n;
	vi v(n);//way of initializing vector
	cout << "Enter the elements: " << endl;
	rep(i, 0, n)
		cin >> v[i];
	set <int> s(all(v));
	vi v1(all(s));//A smart way to sort and unique a vector v
	tr(v1, it)
		cout << *it << "  ";
	int m;
	cout << "Enter the number of elements in the second vector:" << endl;
	cin >> m;
	vi v2(m);	
	cout << "Enter the elements again" << endl;
	rep(i , 0, m)
		cin >> v2[i];
	

	set <int> s2(all(v2));
	vi v3(all(s2));
	vi v7(all(v3));
	tr(v3, it)
		cout << *it << "  "; 
	cout << endl;
	//Let us copy the vector v1 to the end of v3 using copy(from_begin, from_end, to_begin);
	v3.resize(v1.size() + v3.size());
	copy(all(v1), v3.end() - v1.size());
	tr(v3, it)
		cout << *it << " " ;
	cout << endl;
	set <int> s3(all(v3));
	vi v4(all(s3)); // A subtle to way to take union first take 2 sets then copy both of them to a vector and take set on that
	tr(v4, it)
		cout << *it << "  " ;

	cout << endl;
	vi a1(all(v1));
	vi a2(all(v7));
	vi temp(max(v1.size(), v2.size()));
	vi res = vi(temp.begin(), set_intersection(all(a1), all(a2), temp.begin()));
	cout << endl;
	tr(res, it)
		cout << *it << "  " ;
	cout << endl;
	int cnt = temp.begin() -  set_intersection(all(a1), all(a2), temp.begin());
	cout << "The number of elements in the set_intersection are" << cnt << endl;
	//Now time to define the intersection along with set union:::
}
