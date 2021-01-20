#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    priority_queue< pair< int, int > , vector< pair< int, int> >, greater< pair< int, int > > >queries ;
    unordered_map<int, int> periodes_by_number; // <number,period>
    int Q_num;
    int period;
    int K;
    int temp_period;
    pair<int, int> top;
    string reg;
    cin>>reg;
    if(reg != "Register"){
        return 0;
    }
    while(reg!="#"){
        cin>>Q_num>>period;
        queries.push(make_pair(period,Q_num));
        periodes_by_number[Q_num]=period;
        cin>>reg;
        if(reg != "Register" && reg != "#"){
            return 0;
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        top=queries.top();
        cout<<(top.second)<<endl;
        temp_period=periodes_by_number.find(top.second)->second;
        queries.pop();
        queries.push(make_pair(((top.first)+temp_period),top.second));
    }
    return 0;
}


