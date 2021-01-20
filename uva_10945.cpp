#include <iostream>
#include <string>
using namespace std;
/*
int main() {
    string sen;
    while (true){
        getline(cin,sen);
        if (sen == "DONE"){
            break;
        }
        int start=0;
        int end=sen.size()-1;
        int flag=0;
        while(start!=end && start < end){
            if(!isalpha(sen[start])){
                start++;
                continue;
            }
            if(!isalpha(sen[end])){
                end--;
                continue;
            }
            if (char(tolower(sen[start])==char(tolower(sen[end])))){
                start++;
                end--;
                continue;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"You won't be eaten!"<<endl;
        }
        else{
            cout<<"Uh oh.."<<endl;
        }

    }
    return 0 ;
}
*/