#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<limits.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<set>
#include<stack>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define INF 2147483647
#define EPS 1e-9


struct point { double x, y;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)                 // useful for sorting
            return x < other.x;          // first criteria , by x-coordinate
        return y < other.y; }          // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

// Return positive if p-q-r are clockwise, neg if ccw, zero if colinear.
double orientation(point p, point q, point r) {
    return (q.y-p.y)*(r.x-p.x) - (q.x-p.x)*(r.y-p.y);
}

double dist(point p1, point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

// Graham scan to find upper and lower convex hulls of a set of 2d points.
pair<vector<point>, vector<point>> hulls(vector<point> points) {
    vector<point> U;
    vector<point> L;
    sort(points.begin(), points.end());
    for (auto p : points) {
        while (U.size() > 1 && orientation(U[-2], U[-1], p) <= 0) U.pop_back();
        while (L.size() > 1 && orientation(L[-2], L[-1], p) >= 0) L.pop_back();
        U.push_back(p);
        L.push_back(p);
    }
    return {U, L};
}

// Given a list of 2d points, finds all ways of sandwiching the points
// between two parallel lines that touch one point each, and yields the sequence
// of pairs of points touched by each pair of lines.
vector<pair<point, point>> rotatingCalipers(const vector<point>& points) {
    auto UL = hulls(points);
    auto U = UL.first;
    auto L = UL.second;

    vector<pair<point, point>> pairs;

    int i = 0;
    int j = L.size() - 1;
    while (i < U.size() - 1 || j > 0) {
        pairs.emplace_back(U[i], L[j]);

        // if all the way through one side of hull, advance the other side
        if (i == U.size()-1) j--;
        else if (j == 0) i++;
            // still points left on both lists, compare slopes of next hull edges
            // being careful to avoid divide-by-zero in slope calculation
        else if ((U[i+1].y-U[i].y)*(L[j].x-L[j-1].x) >
                 (L[j].y-L[j-1].y)*(U[i+1].x-U[i].x)) i++;
        else j--;
    }
    return pairs;
}

///*****convex hull*****
struct PT
{
    double x,y;

    // compare the lexicographic order of 2 points
    // first compare x, if 2 x's are equal, compare y
    bool operator < (const PT& _p) const
    {
        if (fabs(x - _p.x) > EPS) {
            return (x < _p.x);
        } else {
            return (y < _p.y);
        }
    }
};
// check p3 (leftmost) -> p2 -> p1 (rightmost) left turn (not right turn)
bool left(PT& p1, PT& p2, PT& p3)
{
    double cross = (p2.x - p3.x) * (p1.y - p3.y) - (p2.y - p3.y) * (p1.x - p3.x);

    if (fabs(cross) <= EPS)
        return true;    // to delete p2
    if (cross > 0)
        return true;
    return false;
}
vector<PT> convex_hull(vector<PT>& Points) {

    PT p;
    //-------------- incremental alg. ---------
    // upper hull
    sort(Points.begin(), Points.end());
    stack<PT> stk_up;
    stk_up.push(Points[0]);
    stk_up.push(Points[1]);
    for (int i=2; i<Points.size(); i++) {
        while ((stk_up.size() >= 2)) {
            PT p2, p3;
            p2 = stk_up.top();
            stk_up.pop();
            p3 = stk_up.top();
            if (!left(Points[i], p2, p3)){
                stk_up.push(p2);
                break;
            }
        }
        stk_up.push(Points[i]);
    }
    // lower hull
    for (int i=0; i<Points.size(); i++) {
        Points[i].x = -Points[i].x;
        Points[i].y = -Points[i].y;
    }
    sort(Points.begin(), Points.end());
    stack<PT> stk_low;
    stk_low.push(Points[0]);
    stk_low.push(Points[1]);
    for (int i=2; i<Points.size(); i++) {
        while ((stk_low.size() >= 2)) {
            PT p2, p3;
            p2 = stk_low.top();
            stk_low.pop();
            p3 = stk_low.top();
            if (!left(Points[i], p2, p3)){
                stk_low.push(p2);
                break;
            }
        }
        stk_low.push(Points[i]);
    }

    // print convex hull - cw order from leftmost point
    vector<PT> CH;
    stk_low.pop();
    while (!stk_low.empty()) {
        p = stk_low.top();
        p.x = -p.x;
        p.y = -p.y;
        CH.push_back(p);
        stk_low.pop();
    }
    stk_up.pop();
    PT temp;
    while (!stk_up.empty()) {
        temp = stk_up.top();
        CH.push_back(temp);
        stk_up.pop();
    }
    reverse(CH.begin(), CH.end());  // ccw -> cw
    return CH;
}
///*****convex hull*****

//this function transfer vector of PT to vector of points
vector<point> prepareCalipers(vector<PT> con_hull){
    vector<point> ans;
    for (PT pt:con_hull){
        struct point temp;
        temp.x = pt.x;
        temp.y = pt.y;
        ans.push_back(temp);
    }
    return ans;
}


void checkMinDist (vector<pair<point, point>> ans){
    double max=0;
    double distance;
    for (pair<point, point> pp:ans){
        distance=dist(pp.first, pp.second);
       if(distance>max)max=distance;
    }
    double res=max/double(2);
    printf("%lf",res);
    cout<<endl;
}

/*
int main(){
    ll N,R;
    while (cin >> N >> R){
        vector<PT> points;
        double temp_x,temp_y;
        for (int i = 0 ; i< N; i++){
            cin>>temp_x>>temp_y;
            struct PT temp;
            temp.x = temp_x;
            temp.y = temp_y;
            points.push_back(temp);
        }
        vector<PT> con_hull = convex_hull(points);
        vector<point> Calipers_points=prepareCalipers(con_hull);
        vector<pair<point, point>> ans=rotatingCalipers(Calipers_points);
        checkMinDist(ans);
    }
    return 0;
}
*/