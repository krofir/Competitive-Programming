#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <limits.h>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<char> sc;
typedef vector< vector<int> > vvi; // unweighted graph
typedef vector< vector< pair<int,int> > > vvii; // weighted graph
typedef unordered_map<char,int> mapsUpper; //map index to every uppercase letters.
typedef unordered_map<char,int>::iterator mapIter;
mapsUpper map_letters; ///global variable

void help(vs& words,vvi& graph,sc& set_letters);

/********** topological sort **********/
// input: a graph (g)
// output: is g a DAG (return value), a topological ordering of g (order)
// comment: order is valid only if g is a DAG
bool topological_sort(const vvi& g, vi& order) {
    // compute indegree of all nodes
    vi indegree (g.size(), 0);
    for (int v=0; v<g.size(); v++) for (int u : g[v]) indegree[u]++;
    // order sources first
    order = vector<int>();
    for (int v=0; v<g.size(); v++) if (indegree[v] == 0) order.push_back(v);
    // go over the ordered nodes and remove outgoing edges,
    // add new sources to the ordering
    for (int i=0; i<order.size(); i++) {
        for (int u : g[order[i]]) {
            indegree[u]--;
            if (indegree[u] == 0) order.push_back(u);
        }
    }
    return order.size()==g.size();
}
/********** topological sort **********/

//this function get a vector and index and check if there is a cell in the vector
//with the value index - if not return true
bool notEdge(vi& vec,int index){
    int size=vec.size();
    if(size==0){
        return true;
    }
    for (int i=0;i<size;i++){
        if (vec[i]==index){
            return false;
        }
    }
    return true;
}


void insertFirstLetters(vvi& graph,vs& lines){
    int size=lines.size();
    mapIter iter;
    if(size==0){
        return;
    }
    char c1=lines[0][0];
    char c2;
    int index1,index2;
    for(int i=1;i<size;i++){
        c2=lines[i][0];
        if(c1!=c2){
            iter=map_letters.find(c1);
            index1=iter->second;
            iter=map_letters.find(c2);
            index2=iter->second;
            if(notEdge(graph[index1],index2)){
                graph[index1].push_back(index2);
            }
            c1=c2;
        }
    }
}

//this function get all the words that starts with the same letter
void AddToGraph(vs& words,vvi& graph,sc& set_letters){
    int size=words.size();
    if(size<=1){
        return;
    }
    vs new_words;
    string sub;
    for(int i=0;i<size;i++){
        sub = words[i];
        if(sub.size()==1){
            continue;
        }
        sub = words[i].substr(1);
        new_words.push_back(sub);
    }
    help(new_words,graph,set_letters);
}

void help(vs& words,vvi& graph,sc& set_letters){
    insertFirstLetters(graph,words);
    int num_words=words.size();
    char c1=words[0][0];
    char c2;
    vs new_words;
    for(int i=0;i<num_words;i++){
        c2=words[i][0];
        set_letters.insert(c2);
        if(c1==c2){
            new_words.push_back(words[i]);
        }else{
            AddToGraph(new_words,graph,set_letters);
            new_words.clear();
            c1=c2;
            i--;
        }
    }
    if(words.size()>0){
        AddToGraph(new_words,graph,set_letters);
        words.clear();
    }
}

void print(vi& order,sc& set_letters){
    unsigned int size= order.size();
    set<int> setindex;
    vi answer;
    for(auto letter:set_letters){
        setindex.insert(map_letters[letter]);
    }
    for(int i=0;i<size;i++){
        if(setindex.find(order[i])==setindex.end()){
            continue;
        }
        answer.push_back(order[i]);
    }
    size=answer.size();
    for(int i=0;i<size;i++){
        cout<<char(65+answer[i]);
    }
    cout<<endl;
}

int Solve(vs& lines){
    unsigned int size= map_letters.size();
    vvi graph(size, vector<int>());
    sc set_letters;
    help(lines,graph,set_letters);
    vi order(0,size);
    topological_sort(graph,order);
    print(order,set_letters);
    return 0;
}

void buildMap(mapsUpper& map_letters){
    int counter=0;
    int size='Z'-'A'+1;
    char str;
    for(int i=0;i<size;i++){
        str=char('A'+counter);
        map_letters[str]=counter;
        counter++;
    }
}

int main() {
    string line;
    buildMap(map_letters);
    while (cin >> line){
        vs lines;
        while(line != "#"){
            lines.push_back(line);
            cin >> line;
        }
        Solve(lines);
    }
    return 0;
}
