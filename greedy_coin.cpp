#include <iostream>

using namespace std;

int minCoin(int m)
{
	if(m == 1 || m == 5 || m == 10)
		return 1;
	else 
	{
		int foobar = m;
		int deno = 0;
		deno  += foobar/10;

		foobar = foobar % 10;
		deno = deno + foobar/5;
		foobar = foobar % 5;
		deno += foobar;
		return deno; 
	}
}


int main()
{
	int m;
	cout << "Enter the sum: " << endl;
	cin >> m;
	cout << "The in number of denomination is :" << minCoin(m) << endl;
}
