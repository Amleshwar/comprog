#include <vector>
#include <iostream>
#include <math.h>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <algorithm>	
#define all(c) c.begin(), c.end() 
//#define tr(container, it) 	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 


using namespace std;

double knapsack(const int n, const int W,	const vector < pair <int, int> >& vpii)
{
	vector < pair <double, int> > kp(n);	

	for(int i = 0; i < n; i++)
	{
		kp[i].second = i;
		kp[i].first = vpii[i].first/vpii[i].second; 
	}

	sort(all(kp));
	for(int i = 0; i < n; i++)
		cout << kp[i].first << "  " << kp[i].second << endl; 

	int rem_weight = W;
	double result = 0;
	int counter = n - 1;
	while(rem_weight > 0)
	{
		int cand = kp[counter].second;
		if(vpii[cand].second <= rem_weight)
		{
			rem_weight -= vpii[cand].second;
			result += vpii[cand].first;
			counter--;
		}
		else
		{
			double z = ((double)rem_weight/(double)vpii[cand].second)*vpii[cand].first;
			result += z;
			break;
		}
	
	}
    return result;	
}


int main()
{
	int n, W;
	cout << "Enter the number of items:" << endl;
	cin >> n;
	cout << "Enter the maximum weight" << endl;
	cin >> W;
	cout << "Now enter the values and weights:" << endl;	
	vector < pair <int, int> > vpii(n);
	for(int i = 0; i < n; i++)
		cin >> vpii[i].first >> vpii[i].second;

	cout << "The maximum loot is :" << endl;
	cout.precision(4);
	printf("%.4f\n", knapsack(n, W, vpii));

}
