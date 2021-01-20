#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;
#define PI acos(-1.0)
double w, h, l, theta;

void Do() {
    double tg_theta = (tan(theta * PI / 180));
    double delta_h = tg_theta * l;
    if(delta_h <= h) {
        double remaining_volume = l * (h - delta_h / 2) * w;
        printf("%.3f", remaining_volume);
        cout << " mL" << endl;
    } else {
        double tg_theta = (tan((90 - theta) * PI / 180));
        double remaining_volume = h * tg_theta * (h / 2) * w;
        printf("%.3f", remaining_volume);
        cout << " mL" << endl;
    }
}
/*
int main() {
    while(cin >> l >> w >> h >> theta) Do();
    return 0;
}*/