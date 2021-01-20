#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>

#define EPS 1e-5
#define MAX_SIZE 100

using namespace std;

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


bool IsIn(PT p, vector<PT>& resL) {
    //the polygon must have at least 3 points
    if(resL.size()<3){
        return false;
    }


}

int NumPoints(vector<PT>& resL, vector<PT>& Small) {
    int size = Small.size(), counter = 0;
    for(int i = 0; i < size; i++) {
        if(IsIn(Small[i], resL) == true){
            counter++;
        }
    }
    return counter;
}

void Do(int L) {
    vector<PT> Large;
    double x, y;
    for(int i = 0; i < L; i++) {
        cin >> x >> y;
        struct PT temp;
        temp.x = x;
        temp.y = y;
        Large.push_back(temp);
    }
    vector<PT> Small;
    int S;
    cin >> S;
    for(int i = 0; i < S; i++) {
        cin >> x >> y;
        struct PT temp;
        temp.x = x;
        temp.y = y;
        Small.push_back(temp);
    }
    vector<PT> resL = convex_hull(Large);
    cout << NumPoints(resL, Small) << endl;
}


/*
int main() {
    int L;
    while(scanf("%d", &L) != EOF) Do(L);
    return 0;
}
*/