#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    unionfind(int size) {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }
    int find(int x){
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x) {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember; }
        return x;
    }
    void Union(int p, int q){
        p = find(p);
        q = find(q);
        if(q==p)
        {
            return;
        }
        if(rank[p] < rank[q]) parent[p] = q;
        else parent[q] = p;
        if(rank[p] == rank[q])
            rank[p]++;
    }
};

/*
int main(){
    int num_tests;
    cin >> num_tests;
    int num_friends;
    int s1_index;
    int s2_index;
    int s1_orig_group;
    int s2_orig_group;
    int size1;
    int size2;
    int index_uni;
    string s1;
    string s2;
    unordered_map<string, int>:: iterator itr1;
    unordered_map<string, int>:: iterator itr2;
    for (int i = 0; i<num_tests; i++){
        unordered_map<string, int> names;
        unordered_map<int, int> sizes;// <index,size>
        cin >> num_friends;
        unionfind uni(2*num_friends);
        int count = 0;
        for (int j = 0; j<num_friends; j++){
            cin >> s1 >> s2 ;
            //check if in hash
            itr1=names.find(s1);
            itr2=names.find(s2);
            if (itr1 == names.end()){
                names[s1]=count;
                sizes[count]=1;
                count++;
            }
            if (itr2 == names.end()){
                names[s2]=count;
                sizes[count]=1;
                count++;
            }
            //if yes get indexes
            itr1=names.find(s1);
            itr2=names.find(s2);
            s1_index = itr1->second;
            s2_index = itr2->second;
            // union of the two persons
            s1_orig_group = uni.find(s1_index);
            s2_orig_group = uni.find(s2_index);
            if (s2_orig_group == s1_orig_group){
                cout << sizes.find(s2_orig_group)->second << endl;
            }else{
                size1 = sizes.find(s1_orig_group)->second;
                size2 = sizes.find(s2_orig_group)->second;
                uni.Union(s1_index, s2_index);
                index_uni = uni.find(s2_index);
                sizes[index_uni]=size1+size2;
                cout <<size1+size2<< endl;
            }
        }
    }
    return 0;
}

*/