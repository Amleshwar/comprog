
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
int countFrequency(const vector <int>& numbers, int n, int low, int high)
{
	int count = 0;
	rep(i, low, high+1)
		if(numbers[i] == n)
			count++;

	return count;
}

int getMajority(const vector <int>& numbers, int low, int high)
{
	if(low == high)
		return numbers[low];
	else
	{
		int med = (high + low)/2;
		int	lhs = getMajority(numbers, low, med);
		int rhs = getMajority(numbers, med + 1, high);
		
		med = (high + low)/2;
		if(lhs == rhs)
			return lhs;
		else
		{
			int	lcount = countFrequency(numbers, lhs, low, high);
			int rcount = countFrequency(numbers, rhs, low, high);
			if(lcount == rcount && lcount <= (med - low + 1))
				return -1;
			else if(lcount >= ((med - low)+1))	
				return lhs;
			else if(rcount >= (med - low + 1))
				return rhs;
			else 
				return -1; 
		}
	}
}

int main()
{
	int n;
	cout << "Enter the number of elements:" << endl;
	cin >> n;
	cout << "Now enter the elements: " << endl;
	vector <int> numbers(n);
	rep(i, 0, n)
		cin >> numbers[i];
	cout << "The majority element is " << getMajority(numbers, 0, n-1) << endl;
}

