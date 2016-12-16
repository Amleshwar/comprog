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

pair <int, int> rearrange(vector <int> & numbers, int low, int high)
{
	int n = (high - low + 1);
	int pivot = low + (int)(rand()%n);

	swap(numbers[low], numbers[pivot]);
	int c1, c2;
	c1 = c2 = low + 1;
	rep(i, low + 1, high + 1)
	{
		if(numbers[c1] <= numbers[low])
		{
			swap(numbers[c1], numbers[c2]);
			c1++; 
			c2++;
		}
		else
			c1++;
	}	
	c2--;
	swap(numbers[low], numbers[c2]);

	c1 = c2;	
	rep(i, low, c2)
	{
		if(numbers[i] == numbers[c2])
		{
			--c1;
			swap(numbers[i], numbers[c1]);
		}
	}
	
   pair <int, int> ii;
	ii.first = c1;
	ii.second = c2;	

	return ii;
}

void quicksort(vector <int> & numbers, int low, int high)
{
	if((high <= low) )
		return;
	else 
	{
	cout << " the Low and high are : " << low << "   " << high << endl;
	pair <int, int> ii = rearrange(numbers, low, high);
	cout << "REaching post arrange" << endl;
	quicksort(numbers, low, ii.first - 1);
	quicksort(numbers, ii.second + 1, high);	
	}
}

int main()
{
	int n; 
	cout << "Enter the number of elements ::" << endl;
	cin >> n;
	vector <int> numbers(n);
	cout << "Enter the numbers: " << endl;
	rep(i, 0, n)
		cin >> numbers[i];

	quicksort(numbers, 0, n - 1);
	//rearrange(numbers, 2, 0 , n);
	cout <<" The numbers after sorting are " << endl;

	rep(i, 0, n)
		cout << numbers[i] << "  " ;

	cout << endl;	
}

