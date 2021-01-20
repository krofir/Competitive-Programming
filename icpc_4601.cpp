
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <iomanip>
#define EPS 1e-6
#define MAX_SIZE 100

using namespace std;


double Surface(vector<double> X, vector<double> Y) {
    double S = 0;
    int n = X.size();
    for(int i = 0; i < X.size(); i++) {
        S += (X[i] * Y[(i+1)%n] - X[(i+1) % n] * Y[i]);
    }
    if(S < 0) S *= -1;
    return (0.5 * S);
}

/*
int main() {
    while(true) {
        vector<double> X;
        vector<double> Y;
        bool all_zero = true;
        for(int i = 0; i < 6; i++) {
            double tempX, tempY;
            cin >> tempX >> tempY;
            if(tempX != 0 || tempY != 0) all_zero = false;
            X.push_back(tempX);
            Y.push_back(tempY);
        }
        if(all_zero) break;
        vector<double> DEF_X = {X[3], X[4], X[5]};
        vector<double> DEF_Y = {Y[3], Y[4], Y[5]};
        double S_DEF = Surface(DEF_X, DEF_Y) * 0.5;
        vector<double> abc_x = {X[0], X[1], X[2]};
        vector<double> abc_y = {Y[0], Y[1], Y[2]};
        double S_abc = Surface(abc_x,abc_y);
        while(S_abc < S_DEF) {
            double d_x = X[2] - X[0];
            double d_y = Y[2] - Y[0];
            X[2] += d_x;
            Y[2] += d_y;
            abc_x = {X[0], X[1], X[2]};
            abc_y = {Y[0], Y[1], Y[2]};
            S_abc = Surface(abc_x,abc_y);
        }
        double Hx = 0.5 * (X[0] + X[2]);
        double Hy = 0.5 * (Y[0] + Y[2]);
        vector<double> temp_x = {X[0], X[1], Hx};
        vector<double> temp_y = {Y[0], Y[1], Hy};
        double S = Surface(temp_x, temp_y);
        double high_x = X[2], low_x = X[0], high_y = Y[2], low_y = Y[0];
        while(abs(S - S_DEF) > EPS) {
            if(S < S_DEF) {
                low_x = Hx;
                low_y = Hy;
            }
            else {
                high_x = Hx;
                high_y = Hy;
            }
            Hx = (low_x + high_x) / 2;
            Hy = (low_y + high_y) / 2;
            temp_x[2] = Hx;
            temp_y[2] = Hy;
            S = Surface(temp_x, temp_y);
        }
        double diff_x = Hx - X[0];
        double diff_y = Hy - Y[0];
        double Gx = X[1] + diff_x;
        double Gy = Y[1] + diff_y;
        printf("%.3f", Gx);
        cout <<  " ";
        printf("%.3f", Gy);
        cout <<  " ";
        printf("%.3f", Hx);
        cout <<  " ";
        printf("%.3f", Hy);
        cout << endl;
    }
    return 0;
}
*/