#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>

using namespace std;
#define EPS 1e-6

typedef vector<int> vi;

string KMP_str; // The string to search in
string KMP_pat; // The pattern to search
vi lps;

//KMP--------------------------------------------------------------------------

// KMP Init
void KMP_init(){
    int m = KMP_pat.length();
    lps.resize(m,0);
    lps[0]=-1;
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && (KMP_pat[i] != KMP_pat[j])) j = lps[j];
        i++; j++;
        lps[i] = j;
    }
}

// Search a pattern in a string
// Assuming lps is allready initialized with KMP_init
int KMP_search() {
    int counter=0;
    int n = KMP_str.length();
    int m = KMP_pat.length();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && (KMP_str[i] != KMP_pat[j])) j = lps[j];
        i++; j++;
        if (j == m) { // Pattern found
            //cout << "The pattern is found at index " << i-j << endl;
            j = lps[j];
            counter++;
        }
    }
    return counter;
}
//KMP--------------------------------------------------------------------------


void Do(string s) {
    KMP_str = s + s;
    KMP_pat = s;
    KMP_init();
    int sum=KMP_search();
    cout<<sum-1<<endl;
}
/*
int main() {
    string s;
    while(cin >> s) {
        if(s == ".") break;
        Do(s);
    }
    return 0;
}*/
