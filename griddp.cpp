//
// Created by user on 1/25/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
using namespace std;
typedef vector < int > vi;
typedef vector < vector < int > > vvi;

int optimalPathValue(vvi & data) {
    int n = data.size();
    int m = data[0].size();
    vvi opt(n, vi(m, 0));
    opt[0][0] = data[0][0];
    rep(i, 1, n)
        opt[i][0] = opt[i-1][0] + data[i][0];

    rep(i, 1, m)
        opt[0][i] = opt[0][i-1] + data[0][i];

    rep(i, 1, n) {
        rep(j, 1, m) {
            opt[i][j] = data[i][j] + max(opt[i-1][j], opt[i][j-1]);
        }
    }
    return opt[n-1][m-1];
}

int main() {
    int n, m;
    string s;
    cin >> s;
    s+='w';
    vector <char> v(s);
    s = s.substr(0, 5);
    cout << s << endl;

    cout << s.size() << s[s.size() - 3];
    /*cin >> n >> m;
    vvi data(n, vi(m, 0));
    rep(i, 0, n)
        rep(j, 0 , m)
            cin >> data[i][j];

    cout << "The optimal path is : " << optimalPathValue(data);*/
}