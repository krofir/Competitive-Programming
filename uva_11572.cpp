#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
/*
int main(){
    set<int> how_much;
    set<int>::iterator itr1;
    unordered_map<int, int> indeces;// <number,index>
    unordered_map<int, int>::iterator itr2;
    int temp=0;
    int prev;
    int curnet_size=0;
    int first_index_seria=1;
    int num_of_tests, batch=0;
    cin>>num_of_tests;
    int count=0;
    int max_size=0;
    for(int i=0;i<num_of_tests;i++) {
        cin>>batch;
        for(int j=0;j<batch;j++) {
            cin>>temp;
            itr1=how_much.find(temp);
            if(itr1 == how_much.end()){
                count++;
                how_much.insert(temp);
                indeces[temp]=count;
                curnet_size++;
                max_size=max(max_size,curnet_size);
                continue;
            }
            else {
                count++;
                prev=indeces.find(temp)->second;
                indeces[temp]=count;
                if(first_index_seria>prev){
                    curnet_size++;
                    max_size=max(max_size,curnet_size);
                }else{
                    first_index_seria=prev+1;
                    curnet_size=count-prev;
                    max_size=max(max_size,curnet_size);
                }
            }

        }
        cout<<max_size<<endl;
        max_size=0;
        first_index_seria=1;
        how_much.clear();
        indeces.clear();
        curnet_size=0;
    }
    return 0;
}
*/