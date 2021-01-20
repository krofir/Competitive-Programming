#include <vector>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector< vector<int> > vvi; // unweighted graph
typedef vector< vector< pair<int,int> > > vvii; // weighted graph

const int INF = 1e9;

bool checkSymmetry(vi& X,vi& Y,int n){
    double x_coord=(X[0]+X[n-1])/2;
    double y_coord=(Y[0]+Y[n-1])/2;
    double temp_x,temp_y;
    int i=0,j=n-1;
    while (i<j){
        temp_x=(X[i]+X[j])/2;
        temp_y=(Y[i]+Y[j])/2;
        if(temp_x!=x_coord || temp_y!=y_coord){
            return false;
        }
        i++;
        j--;
    }
    if(i==j){
        if(X[i]!=x_coord || Y[i]!=y_coord){
            return false;
        }
    }
    return true;
}

void getInput(vi& X,vi& Y,int n){
    int temp_x,temp_y;
    for (int i=0;i<n;i++){
        cin>>temp_x>>temp_y;
        X.push_back(temp_x);
        Y.push_back(temp_y);
    }
}

int main() {
    int num_tests;
    int n;
    cin>>num_tests;
    while(num_tests--){
        cin>>n;
        vi X;
        vi Y;
        getInput(X,Y,n);
        if(n==1 || n==2){
            cout<<"yes"<<endl;
            continue;
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        if (checkSymmetry(X,Y,n)){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
