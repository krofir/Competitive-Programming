#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

const int INF = 1e9;


/********** Max Flow **********/
int augment(vvi& res, int s, int t, const vi& p, int minEdge) {
    // traverse the path from s to t according to p.
    // change the residuals on this path according to the min edge weight along this path.
    // return the amount of flow that was added.
    if (t == s) {
        return minEdge;
    } else if (p[t] != -1) {
        int f = augment(res, s, p[t], p, min(minEdge, res[p[t]][t]));
        res[p[t]][t] -= f;
        res[t][p[t]] += f;
        return f;
    }
    return 0;
}

// input: number of nodes (n), all nodes are between 0 and n-1,
//        edges v1->v2 of the form (weight,(v1,v2)), source (s) and target (t).
// output: max flow from s to t over the edges.
// time: O(VE^2) and O(EF).
int EdmondsKarp (int n, vector<iii>& edges, int s, int t) {
    // initialise adjacenty list and residuals adjacency matrix
    vvi res(n,vi(n,0));
    vvi adj(n);
    for (iii e : edges) {
        res[e.second.first][e.second.second] += e.first;
        adj[e.second.first].push_back(e.second.second);
        adj[e.second.second].push_back(e.second.first);
    }
    // while we can add flow
    int addedFlow, maxFlow = 0;
    do {
        // save to p the BFS tree from s to t using only edges with residuals
        vi dist(res.size(), INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        vi p(res.size(), -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int v : adj[u]) if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
        }
        // add flow on the path between s to t according to p
        addedFlow = augment(res, s, t, p, INF);
        maxFlow += addedFlow;
    } while (addedFlow > 0);
    return maxFlow;
}

/********** Max Flow **********/

struct pupil {
    int height;
    char sex;
    string music_style;
    string favourite_sport;
    pupil(int height,char sex,string music_style,string favourite_sport) {
        this->height=height;
        this->sex=sex;
        this->music_style=music_style;
        this->favourite_sport=favourite_sport;
    }
};


bool eligiblePupils(vector<pupil>& pupils,int i,int j){
    pupil p1=pupils[i];
    pupil p2=pupils[j];
    if(abs(p1.height-p2.height)>40){
        return false;
    }else if(p1.music_style!=p2.music_style){
        return false;
    }else if(p1.favourite_sport==p2.favourite_sport){
        return false;
    }
    else return true;
}

vector<iii> buildGraph(int N,vector<pupil>& pupils){
    vector<iii> graph;
    ii pair;
    for(int i=0;i<N;i++){
        if(pupils[i].sex=='F'){
            pair={N,i};
            graph.push_back({1,pair});
        }else{
            pair={i,N+1};
            graph.push_back({1,pair});
        }
        for(int j=i;j<N;j++){
            if(pupils[i].sex=='F' && pupils[j].sex=='M'){
                if(eligiblePupils(pupils,i,j)){
                    pair={i,j};
                    graph.push_back({1,pair});
                }
            }else if(pupils[i].sex=='M' && pupils[j].sex=='F'){
                if(eligiblePupils(pupils,i,j)){
                    pair={j,i};
                    graph.push_back({1,pair});
                }
            }
        }
    }
    return graph;
}

void find_max_pupils(){
    int N;
    int height;
    char sex;
    string music_style;
    string favourite_sport;
    cin>>N;
    vector<pupil> pupils;
    for(int i=0;i<N;i++){
        cin>>height>>sex>>music_style>>favourite_sport;
        pupils.push_back(pupil(height,sex,music_style,favourite_sport));
    }
    vector<iii> graph=buildGraph(N,pupils);
    int max=EdmondsKarp(N+2,graph,N,N+1);
    cout<<N-max<<endl;
}

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        find_max_pupils();
    }
    return 0;
}
