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

/********** Min Spanning Tree **********/


struct unionfind {
    vector<int> rank;
    vector<int> parent;

    unionfind (int size) {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        for(int i=0;i<size;i++) parent[i]=i;
    }

    int find(int x) {
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x) {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember;
        }
        return x;
    }

    void unite(int p, int q) {
        p = find(p);
        q = find(q);
        if(q==p) return;
        if(rank[p] < rank[q]) parent[p] = q;
        else parent[q] = p;
        if(rank[p] == rank[q]) rank[p]++;
    }
};

// input: edges v1->v2 of the form (weight,(v1,v2)),
//        number of nodes (n), all nodes are between 0 and n-1.
// output: weight of a minimum spanning tree.
// time: O(ElogV).
int Kruskal(vector<iii>& edges, int n) {
    sort(edges.begin(), edges.end());
    int mst_cost = 0;
    unionfind components(n);
    for (iii e : edges) {
        if (components.find(e.second.first) != components.find(e.second.second)) {
            mst_cost += e.first;
            components.unite(e.second.first, e.second.second);
        }
    }
    return mst_cost;
}

/********** Min Spanning Tree **********/

int findMinDistance(int num1,int num2){
    int min_dist=0;
    int dig1,dig2;
    for(int i=0;i<4;i++){
        dig1=num1%10;
        dig2=num2%10;
        if(dig1==dig2){
            min_dist+=0;
        }else if(dig1<dig2){
            min_dist+=min(dig2-dig1,dig1+10-dig2);
        }else{
            min_dist+=min(dig1-dig2,dig2+10-dig1);
        }
        num1=num1/10;
        num2=num2/10;
    }
    return min_dist;
}

vector<iii> buildGraph(int N,vi& keys){
    vector<iii> graph;
    int distance;
    ii pair1,pair2;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            distance=findMinDistance(keys[i],keys[j]);
            pair1={i,j};
            pair2={j,i};
            graph.push_back({distance,pair1});
            graph.push_back({distance,pair2});
        }
    }
    return graph;
}

/*
int main() {
    int T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        vi keys;
        int temp;
        int min_distance=INF;
        for(int k=0;k<N;k++){
            cin>>temp;
            min_distance=min(findMinDistance(0,temp),min_distance);
            keys.push_back(temp);
        }
        vector<iii> graph=buildGraph(N,keys);
        cout<<min_distance+Kruskal(graph,N)<<endl;
    }
    return 0;
}
*/