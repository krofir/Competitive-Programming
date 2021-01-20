#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <limits.h>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

/*
int main() {
    int n,t;
    while (scanf("%d", &n) != EOF){
        vll W(3,0); // (white,yellow,pink)
        vll H(3,0); // (white,yellow,pink)
        vll S(3,0); // (white,yellow,pink)
        for(int i=0;i<n;i++){
            cin>>t;
            W[i%3]+=t;
        }
        for(int i=0;i<n;i++){
            cin>>t;
            H[i%3]+=t;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                S[(i+j)%3]+=W[i]*H[j];
            }
        }
        // print in order (yellow,pink,white)
        cout<<S[1]<<" "<<S[2]<<" "<<S[0]<<endl;
    }
    return 0;
}
*/