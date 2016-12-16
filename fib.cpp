#include <iostream>
#include <string>
using namespace std;

long long fib(int n)
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
			arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
		}
				
		return arr[n];
	}

}

int main()
{
	cout << "Enter the number" << endl;
	int n;
	cin >> n;
	long long result;
	result = fib(n);
	cout << "The result is " << result << endl; 

}


