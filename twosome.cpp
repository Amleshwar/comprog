//
// Created by user on 1/22/2019.
//
#include <bits/stdc++.h>
#define rep(i, a, b) for(auto i = a; i < b; i++)
using namespace std;
typedef vector < int  > vi;
bool twoSumExists(vi & data, int sum);

bool twoSumExists(vi & data, int sum) {
    int start, end;
    start = 0;
    end = data.size() - 1;
    while(end > start) {
        if(data[start] + data[end] == sum)
            return true;
        else if(data[start] + data[end] > sum)
            end--;
        else
            start++;
    }
    return false;
}
int main() {
    int n, sum;
    cin >> n >> sum;
    vi data(n);
    rep(i, 0, n)
        cin >> data[i];
    cout << twoSumExists(data, sum);
}
