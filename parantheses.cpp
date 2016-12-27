#include <string.h>
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
using namespace std;

int max_val(string s)
{
	int n = s.length();
	cout << "length " << n << endl;
	int opt[n][n];
	rep(i, 0, n)
		rep(j, 0, n)
			opt[i][j] = 0;

	for(int i = 0; i < n; i+=2)
		opt[i][i] = s[i] - '0';

	cout << "Reache prior to for " << endl;
	for(int i = 0; i < n; i+=2)
		for(int j = i+2; j < n; j+=2)
		{
			vector <int> v;
			for(int k = i; k < j; k+=2)
			{
				if(s[k+1] == '+')
					v.push_back(opt[i][k] + opt[k+2][j]);
				else if(s[k + 1] == '-')
					v.push_back(opt[i][k] - opt[k+2][j]);
				else
					v.push_back(opt[i][k] * opt[k+2][j]);
			}
			rep(i, 0, int(v.size()))
				cout << v[i] << " " ;
			opt[i][j] = *max_element(all(v));
		}
	cout << "Reached Return " << endl;
	return opt[0][n-1];
}

int main()
{
	string s;
	cout << "Enter the string" << endl;
	cin >> s;
	cout << "The maximum value is " << max_val(s) << endl;
}
