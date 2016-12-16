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
#include <string.h>
#include <stdio.h>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
using namespace std;


void outputAlignment(int i, int j, vector < vector<int> >& opt, string s1, string s2);

int min3(int a, int b, int c)
{
	if(a <= b && a <= c)
		return a;
	else if(b <= a && b <= c)
		return b;
	else
		return c;

}

void outputAlignment(int i, int j, vector < vector<int> >& opt, string s1, string s2)
{
	if(i == 0 && j == 0)
		return;
	else
	{
		if(i > 0 && (opt[i][j] == (opt[i - 1][j] + 1)))
		{
			outputAlignment(i - 1, j, opt, s1, s2);
			cout << s1[i - 1] << "| *" << ":::" ;
		}
		else if(j > 0 && (opt[i][j] == (opt[i][j-1] + 1)))
		{
			outputAlignment(i, j-1, opt, s1, s2);
			cout << "* |" << s2[j - 1] << ":::" ;
		}
		else
		{
			outputAlignment(i-1, j-1, opt, s1, s2);
			cout << s1[i - 1] << "|" << s2[j-1] << ":::" ;
		}
	}
}

	
int editDistance(const string s1, const string s2)
{

	int m = s1.length();
	int n = s2.length();
	int opt[m+1][n+1];
	rep(i, 0, m+1)
		opt[i][0] = i;

	rep(j, 0, n+1)
		opt[0][j] = j;


	rep(i, 1, m+1)
		rep(j, 1, n+1)	
		{
			if(s1[i - 1] == s2[j - 1])
				opt[i][j] = min3(opt[i-1][j-1], (opt[i-1][j]+1), (opt[i][j-1]+1));
			else
				opt[i][j] = min3((opt[i-1][j-1]+1), (opt[i-1][j]+1), (opt[i][j-1]+1));
			
		}
	vector < vector<int> > vecopt(m+1, vector<int>(n+1));
	rep(i , 0, m+1)
		rep(j, 0, n+1)
			vecopt[i][j] = opt[i][j];
	cout << endl;
	outputAlignment(m, n, vecopt, s1, s2);
	return 
		opt[m][n];		

}





int main()
{
	string s1;
	string s2;
	cout << "Enter the first string :" << endl;
	cin >> s1;
	cout << "Enter the second string :" << endl;
	cin >> s2;
	cout << "The edit distance is " << endl << editDistance(s1, s2);

}




