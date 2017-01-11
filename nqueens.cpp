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

int counter = 0;
void nqueens(vi & Q, int r)
{
	int n = int(Q.size());
	if(r == n)
	{
		//cout << "c2" << endl;
		rep(i, 0, n)
			cout << Q[i] << "  " ;
		cout << endl;
    	++counter;	
	}
	else
	{
		//cout << "c3" << endl;
		rep(j, 0, n)
		{
			bool legal = true;
			rep(i, 0, r)
			{
			//	cout << "c1" << endl;
				if((Q[i] == j)|| Q[i] == (j - r + i) || Q[i] == (j + r - i))
					legal = false;
			}
				if(legal)
				{
					//cout << "c4" << endl;
					Q[r] = j;
				    nqueens(Q, r+1);	
				}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vi Q(n);
	fill(all(Q), -1);
	rep(i, 0, n)
		cout << Q[i] << " ";
	cout << endl;
	nqueens(Q, 0);
	cout << "The total number of nqueens solutions for n =  " << n << " is : " << counter << endl; 
}
