//
// Created by user on 2/3/2019.
//

# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end() ; it++)
# define all(container) container.begin(), container.end()
# define X real()
# define Y imag()
using namespace std;
typedef vector <int> vi;
typedef long long C;
typedef complex<C> point;
typedef pair < long , long > coordinate;
bool compare(point p1, point p2){
    return p1.X < p2.X;
}

int crossProduct(point p1, point p2) {
   return (conj(p1)*p2).Y;
}

coordinate complexCoordinate(point p) {
    return {p.X, p.Y};
}
point coordinateToComplex(coordinate c) {
    return {c.first, c.second};
}

stack <point> convexHull(vector <point> & points){
    stack<point> s;
    point pivot = points[0];
    set<pair<int, coordinate>> sortedPolarAngle;
    rep(i, 1, points.size())
        sortedPolarAngle.insert({arg(points[i] - pivot), complexCoordinate(points[i])});
    s.push(pivot);
    s.push(coordinateToComplex((*sortedPolarAngle.begin()).second));
    sortedPolarAngle.erase(sortedPolarAngle.begin());

    tr(sortedPolarAngle, it) {
        point topMost = s.top();
        s.pop();
        point secondTopMost = s.top();
        if(crossProduct((coordinateToComplex((*it).second) - topMost), topMost - secondTopMost) > 0) {
            s.pop();
            s.push(coordinateToComplex((*it).second));
        } else {
            s.push(coordinateToComplex((*it).second));
        }
    }

}

int main() {
    int n = 7;
    vector <point> vp(n);
    vp[0] = {0, 3};
    vp[1] ={2, 2};
    vp[2] ={1, 1};
    vp[3] ={2, 1};
    vp[4] ={3, 0};
    vp[5] ={0, 0};
    vp[6] ={3, 3};
    sort(all(vp), compare);
    stack <point> conHull = convexHull(vp);
    rep(i, 0, conHull.size()) {
        point temp = conHull.top();
        cout << "Point : " << temp.X << " , " << temp.Y << endl;
        conHull.pop();
    }
}

