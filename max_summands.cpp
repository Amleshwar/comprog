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
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
using namespace std;

vector <int> max_summand(const int n)
{
	vector <int> numbers;
	if(n == 1)
	{
		numbers.push_back(1);
		return numbers;
	}
	else if(n == 2)
	{
		numbers.push_back(2);
		return numbers;
	}
	else
	{
		int rem = n;
		int current = 1;
		while(rem > 0)
		{
			if(rem > 2*current) 
			{
				numbers.push_back(current);
				rem -= current;
				current ++;
			}
			else
			{
				numbers.push_back(rem);
				rem = 0;
			}
		
		}		
		return numbers;
	}
}

int main()
{
	int n;
	cout << "Enter the number that you want :" << endl;
	cin >> n;
	vector <int> summands = max_summand(n);

	cout << "The maximum number of summands is :" << summands.size() << endl;
	int length = summands.size();
	rep(i, 0 , length)
		cout << summands[i] << " ";
	cout << endl;
	int sum = 0;
	rep(i, 0, length)
		sum += summands[i];
	
	cout << "Verification: " << sum << endl;


}








