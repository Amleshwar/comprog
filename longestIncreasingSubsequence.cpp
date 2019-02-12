//
// Created by user on 1/24/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
using namespace std;
typedef vector<int> vi;

vi longestIncreasingSubsequence(vi & data) {
    vi lis(data.size(), 0);
    rep(i, 0, data.size()) {
            lis[i] = 1;
            for(auto j = i - 1; j >= 0; j--){
                if(data[j] < data[i-1]) {
                    lis[i] = max(lis[i], lis[j+1] + 1);
                }
            }
        }

    return lis;
}

int main() {
    int n;
    cin >> n;
    vi data(n);
    rep(i, 0, n)
        cin >> data[i];
    vi lis = longestIncreasingSubsequence(data);
      rep(i, 0, n+1)
      cout <<     lis[i] << endl;
}
