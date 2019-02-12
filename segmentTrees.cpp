//
// Created by user on 1/30/2019.
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

        tree[node] = data[left];
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

void update(int k, int x) {
    // updating kth value of the data by x
    data[k] += x;
    k += data.size();
    tree[k] += x;
    k /= 2;

    while(k > 1) {
        tree[k] = tree[2*k] + tree[2*k + 1];
        k /=2;
    }
}

void rangeUpdate(int left, int right, int x) {

}




int main() {
    int n;
    cin >> n;
    tree = vi(2*n+1, 0);
    data = vi(n, 0);
    diffTree = vi(2*n+1, 0);
    diffData = vi(n, 0);

    rep(i, 0 ,n) {
        cin >> data[i];
    }

    buildTree(1, 0 , data.size() -1);
    updateTest();

}

void queryTest() {
    int left, right;
    cout << "Enter the left and right to your queries : " << endl;
    cin >> left  >> right ;
    cout << "the sum to left and right are : " << query(left, right);
}

void updateTest() {
    cout << "The index which you want to increase: " << endl ;
    int k;
    cin >> k;
    cout << "Enter how much you want to increase it by : "  << endl;
    int x;
    cin >> x;
    update(k, x);
    rep(i, 0, data.size())
        cout << data[i] << " : " ;
    cout << endl;
    rep(i, 0, tree.size())
        cout << tree[i] << " : "  ;
    cout << endl;

}