#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include <limits.h>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector< vector<int> > vvi; // unweighted graph
typedef vector< vector< pair<int,int> > > vvii; // weighted graph

const int INF = 1e9;

/********** Dijkstra **********/
// input: digraph (g), source (s)
// output: distances from s (dist)
void Dijkstra(const vector<vii>& g, int s, vi& dist) {
    dist = vi(g.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ii front = q.top(); q.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // We may have found a shorter way to get to u after inserting it to q.
        // In that case, we want to ignore the previous insertion to q.
        for (ii next : g[u]) {
            int v = next.first, w = next.second;
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                q.push({dist[v], v});
            }
        }
    }
}


//get M weighted edges -and build the digraph with them reversed.
void buildGraph(vvii& graph, unsigned int M){
    int u,v,time;
    ii pair ;
    for(int i=0;i<M;i++){
        cin >> u >> v >>time ;
        pair = make_pair(u-1,time);
        graph[v-1].push_back(pair);
    }
}

int countMices(unsigned int T,vi& dist){
    int size=dist.size();
    int counter=0;
    //only the mice that start in the exit cell Will succeed to exit.
    if (T==0){
        return 1;
    }else {
        for(auto time:dist){
            if(time<=T){
                counter++;
            }
        }
    }
    return counter;
}

int Solve(){
    unsigned int N,E,T,M;
    int counter=0;
    cin>>N>>E>>T>>M;
    vvii graph(N,vector< pair<int,int> >());
    vi dist;
    buildGraph(graph,M);
    //run Dijkstra from the exit cell - E .
    E--;//the numbers of the cells is between 1..N so cell x is in index x-1;
    Dijkstra(graph,E,dist);
    counter=countMices(T,dist);
    return counter;
}

int main() {
    int num_tests;
    string blank;
    cin>>num_tests;
    getline(cin,blank);
    while(num_tests--){
        int answer=Solve();
        cout<<answer<<endl;
        if(num_tests!=0){
            cout<<endl;
        }
        getline(cin,blank);
    }
    return 0;
}
