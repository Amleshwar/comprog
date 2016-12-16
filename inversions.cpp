
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

int countInversions(vector <int>& numbers, int low, int high)
{
	if(high <= low)
		return 0;
	else if((high - low) == 1)
	{
		if(numbers[low] > numbers[high])
			return 1;
		else 
			return 0;
	}
	else
	{
		int medium = (high+low)/2;

	
	
	
	
	}






}























