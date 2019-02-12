//
// Created by user on 1/22/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define MAX 1000007
using namespace std;
char firstRecurringCharacter(const vector <char> data) {
    vector < int > count(MAX, 0);
    rep(i, 0, data.size()) {
        if(count[data[i]] > 0)
            return data[i];
        else
            count[data[i]]++;
    }
    return '\\';
}

int main() {
    string data;
    cin >> data;
    char dataInArray[data.length() + 1];
    strcpy(dataInArray, data.c_str());
    rep(i, 0, data.length())
        cout << "char : " + dataInVector[i];

}
