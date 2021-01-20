#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

int main(){
    unsigned int num_of_tests;
    unsigned int lakes;
    long temp;
    bool stop_flag;
    unsigned long zeros_in_suffix;
    unsigned long lakes_in_suffix;
    unsigned int days;
    cin>>num_of_tests;
    set<int> zeros_indices;
    set<int>::iterator itr;
    int last_zero_index;
    for(int i=0;i<num_of_tests;i++) {
        stop_flag=false;
        last_zero_index=-1;
        zeros_in_suffix=0;
        lakes_in_suffix=0;
        cin>>lakes>>days;
        vector<int> vect(days);
        vector<int> last_rainy_day(lakes);
        vector<int> answer(days);
        vector<int> full_lakes_indeces(lakes,0);
        for(int j=0;j<days;j++) {
            cin>>temp;
            if(stop_flag){
                continue;
            }
            if(temp==0){
                zeros_in_suffix++;
                last_zero_index=j;
                zeros_indices.insert(j);
                itr=zeros_indices.begin();
            }else{
                lakes_in_suffix++;
            }
            vect[j]=temp;
            if(lakes_in_suffix>zeros_in_suffix){
                stop_flag=true;
                cout<<"NO"<<endl;
                continue;
            }
            if(temp!=0){
                if(full_lakes_indeces[temp-1]>last_zero_index){
                    stop_flag=true;
                    cout<<"NO"<<endl;
                    continue;
                }else{
                    full_lakes_indeces[temp-1]=j;
                }
                if(last_rainy_day[temp-1]==0){
                    itr=zeros_indices.lower_bound(0);
                    last_rainy_day[temp-1]=j;
                }else{
                    itr=zeros_indices.lower_bound(last_rainy_day[temp-1]);
                    last_rainy_day[temp-1]=j;
                }
                if(itr==zeros_indices.end()){
                    stop_flag=true;
                    cout<<"NO"<<endl;
                    continue;
                }
                answer[*itr]=temp;
                zeros_indices.erase(itr);
            }
        }
        if(stop_flag){
            full_lakes_indeces.clear();
            vect.clear();
            answer.clear();
            zeros_indices.clear();
            last_rainy_day.clear();
            continue;
        }
        cout<<"YES"<<endl;
        int count_zeros=0;
        for(int k=0;k<days;k++){
            if (vect[k]==0){
                count_zeros++;
            }
        }
        int count_zeros_again=0;
        for(int k=0;k<days;k++){
            if (vect[k]==0){
                count_zeros_again++;
                if(count_zeros_again==count_zeros){
                    cout<<answer[k]<<endl;
                }else{
                    cout<<answer[k]<<" ";
                }
            }
        }
        full_lakes_indeces.clear();
        vect.clear();
        answer.clear();
        zeros_indices.clear();
        last_rainy_day.clear();
    }
    return 0;
}
