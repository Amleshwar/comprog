//
// Created by user on 1/24/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin; it != container.end(); it++)
using namespace std;
typedef vector < int > vi;
int minCoinSum(int sum, vi & coins);

int minCoinSum(int sum, vi & coins) {
    vi opt(sum+1, 0);
    rep(i, 1, sum+1) {
        int tempMin = numeric_limits <int> :: max();
        rep(j, 0, coins.size())
            if(i - coins[j] >= 0)
                tempMin = min(opt[i-coins[j]]+1, tempMin);
        opt[i] = tempMin;
    }
    return opt[sum];
}

int main() {
    int n, sum;
    cin >> n >> sum;
    vi coins(n, 0);
    rep(i, 0, n)
        cin >> coins[i];
    cout << "Min coins required are: " << minCoinSum(sum, coins);
}