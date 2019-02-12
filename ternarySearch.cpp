//
// Created by user on 1/27/2019.
//
#include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vi;
int ternarySearch(vi & data, int left , int right) {
    // cout << data[left] << " ; "  << data[right] << endl;
    int b = (left + 2*right)/3;
    int a = (right + 2*left)/3;
   // cout << "Left is : " << left << " Right is : " << right << endl;
   // cout << "Element a is : " << a << " Element b is : " << b << endl;
    if(right - left < 4) {
        int tempMin = numeric_limits <int> :: max();
        rep(i, left, right)
            tempMin = min(data[i], tempMin);
        return tempMin;
    }
    if(data[a] < data[b])
        ternarySearch(data, left, b);
    else if(data[a] > data[b])
        ternarySearch(data, a, right);
    else
        return data[a];
}

int main() {
    int n;
    cin >> n;
    vi data(n);
    rep(i, 0, n)
        cin >> data[i];

    cout << "The ternary search element is : " << ternarySearch(data, 0, n-1);
}