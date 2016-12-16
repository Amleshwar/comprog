#include <iostream>
#include <vector>

using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  int max_ind1 = -1;
  int max_ind2 = -1;

  for(int i = 0; i < n; i++)
  {
	if(max_ind1 == -1 || numbers[max_ind1] < numbers[i])
		max_ind1 = i;
  }


  for(int j = 0; j < n; j++)
  {
	  if(max_ind2 == -1 || (numbers[max_ind2] >= numbers[j] && (j != max_ind1)))
		max_ind2 = j;		
  }
  cout << "First max " << max_ind1 << endl;
  cout << "SEcond Max" << max_ind2 << endl;

  result = ((long long)numbers[max_ind1])*numbers[max_ind2];
  return result;
}


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
