//
// Created by user on 1/23/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
using namespace std;
typedef vector <int> vi;
int addOneToNumber(vi & num) {
    int number = 0;
    rep(i, 0, num.size())
        number += num[i]*pow(10, num.size() - i);
    return number+1;
}
int main() {
    int n;
    cin >> n;
    vi num(n, 0);
    rep(i, 0, n)
        cin >> num[i];

    string s = to_string(addOneToNumber(num));
    cout << "number added by 1: " << s << endl;

}