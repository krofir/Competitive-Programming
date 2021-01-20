#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits.h>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi; // unweighted graph
typedef vector< vector< pair<int,int> > > vvii; // weighted graph
const int INF = 1e9;

//this function count how much operations we need to free the wanted parent dool
//for put there the current dool , and change the dools in the way to be free to
ll countAndChangeTofreeParent(int parent_index,vi& initial){
    ll sum=0;
    int temp_index;
    if(initial[parent_index]==0){
        return 0;
    }
    while(initial[parent_index]!=0){
        sum+=1;
        temp_index=initial[parent_index];
        initial[parent_index]=0;
        parent_index=temp_index;
    }
    return sum;
}

ll SOLVE(vi& initial,vi& target,int n){
    ll sum=0;
    for (int i=1;i<n+1;i++){
        if(initial[i]!=target[i]){
            //after this the current parent is zero:current parent doll is free
            int curr_parent=initial[i];
            int target_parent=target[i];
            if(curr_parent!=0){
                sum+=countAndChangeTofreeParent(curr_parent,initial);
                initial[i]=0;
                sum+=1; //take current doll to be free
            }
            if(target_parent==0) {
                continue;
            }
            //after this the target parent will be free - so we can put there the current doll
            sum+=countAndChangeTofreeParent(target_parent,initial);
            initial[i]=target[i];
            sum+=1; //take current doll and insert to the target parent
        }
    }
    return sum;
}

int main() {
    int n;
    int temp;
    while (scanf("%d", &n) != EOF){
        ll sum=0;
        vi initial(n+1,0); //include zero
        vi target(n+1,0); //include zero
        for(int i=1;i<n+1;i++){
            cin>>temp;
            initial[i]=temp;
        }
        for(int i=1;i<n+1;i++){
            cin>>temp;
            target[i]=temp;
        }
        sum=SOLVE(initial,target,n);
        cout<<sum<<endl;
    }
    return 0;
}



