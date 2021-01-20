#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <limits.h>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi; // unweighted graph

//global variable for the answer
vi answer;
int num_holes;
unsigned int CASE_NUM;

//get the graph , index of current row and a letter -
//this function translate the hexadecimal letter to a binary number and push it to the graph[row]
void addToGraph(vvi& graph,int row,char letter){
    int num;
    //the letter is a number between 0 to 9
    if(letter>=48 && letter <=57){
        num=letter-48; //translate letter to number
    }else{  //the letter is a letter between a to f
        num=letter-87; //translate letter to number
    }
    vi digits(4,0);
    int temp=0;
    while (num > 0) {
        digits[temp] = num % 2;
        num = num / 2;
        temp++;
    }
    reverse(digits.begin(),digits.end());
    for(int i=0;i<4;i++){
        graph[row].push_back(digits[i]);
    }
}

//get input and build the graph include zeros in the beginning and the end
void buildGraph(vvi& graph,unsigned int H,unsigned int W){
    string line;
    for(int i=1;i<H-1;i++){
        cin>>line;
        graph[i].push_back(0);
        for(int j=0;j<W;j++){
            addToGraph(graph,i,line[j]);
        }
        graph[i].push_back(0);
    }
}

//build the frame of zeros
void buildFrame(vvi& graph,unsigned int H,unsigned int W){
    for (int i=0;i<W;i++){
        graph[0].push_back(0);
        graph[H-1].push_back(0);
    }
}

void colorHole(vvi& graph,int row,int col){
    if(graph[row][col]==0) {
        graph[row][col] = 3;
        colorHole(graph, row - 1, col);
        colorHole(graph, row + 1, col);
        colorHole(graph, row , col-1);
        colorHole(graph, row , col+1);
    }
    return;
}

void scanLetter(vvi& graph,int row,int col,unsigned int H,unsigned int W){
    if(row<0 || row >=H){
        return;
    }
    if(col<0 || col >=W){
        return;
    }
    if(graph[row][col]==0){
        num_holes++;
        colorHole(graph,row,col);
        return;
    }else if (graph[row][col]==1){
        graph[row][col]=2; //we sign that we visit here
        if(row-1>=0){
            scanLetter(graph,row-1,col,H,W);
        }
        if(row+1<H){
            scanLetter(graph,row+1,col,H,W);
        }
        if(col-1>=0){
            scanLetter(graph,row,col-1,H,W);
        }
        if(col+1<W){
            scanLetter(graph,row,col+1,H,W);
        }
    }
    return;
}

//this function run all over the matrix till it find a letter = black dot that not colored
//we color : black dots that we visit at : 2
//holes as :3
//white spaces in the background as : 9
void searchHieroglyphs(vvi& graph,int row,int col,unsigned int H,unsigned int W){
    if(graph[row][col]==2 || graph[row][col]==3 || graph[row][col]==9){
        return;
    }
    else if(graph[row][col]==1){
        num_holes=0;
        scanLetter(graph,row,col,H,W); //we find a new letter - than we scan it
        //to find what letter this is
        if(num_holes==0){
            answer.push_back(6); // W we sign with 6 holes
        }else{
            answer.push_back(num_holes);
        }
    }else{
        graph[row][col]=9; //sign that we visit this coord in the background
        if(row-1>=0){
            searchHieroglyphs(graph,row-1,col,H,W);
        }
        if(row+1<H){
            searchHieroglyphs(graph,row+1,col,H,W);
        }
        if(col-1>=0){
            searchHieroglyphs(graph,row,col-1,H,W);
        }
        if(col+1<W){
            searchHieroglyphs(graph,row,col+1,H,W);
        }
    }
}

//this function color the background from 0 to 8
//so we can recognize between hole inside a letter to the background
void colorBackground(vvi& graph,int row,int col,unsigned int H,unsigned int W){
    if(graph[row][col]==0){
        graph[row][col]=8; //color the background
    }else{
        return;
    }
    if(row-1>=0){
        colorBackground(graph,row-1,col,H,W);
    }
    if(row+1<H){
        colorBackground(graph,row+1,col,H,W);
    }
    if(col-1>=0){
        colorBackground(graph,row,col-1,H,W);
    }
    if(col+1<W){
        colorBackground(graph,row,col+1,H,W);
    }
}

void printAnswer(vi& letters){
    cout<<"Case "<<CASE_NUM<<": ";
    for(int i=0;i<6;i++){
        int num_to_print=letters[i];
        for(int j=0;j<num_to_print;j++){
            if(i==0) cout<<"A";
            if(i==1) cout<<"D";
            if(i==2) cout<<"J";
            if(i==3) cout<<"K";
            if(i==4) cout<<"S";
            if(i==5) cout<<"W";
        }
    }
    cout<<endl;
}

void SOLVE(unsigned int H,unsigned int W){
    answer.clear();
    //we build a frame of zeros that will wrap the graph
    H+=2;
    vvi graph(H,vector<int>());
    buildGraph(graph,H,W);
    W=graph[1].size();
    buildFrame(graph,H,W);
    colorBackground(graph,0,0,H,W);
    searchHieroglyphs(graph,0,0,H,W);
    vi letters(6,0); //this vector save hole much letters we found for each letter
    //(A,D,J,K,S,W)
    int size=answer.size();
    for(int i=0;i<size;i++){
        switch (answer[i]){
            case 1: letters[0]+=1;break;
            case 2: letters[3]+=1;break;
            case 3: letters[2]+=1;break;
            case 4: letters[4]+=1;break;
            case 5: letters[1]+=1;break;
            case 6: letters[5]+=1;break;
            default:break;
        }
    }
    printAnswer(letters);
}

int main() {
    unsigned int H,W;
    CASE_NUM=0;
    cin>>H>>W;
    while(!(H==0 && W==0)){
        CASE_NUM++;
        SOLVE(H,W);
        cin>>H>>W;
    }
    return 0;
}
