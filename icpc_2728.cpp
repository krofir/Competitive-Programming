#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <limits.h>
#include <tuple>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<vi> vvi;

#define INF INT_MAX


ll calculateMinWaitingTime(int N,int T,vi& travel_times,vi& depart_from_first,
                            vi& depart_from_last){
    vvi waiting_times(N, vi(T+1,INT_MAX));
    waiting_times[0][0]=depart_from_first[0];
    for (int l=1; l<N; l++){
        for (int t=0; t<=T; t++){
            waiting_times[l][t] = min(min(waiting_times[l][t-1]+1,
                                      waiting_times[l-1][t-travel_times[l-1]]),
                                      waiting_times[l+1][t-travel_times[l+1]]);
        }
    }
    ll ans = waiting_times[N-1][T];
}

void Solve(int N,int T,int case_num){
    vi travel_times;
    vi depart_from_first;
    vi depart_from_last;
    int temp_input;
    int M1,M2;
    for(int i=1;i<N;i++){
        cin>>temp_input;
        travel_times.push_back(temp_input);
    }
    cin>>M1;
    for(int i=0;i<M1;i++){
        cin>>temp_input;
        depart_from_first.push_back(temp_input);
    }
    cin>>M2;
    for(int i=0;i<M2;i++){
        cin>>temp_input;
        depart_from_last.push_back(temp_input);
    }
    ll ans=calculateMinWaitingTime(N,T,travel_times,depart_from_first,depart_from_last);
    cout<<"Case Number "<<case_num<<": "<<ans<<endl;
}

/*
int main() {
    int N,T;
    int case_num=1;
    cin>>N;
    while(N!=0){
        cin>>T;
        Solve(N,T,case_num++);
        cin>>N;
    }
    return 0;
}*/