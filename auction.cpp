#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)

#define all(c) c.begin(), c.end() 
using namespace std;

int max_revenue(const int n, vector <int>& pay, vector <int>& ctr)
{
	sort(all(pay));
	sort(all(ctr));
	rep(i, 0, n)
		cout << pay[i] << "  " << ctr[i] << endl;

	int result = 0;
	for(int i = 0; i < n; i++)
		result += pay[i]*ctr[i];

	return result;
}


int main()
{
	int n; 
	
	cout << "Enter the number of slots" << endl;
	cin >> n;
	cout << "Enter the payment values: " << endl;
	vector <int> pay(n);	
	vector <int> ctr(n);

	for(int i = 0; i < n; i++)
		cin >> pay[i];

	cout << "Enter the click through rates:" << endl;

	for(int i = 0; i < n; i++)
		cin >> ctr[i];

	cout << "The result is " << endl;
	cout << max_revenue(n, pay, ctr) << endl;





}
