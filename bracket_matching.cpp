#include <string.h>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <stack>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
using namespace std;

int bracket(string s)
{
	int n = s.length();
	stack < pair <char, int> > bal; 

	rep(i, 0, n)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			bal.push(make_pair(s[i], i));
		else
		{
			if(s[i] == ')' && bal.top().first != '(')
				return i;
			else if(s[i] == '}' && bal.top().first != '{')
				return i;
			else if(s[i] == ']' && bal.top().first != '[')
				return i;
			else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
				bal.pop();
		}
	}
	if(bal.empty())
		return -1;
	else
		return bal.top().second;
}

int main()
{
	string s;
	cout << "Enter the string: " << endl;
	cin >> s;
	if(bracket(s) == -1)
		cout << "Success" << endl;
	else
		cout << bracket(s);
}
