//
// Created by user on 2/3/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
# define X first
# define Y second
using namespace std;
typedef long long C;
typedef vector < int > vi;
typedef pair <long, long> point;

struct event {
    int type;
    point p1, p2;
    event(point p1, point p2, int type) :p1(p1), p2(p2), type(type){};
};

bool compare(event e1, event e2) {
    return (e1.p1.X < e2.p1.X);
}


point swappedCoordinate(point p) {
    return {p.Y, p.X};
}
void findIntersection(vector<event> & events) {
    set<point> orderedEvents;
    rep(i, 0, events.size()) {
        event e = events[i];
        if(e.type == 0) {
            cout << e.p1.first << " : " << e.p2.second << endl;
            orderedEvents.insert(swappedCoordinate(e.p1));
        } else if(e.type == 1) {
            orderedEvents.erase(swappedCoordinate(e.p2));
        } else {
            int minC = min(e.p1.Y, e.p2.Y);
            int maxC = max(e.p1.Y, e.p2.Y);
            cout << "Min : "  << minC << " Max : " << maxC << endl;
           tr(orderedEvents, it) {
               cout << "Point : " << (*it).X << " : " << (*it).Y << endl;
               if((*it).X > minC && (*it).X < maxC)
                   cout << "the point of intersections are :  " << (*it).X << " : " << e.p1.X << endl;
           }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector <event> events;
    int counter = 0;

    rep(i, 0, n) {
       int x1, y1, x2, y2;
       cin >> x1 >> y1 >> x2 >> y2;
       point p1, p2;
       p1 = {x1, y1};
       p2 = {x2, y2};
       if(p1.X == p2.X)
           events.emplace_back(event(p1, p2, 2));
       else {
           events.emplace_back(event(p1, p2, 0));
           events.emplace_back(event(p2, p1, 1));
       }
    }
    sort(events.begin(), events.end() , compare);
    rep(i, 0, events.size()) {
        cout << "the event is : " << events[i].type << " points : " << events[i].p1.first << " -- " << events[i].p2.first << endl;
    }
    findIntersection(events);

}