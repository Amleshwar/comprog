#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
  //cin >> a;
  //cin >> b;
  //sum = a + b;
  vector < pair <int, int> > vpii(5);
  for(int i = 0; i < 5; i++)
	  cin >> vpii[i].first >> vpii[i].second;
  sort(vpii.begin(), vpii.end());
  for(int i = 0; i < 5; i++)
	cout << vpii[i].first << "  " << vpii[i].second << endl;
  return 0;
}


