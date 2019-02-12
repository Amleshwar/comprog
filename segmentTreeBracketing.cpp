//
// Created by user on 2/8/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define MAX 10000
using namespace std;
typedef vector <int> vi;
vi tree;
vi data;
vi diffData;
vi diffTree;

void updateTest();
void queryTest();


void buildTree(int node, int left, int right) {
    cout  << node << " : " << left << " : " << right << endl;
    if(left >= right) {
        tree[node] = 1;
        return;
    }

    int mid  = left + (right-left)/2;
    buildTree(2*node, left, mid);
    buildTree(2*node+1, mid+1, right);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int left, int right) {
    int n = data.size();
    left += n; right += n;
    int sum = 0;
    while(left <= right) {
        if(left%2 == 1) sum += tree[left++];
        if(right % 2 == 0) sum += tree[right--];
        left /= 2; right /= 2;
    }
    return sum;
}
