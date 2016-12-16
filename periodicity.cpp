#include <iostream>
#include <string>
#include <vector>
using namespace std;


long long fib(int n, int m)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		long long arr[n+1];
		arr[0] = 0;
		arr[1] = 1;
		for(int i = 2; i < n+1; i++)
		{
			arr[i] = (arr[i - 1] + arr[i - 2]) % m;
		}
				
		return arr[n];
	}

}



int periodicity(int m)
{
	if(m == 1)
		return -1;
	else
	{
		int store, col, result;
		store = col = result = 0;
		vector <int> vi;
		vi.push_back(0);
		vi.push_back(1);
		
		for(long long i = 2; i < 999999999999999; i++)
		{
			vi[i] = (vi[i-1] + vi[i - 2]) % m;
			if(vi[i - 1] == 0 && vi[i] == 1)
			{
				result = i - 1;
				break;
			}
		}	
		return result;
	}
}


int sum(int n, int m, int period)
{
	int res = 0;
	for(int i = m; i < n + 1; i++)
	{
		res = res + fib(i % period, 10);
		res = res % 10;
	}	
	
	return res;
}

int main()
{
	long long n, m;
	cout << "Enter the number bro: " << endl;
	cin >> n >> m;
	int period = periodicity(10);
	cout << "The period is: " << period << endl;
	cout << "The answer is : " << sum(n, m , period) << endl; 
} 
