#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#include <iomanip>
#define INF 2147483647
#define EPS 1e-5
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> pdd;
typedef vector<pdd> vdd;

#include <stdio.h>

double dist(double p1_x, double p1_y, double p2_x, double p2_y) {   // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return (pow(p1_x - p2_x,2)+ pow(p1_y - p2_y, 2)); }           // return double

long double findClosest(vdd& points){
    long double min_len = INF;
    long double curr_min_len =INF;
    for (int i = 0 ; i< points.size(); i++){
        for (int j = i+1 ; j< points.size(); j++){
            long double curr_len = dist(points[i].first,points[i].second, points[j].first, points[j].second);
            curr_min_len = min(curr_min_len, curr_len);
        }
        min_len = min(min_len,curr_min_len);
    }
    return  min_len;
}

/*
int main(){
    int N;
    while (cin >> N){
        if (N==0) break;
        vdd  points;
        double temp_x,temp_y;
        for (int i = 0 ; i< N; i++){
            cin>>temp_x>>temp_y;
            points.push_back({temp_x,temp_y});
        }
        sort(points.begin(),points.end());
        long double res = findClosest(points);
        res=sqrt(res);
        if (res > 10000 || abs(res-10000)< EPS){
            cout << "INFINITY" << endl;
        }else{
            double ans=double (res);
            printf("%.4lf\n",ans);
        }
    }
    return 0;
}
*/



