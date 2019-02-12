//
// Created by user on 1/23/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto i = container.begin(); i != container.end(); i++)
using namespace std;
typedef vector<int> vi;
int binaryValidSearch(vi & data);

bool valid(int num, int data) {
    return num == data;
}
int binaryValidSearch(int num, vi & data) {
    int a = -1;
    for(int b = data.size(); b >= 1; b /= 2) {
        while(!valid(num, data[a+b]))
             a += b;
    }
    return a+1;
}
int main() {
    int n = 5;
    /*cin >> n;
    vi data(n);
    rep(i, 0, n)
        cin >> data[i];
    */
    vi data(n);
    data.push_back(9);

    data.push_back(4);
    data.push_back(3);
    data.push_back(1);
    data.push_back(5);

    cout << "Enter the element to search: " << endl;
    int num;
    cin >> num;
    cout <<"The position of element is : "  << binaryValidSearch(num, data) << endl;
}
