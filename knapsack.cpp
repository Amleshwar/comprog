

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

int knapsack(int W, int n, const vector<int>& weights)
{
	int opt[n+1][W+1];
	rep(i, 0, n+1)
		opt[i][0] = 0;

	rep(i, 0, W+1)
		opt[0][i] = 0;

	rep(i, 1, n + 1)
		rep(j, 1, W + 1)
		{
			if((j - weights[i - 1]) >= 0)
			{
				opt[i][j] = max(opt[i - 1][j], opt[i - 1][j - weights[i - 1]] + weights[i - 1]);
				cout << opt[i][j] << "case 1: "  << endl;
			
			}
			else
			{
				opt[i][j] = opt[i - 1][j];  
				cout << opt[i][j] << "case 2 : " << endl;
			}

		}

	return opt[n][W];
}

int main()
{
	int n, W;
	cout << "Enter the number of elements and the maximum weight : " << endl;
	cin >> W >> n;

	vector <int> weights(n);
	cout << "Enter the weights of the n elements " << endl;
	rep(i, 0, n)
		cin >> weights[i];
	cout << "The optimal weight is :" << knapsack(W, n, weights) << endl;
}
