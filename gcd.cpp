#include <iostream>
#include <math.h>
using namespace std;
int gcd(int m, int n)
{
	if(n == 0)
		return m;
	else
	{
		return gcd(n , m % n);
	}
}


int main()
{
	int n, m;
	cout << "Enter the numbers that you want to calc gcd of :" << endl;
	cin >> m >> n;
	int gcde  = gcd(m, n);
	cout << "The GCD is " << gcde << endl;
	int lcm;
	lcm =(m*n)/gcde;
    cout << "The LCM is " << lcm << endl;	
}
