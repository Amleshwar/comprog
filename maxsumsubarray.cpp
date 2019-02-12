//
// Created by user on 1/22/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vi;

int maxSubArraySum(vi & arr);

int maxSubArraySum(vi & arr) {
    int sumSoFar = numeric_limits < int > :: min();
    int bestSoFar = numeric_limits < int > :: min();
    rep(i, 0, arr.size()) {
        if(sumSoFar < arr[i])
            sumSoFar = max(arr[i], sumSoFar + arr[i]) ;
        else
            sumSoFar += arr[i];
        bestSoFar = max(bestSoFar, sumSoFar);
    }
    return bestSoFar;
}

int main() {
    cout << "The size of the array: " << endl;
    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "the max subarray sum is : " <<  maxSubArraySum(arr) << endl;
}
