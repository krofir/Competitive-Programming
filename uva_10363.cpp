#include <iostream>
using namespace std;

int main() {
    int test_size;
    string grid_first;
    string grid_second;
    string grid_third;
    string empty;
    cin>>test_size;
    for(int i=0;i<test_size;i++){
        int x_win=0,o_win=0; //flags
        int num_0=0,num_x=0;
        cin>>grid_first>>grid_second>>grid_third;
        getline(cin,empty);
        if (grid_first[0]=='X' && grid_first[1]=='X' && grid_first[2]=='X'){
            x_win=1;
        }
        if (grid_second[0]=='X' && grid_second[1]=='X' && grid_second[2]=='X'){
            x_win=1;
        }
        if (grid_third[0]=='X' && grid_third[1]=='X' && grid_third[2]=='X'){
            x_win=1;
        }
        if (grid_first[0]=='X' && grid_second[0]=='X' && grid_third[0]=='X'){
            x_win=1;
        }
        if (grid_first[1]=='X' && grid_second[1]=='X' && grid_third[1]=='X'){
            x_win=1;
        }
        if (grid_first[2]=='X' && grid_second[2]=='X' && grid_third[2]=='X'){
            x_win=1;
        }
        if (grid_first[0]=='X' && grid_second[1]=='X' && grid_third[2]=='X'){
            x_win=1;
        }
        if (grid_first[2]=='X' && grid_second[1]=='X' && grid_third[0]=='X'){
            x_win=1;
        }

        if (grid_first[0]=='O' && grid_first[1]=='O' && grid_first[2]=='O'){
            o_win=1;
        }
        if (grid_second[0]=='O' && grid_second[1]=='O' && grid_second[2]=='O'){
            o_win=1;
        }
        if (grid_third[0]=='O' && grid_third[1]=='O' && grid_third[2]=='O'){
            o_win=1;
        }
        if (grid_first[0]=='O' && grid_second[0]=='O' && grid_third[0]=='O'){
            o_win=1;
        }
        if (grid_first[1]=='O' && grid_second[1]=='O' && grid_third[1]=='O'){
            o_win=1;
        }
        if (grid_first[2]=='O' && grid_second[2]=='O' && grid_third[2]=='O'){
            o_win=1;
        }
        if (grid_first[0]=='O' && grid_second[1]=='O' && grid_third[2]=='O'){
            o_win=1;
        }
        if (grid_first[2]=='O' && grid_second[1]=='O' && grid_third[0]=='O'){
            o_win=1;
        }

        for(int j=0;j<3;j++){
            if(grid_first[j]=='O'){
                num_0++;
            } else if(grid_first[j]=='X') {
                num_x++;
            }
            if(grid_second[j]=='O'){
                num_0++;
            } else if(grid_second[j]=='X') {
                num_x++;
            }
            if(grid_third[j]=='O'){
                num_0++;
            } else if(grid_third[j]=='X') {
                num_x++;
            }
        }
        if(x_win && !o_win && (num_x==num_0+1)){
            cout<<"yes"<<endl;
        }
        else if(o_win && !x_win && (num_x==num_0)){
            cout<<"yes"<<endl;
        }
        else if(!o_win && !x_win && (num_x==num_0 || num_x==num_0+1)){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0 ;
}
