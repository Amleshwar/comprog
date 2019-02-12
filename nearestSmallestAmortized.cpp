//
// Created by user on 1/27/2019.
//

# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vi;

void nearestSmallerElement(vi & data) {
    stack <int> s;
    s.push(data[0]);
    rep(i, 0, data.size()) {
        if(data[i] >= s.top()) {
            cout << "The element smaller to : " << data[i] << " : " << s.top() << endl;
            s.push(data[i]);
        }
        else {
            while(s.top() > data[i]) {
                s.pop();
            }
            cout << "The element smaller to : " << data[i] << " : " << s.top() << endl;
            s.push(data[i]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vi data(n);
    rep(i, 0, n)
        cin >> data[i];
    nearestSmallerElement(data);
}