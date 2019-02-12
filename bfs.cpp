//
// Created by user on 1/26/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
# define N 1000
using  namespace std;
typedef vector < int > vi;
typedef vector < vector < int > > vvi;

vi visited(N, 0);
vi height(N,0);
vvi nodeLevels(N);

void bfs(vvi & graph, int node) {
    visited[node] = 1;
    queue <int> q;
    q.push(node);
    nodeLevels[0].push_back(node);
    while(!q.empty()){
        int nodeBeingExplored = q.front();
        q.pop();
        tr(graph[nodeBeingExplored], it) {
            if(!visited[*it]) {
                height[*it] = height[nodeBeingExplored]+1;
                q.push(*it);
            }
        }
    }
}
#define rep(i, a, b) for(auto i = a; i <b; i++)
typedef vector <int> vi;
typedef vector <vector <int> >;
vector<int> maxone(vector<int> &A, int B) {

    int maxSoFar = numeric_limits <int> :: min();
    int currentMax = numeric_limits <int> :: min();
    vi current;
    int BC = B;
    rep(i, 0, A.size()) {
        if(A[i] == 1){
            currentMax += 1;
            maxSoFar = max(maxSoFar, currentMax);
            current.push_back(i);
        }
        else if(A[i] == 0 && BC > 0) {
            BC--;
            currentMax += 1;
            maxSoFar = max(maxSoFar, currentMax);
        } else {
            current = vi();
            current.push_back(i);
            currentMax = 1;
            BC = --B;
            maxSoFar = max(maxSoFar, currentMax);
        }
    }
    return current;
}


int solve(const vector<int> &A) {
    if(A.size() == 1)
        return 1;
    int maxDiff = 0;
    int maxA = numeric_limits<int> :: min();
    int minA = numeric_limits<int> :: max();
    for(auto i = 0; i < A.size(); i++){
        if(A[i] > maxA)
            maxA = A[i];
        if(A[i] < minA)
            minA = A[i];
    }
    maxDiff = maxA - minA;
    vector < vector <int> > dp(A.size() + 1, (vector<int> (maxDiff+1, 0)));
    for(auto i = 0; i < A.size(); i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    int maxDP = numeric_limits <int> :: min();
    for(auto i = 2; i <= A.size() ; i++) {
        int temp = 0;
        for(auto j = 0; j <= maxDiff; j++) {
            for(auto k = i-1; k > 0; k--) {

                if(abs(A[i-1] - A[k-1]) == j)
                    temp = max(temp, 1+dp[k][j]);
            }

            dp[i][j] = temp;
            maxDP = max(temp, maxDP);
        }

    }
/*    rep(i, 0, A.size() + 1)
    {
        rep(j, 0, maxDiff+1)
            cout << dp[i][j] << " : " ;
        cout << endl;
    }*/
    return maxDP;
}


int main() {
    int n , m;
    n = 3, m = 1;
    vi A(n), B(m);
    A[0] = 1;
    A[1] = 3;
    A[2] = 7;
    B[0] = 20;
    cout << "Loda mera: " << solve(A) << endl;
    /*const vector <int> leftSubA(v.begin(), v.begin()+v.size()/2);

    vi v1(v.begin()+ v.size()/2, v.begin() + v.size());
    rep(i, 0, leftSubA.size())
    cout << leftSubA[i] << endl;*/
  /*  vvi graph(n, vi(m, 0));
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    bfs(graph, 0);
    rep(i, 0, n)
        cout << height[i];*/
}