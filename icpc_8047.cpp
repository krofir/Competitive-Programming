#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits.h>
#include <set>
using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi; // unweighted graph
typedef vector< vector< pair<int,int> > > vvii; // weighted graph
const int INF = 1e9;

void bfs(const vvi& g, int s, vector<int>& d ) {
    queue<int> q; q.push(s);
    vector<bool> visible (g.size(),false);
    visible[s]=true;
    d.assign(g.size(),INF); d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!visible[v]) {
                visible[v] = true;
                d[v] = d[u]+1;
                q.push(v);
            }
    }
}
/*
int main() {
    int m,n;
    char u,v;
    int index1,index2;
    string word1,word2;
    while (scanf("%d%d", &m,&n) != EOF){
        vvi graph(26, vector<int>());
        for(int i=0;i<m;i++){
            cin >> u ;
            cin >> v ;
            index1=int(u)-97;
            index2=int(v)-97;
            graph[index1].push_back(index2);
        }
        for(int i=0;i<n;i++){
            cin >> word1 >> word2 ;
            if(word1.size()!=word2.size()){
                cout<<"no"<<endl;
            }else if (word1==word2){
                cout<<"yes"<<endl;
            }else{
                bool flag = false;
                for (int i=0;i<word1.size();i++){
                    if(word1[i]==word2[i]){
                        continue;
                    }
                    vector<int> distance(26,0);
                    char s = word1[i];
                    int temp=int(s)-97;
                    bfs(graph,temp,distance);
                    s=word2[i];
                    temp=int(s)-97;
                    if(distance[temp]==INF){
                        cout<<"no"<<endl;
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    cout<<"yes"<<endl;
                }
            }
        }
    }
    return 0;
}

*/