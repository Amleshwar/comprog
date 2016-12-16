#include <iostream>
#include <string>
#include <vector>
using namespace std;


int huge_fib(int n, int m)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		int result = -1;	
		int arr[20*m];
		arr[0] = 0;
		arr[1] = 1;
		int store = 0;
		int col = 2;						
		for(int i = 2; i < 20*m; i++)
		{
			arr[i] = ((arr[i - 1] + arr[i - 2]) % m);
			if(arr[i - 1] == 0 && arr[i] == 1)
			{
				store = i - 1;
				for(int j = i + 1; 20*m; j++)
				{
					arr[j] = ((arr[j-1] + arr[j-2])%m);
					if(arr[j] == arr[col])
					{
						col++;
						if(col == store)
							result = arr[n % col]; 
						else 
						{
							col = 2;
							break;
						}
					}		
				}
			}		
		}
		return result;
	}
}

int main()
{

	int n, m;
	cout << "Enter the number :" << endl;
	cin >> n;
	cout << "Enter the mod number" << endl;
	cin >> m;
	cout << "The periodicity is ::" << huge_fib(n, m);
	return 0;
}



























