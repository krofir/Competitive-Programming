#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>

using namespace std;

bool IsBigger(pair<int, int> a, pair<int,int> b) {
    /*int maxA = a.first > a.second ? a.first : a.second;
    int minA = a.first < a.second ? a.first : a.second;
    int maxB = b.first > b.second ? b.first : b.second;
    int minB = b.first < b.second ? b.first : b.second;*/
    //return a.first >= b.first && a.second >= b.second ;

    if(a.first >= b.first && a.second >= b.second) return true;
    return false;
}

bool IsSmall(pair<int, int> a, pair<int,int> b) {
    return (a.first < b.first && a.second < b.second);
}

void Do(int num_cubes) {
    vector<pair<int,int>> a;
    for(int i = 0; i < num_cubes; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        a.push_back(pair<int,int>(temp1, temp2));
    }
    sort(a.begin(), a.end());/*, IsBigger);*/

    vector<int> LIS(num_cubes,1);
    for (int i=1; i<num_cubes; i++) {
        for (int j = 0; j < i; j++)
            if (IsBigger(a[i], a[j]))
                LIS[i] = max(LIS[i], LIS[j] + 1);
    }
    int max_num = -1;
    for(int k = 0; k < num_cubes; k++) {
        //max_num = max(max_num, LIS[k]);
        max_num = (max_num > LIS[k]) ? max_num : LIS[k];
    }
    cout << max_num << endl;
}

int main() {
    int num_cubes;
    cin >> num_cubes;
    while(num_cubes != 0) {
        Do(num_cubes);
        cin >> num_cubes;
    }
    cout << "*" << endl;
    return 0;
}