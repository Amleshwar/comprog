//
// Created by user on 1/27/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
using namespace std;
typedef vector <int> vi;
bool stale(int x, int k, deque <int> q);
void minimumSlidingWindow(vi & data, int k) {
    deque <int> q;
    rep(i, 0, k){
        while(!q.empty() && data[i] <= data[q.back()])
            q.pop_back();
        q.push_back(i);
    }

    rep(i, k , data.size()+1) {
        rep(j, i-k, i){
            cout << "range: " << data[j] << " : " ;
        }
        cout << endl;
        cout << "The min elements is : " << data[q.front()] << endl;
        if(stale(i, k, q))
            q.pop_front();

        while(!q.empty() && data[i] <= data[q.back()])
            q.pop_back();
        q.push_back(i);
    }
}

bool stale(int x,  int k, deque <int> q) {
    return !q.empty() && q.front() < x - k + 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vi data(n);
    rep(i, 0, n)
        cin >> data[i];
    minimumSlidingWindow(data, k);
}