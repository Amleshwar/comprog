
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

vector <int>* calculator(int n);

void findsolution(int n, vector <int> opt)
{
	if(n == 0)
	{
			cout << 0 << " ";
			return;
	
	}
	else
	{
		if(n % 2 == 0 && n % 3 == 0)
		{
			if(opt[n/2] < opt[n/3])
			{
				cout << n/2 << " ";
				return;			
			}
		
		
		
		
		}


	
	
	
	
	
	
	
	
	
	
	}
}

int min3(int a, int b, int c)
{
	if(a <= b && a <= c)
		return a;
	else if(b <= a && b <= c)
		return b;
	else
		return c;

}


vector <int>* calculator(int n)
{
	vector <int>* opt= new vector<int>(n+1);
	vector <int> numbers;
	if(n == 0)
	{
		return opt;

	}
	else
	{
		(*opt)[0] = 0;
		(*opt)[1] = 0;
		rep(i, 2, n+1)
		{
			if((i%2 == 0) && (i%3 == 0))
				(*opt)[i] = min3((*opt)[i - 1], (*opt)[i/2], (*opt)[i/3]) + 1;
			else if(i % 3 == 0)
				(*opt)[i] = min((*opt)[i - 1], (*opt)[i/3]) + 1;
			else if(i % 2 == 0)
				(*opt)[i] = min((*opt)[i - 1], (*opt)[i/2]) + 1;
			else
				(*opt)[i] = (*opt)[i - 1] + 1;
		
		}
		return opt;
	}
}

int main()
{
	int n;
	cout << "Enter the number that you want to calculate : " << endl;
	cin >> n;
	vector <int> opt = *calculator(n);
	rep(i , 0, n+1)
		cout << opt[i] << "  ";
	cout << "The min number of operations " << opt[n]; 
}

