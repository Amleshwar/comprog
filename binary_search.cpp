
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
int binary_search(const vector <int> numbers, int num, int low, int high)
{
	if(high < low)
		return -1;
	else
	{
	int med = (low + high)/2;
	if(numbers[med] == num)
		return med;
	else if(numbers[med] > num)
		return binary_search(numbers, num, low, med - 1);
	else
		return binary_search(numbers, num, med + 1, high);
	}
}

int main()
{
	int n;
	cout << "enter the number of elements" << endl;
	cin >> n;
	vector <int> numbers(n);
	cout << "Enter the number :" << endl;
	rep(i, 0, n)
		cin >> numbers[i];

	cout << "Enter the numbers u want to search " << endl;
	//vector <int> num(n);
	//
	//rep(i, 0, n)
	//	cin >> num[n];
	
	//rep(i , 0, n)
	////	cout << "The number is found at position :" << binary_search(numbers, num[i], 0, n-1)<<endl;
	int num;
	cin >> num;
	cout << binary_search(numbers, num, 0, n - 1);

}
