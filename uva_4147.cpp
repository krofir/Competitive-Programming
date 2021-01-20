#include <algorithm>
#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;
/*
int main(){
    bitset<1024> b_set1;
    bitset<1024> b_set2;
    bool temp1;
    bool temp2;
    int num_tests;
    int N;
    int M;
    int counter_W_O=0;
    unsigned int player_out;
    int curr_size=0;
    cin>>num_tests;
    for(int i=0;i<num_tests;i++) {
        b_set1.set();
        cin>>N>>M;
        curr_size=pow(2,N);
        for(int j=0;j<M;j++){
            cin>>player_out;
            b_set1.set(player_out-1,0);
        }
        if(b_set1.all()){
            cout<<0<<endl;
            continue;
        }
        else{
            while(curr_size>1){
                for (int k=0;k<curr_size;k+=2){
                    temp1=b_set1.test(k);
                    temp2=b_set1.test(k+1);
                    if(temp1 && temp2){
                        b_set2.set((k/2),1);
                    }else if((temp1 && !temp2)|| (!temp1 && temp2)){
                        counter_W_O++;
                        b_set2.set((k/2),1);
                    }else{
                        b_set2.set((k/2),0);
                    }
                }
                b_set1=b_set2;
                b_set2.reset();
                curr_size=curr_size/2;
            }
        }
        cout<<counter_W_O<<endl;
        counter_W_O=0;
    }
    return 0;
}
 */