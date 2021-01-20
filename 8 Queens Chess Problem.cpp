#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

///global variable
int test_counter;

void print_header(){
    cout<<"SOLN"<<"       "<<"COLUMN"<<endl;
    cout<<" #      "<<"1 2 3 4 5 6 7 8"<<endl;
    cout<<endl;
}

void print_board(int counter,vector<int>& board){
    if(counter<10){
        cout<<" "<<counter<<"      ";
        for (int i=1;i<=8;i++){
            if(i==8){
                cout<<board[i]<<endl;
            }else{
                cout<<board[i]<<" ";
            }
        }
    }else{
        cout<<counter<<"      ";
        for (int i=1;i<=8;i++){
            if(i==8){
                cout<<board[i]<<endl;
            }else{
                cout<<board[i]<<" ";
            }
        }
    }

}

//this function check if the current board till the current column is legal
//we know that the board is ok with out the current column so we just check the current column
//Depending to prev columns
bool BoardIsValid(vector<int>& curr_board,int cuurent_col){
    if(cuurent_col>8 || cuurent_col<1){
        return false;
    }
    int curr_row=curr_board[cuurent_col];
    for (int i=cuurent_col-1;i>0;i--){
        if(curr_board[i]==curr_row-(cuurent_col-i) && curr_row-(cuurent_col-i)>0){
            return false;
        }else if(curr_board[i]==curr_row+(cuurent_col-i) && curr_row-(cuurent_col-i)<8){
            return false;
        }
    }
    for (int i=cuurent_col+1;i<=8;i++){
        if(curr_board[i]==curr_row-(i-cuurent_col) && curr_row-(i-cuurent_col)>0){
            return false;
        }else if(curr_board[i]==curr_row+(i-cuurent_col) && curr_row-(i-cuurent_col)<8){
            return false;
        }
    }
    return true;
}


//max recursion depth is 8
void SolBoard(vector<int>& board,set<int>& busy_rows,int first_COL,int cuurent_col){
    if(cuurent_col>8){
        if(BoardIsValid(board,8)){
            print_board(test_counter,board);
            test_counter++;
        }
        return;
    }
    if(cuurent_col==first_COL){
        SolBoard(board,busy_rows,first_COL,cuurent_col+1);
    }
    //the board until current column is legal
    vector<int> curr_board=board;
    for (int i=1;i<=8;i++){
        if(busy_rows.find(i)!=busy_rows.end()){
            continue;
        }
        //if the new boars is valid-continue to the next column
        curr_board[cuurent_col]=i;
        if(BoardIsValid(curr_board,cuurent_col)){
            busy_rows.insert(i);
            SolBoard(curr_board,busy_rows,first_COL,cuurent_col+1);
            busy_rows.erase(i);
            curr_board[cuurent_col]=0;
        }else{//if not valid - check another row
            curr_board[cuurent_col]=0;
            continue;
        }
    }
    return;
}


int main() {
    int num_datasets;
    int ROW,COLUMN;
    string blank;
    cin>>num_datasets;
    getline(cin,blank);
    for (int i=0;i<num_datasets;i++){
        test_counter=1;
        vector<int> board(9,0);
        set<int> busy_rows;
        ///the first column is empty to match a real chess board
        cin>>ROW>>COLUMN;
        print_header();
        busy_rows.insert(ROW);
        board[COLUMN]=ROW;
        SolBoard(board,busy_rows,COLUMN,1);
        if(i!=num_datasets-1){
            cout<<endl;
        }
        getline(cin,blank);
    }
    return 0;
}
