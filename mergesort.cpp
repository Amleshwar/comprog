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


void mergesort(vector <int> &numbers, int low, int high)
{
	if(high <= low)
		return ;
	else
	{
		int med = (high + low)/2;
		mergesort(numbers, low, med);
		mergesort(numbers, med + 1, high);


		cout << endl;
	}
}

void merge(vector <int> &numbers, int low, )
int main()
{
	int n;
	cout << "Enter the number of elements you want: " << endl;
	cin >> n;
	vector <int> numbers(n);
	cout << "Enter the numbers that you want to sort: " << endl;
	rep(i , 0, n)
		cin >> numbers[i];

	numbers = mergesort(numbers, 0, n-1);

	rep(i, 0, n)
		cout << numbers[i] << "   " ;

	cout << endl;
}
