#include <iostream>

using namespace std;

int getLenSeq(string str, int index){
    if (index>str.size()-1) return index; ///not sure if corrent of if matters
    int iter = index;
    char seq_letter = str[iter];
    while (iter<str.size() && str[iter] == seq_letter){
        iter++;
    }
    return iter;
}
#include <unordered_map>


int popping(string str, int index,unordered_map<string,int>& strs){
    if (str.size()==0) return 1;
    if (index >= str.size()-1) return 0;
    if (strs.find(str)!=strs.end()) {
        return strs[str];
    }
    int i = index;
    while (i<str.size()){
        int end_curr_seq = getLenSeq(str, i);
        if ((end_curr_seq - i)>=2){
            if (popping((str.substr(0,i)+str.substr(end_curr_seq)), 0,strs) || popping(str, end_curr_seq+1, strs)){
                strs[str] = 1;
                return 1;
            }
            i = end_curr_seq;
            continue;
        }
        i++;
    }
    strs[str] = 0;
    return 0;
}


int main(int argc, const char * argv[]) {
    int num_tests;
    cin >> num_tests;
    for (int i =0 ; i<num_tests;i++){
        string curr;
        cin >> curr;
        unordered_map<string, int> strs;
        cout << popping(curr, 0, strs) << endl;
    }
    return 0;
}
