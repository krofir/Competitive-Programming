#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <cmath>
#define PI 3.14159265
#define EPS 1e-5
#define MAX_SIZE 100

using namespace std;
typedef long double ld;
typedef vector<ld> vd;
typedef vector< vector<int> > vvi; // unweighted graph


bool isInt(ld num) {
    ld temp=round(num);
    if(abs(temp-num)<EPS){
        return true;
    }else return false;
}

ld calculateAngle(int first_index,int right_index,int left_index,vd& X,vd& Y){
    ld a_x=0;
    ld a_y=0;
    ld b_x=0;
    ld b_y=0;
    a_x=X[first_index]-X[right_index];
    a_y=Y[first_index]-Y[right_index];
    b_x=X[first_index]-X[left_index];
    b_y=Y[first_index]-Y[left_index];
    ld a_norm=(a_x*a_x)+(a_y*a_y);
    a_norm=sqrt(a_norm);
    ld b_norm=(b_x*b_x)+(b_y*b_y);
    b_norm=sqrt(b_norm);
    ld a_b=(a_x*b_x)+(a_y*b_y);
    ld angle=acos(a_b/(a_norm*b_norm));
    return angle;
}

void findAngles(vd& angles,vd& X,vd& Y){
    ld angle;
    angle=calculateAngle(0,1,2,X,Y);
    angles.push_back(angle);
    angle=calculateAngle(1,2,0,X,Y);
    angles.push_back(angle);
    angle=calculateAngle(2,0,1,X,Y);
    angles.push_back(angle);
}

void Solve(vd& X,vd& Y) {
    vd angles;
    findAngles(angles,X,Y);
    ld K1=angles[0]/(PI);
    ld K2=angles[1]/(PI);
    ld K3=angles[2]/(PI);
    bool flag=false;
    for(int n=3;n<1001;n++){
        if(isInt(K1*n) && isInt(K2*n) && isInt(K3*n)){
            cout<<n<<endl;
            flag=true;
            break;
        }
    }
    if(!flag){
        cout<<"1000"<<endl;
    }
}


int main() {
    string line;
    cin>>line;
    long double temp_x,temp_y;
    while(line!="END"){
        vd X;
        vd Y;
        temp_x = std::stold(line);
        cin>>temp_y;
        X.push_back(temp_x);
        Y.push_back(temp_y);
        for(int i=0;i<2;i++){
            cin>>temp_x>>temp_y;
            X.push_back(temp_x);
            Y.push_back(temp_y);
        }
        Solve(X,Y);
        cin>>line;
    }
    return 0;
}