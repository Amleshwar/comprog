
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

int long_sub(string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();
	int opt[m+1][n+1];
	rep(i, 0, m+1)
		opt[i][0] = 0;
	rep(i, 0, n+1)
		opt[0][i] = 0;

	rep(i, 1, m+1)
		rep(j, 1, n+1)
		{
			int k = j;
			int flag = 0;
			while(k > 0)
			{
				if(s1[i-1] == s2[k-1])
				{
					opt[i][j] = opt[i-1][k - 1] + 1;
					flag = 1;
					break;			
				}
				else 
					k--;
			}
			if(flag == 0)
				opt[i][j] = opt[i-1][j];
		}
	return opt[m][n];
}

int main()
{
	string s1, s2;
	cout << "Enter the first string" << endl;
	cin >> s1;
	cout << "Enter the second string" << endl;
	cin >> s2;
	cout << "The length of longest common subsequence is :" << long_sub(s1, s2);
}
