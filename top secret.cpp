#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long

void PrintAnswer(vector<ll>& numbers){
    ll size=numbers.size();
    for(int i=0;i<size;i++){
        if(i!=size-1){
            cout<<numbers[i]<<" ";
        }else{
            cout<<numbers[i]<<endl;
        }
    }
}

vector<vector<ll> > CreateMatrix (ll size,ll L,ll R){
    vector<vector<ll> > matrix(size);
    //we create the size*size matrix that will include the operations
    //first we initiate the matrix with zeros
    for ( int i = 0 ; i < size ; i++ ) {
        matrix[i].resize(size);
    }
    //insert L and R operations to the matrix
    ll curr=0;
    ll prev=size-1;
    ll next=1;
    for ( int i = 0 ; i < size ; i++ ) {
        matrix[i][curr]=1;
        matrix[i][prev]=L;
        matrix[i][next]=R;
        prev=curr;
        curr=next;
        if(next==size-1){
            next=0;
        }else{
            next++;
        }
    }
    return matrix;
}


void multiplyMatrix(vector<vector<ll> >& matrix1 ,vector<vector<ll> >& matrix2,ll mod){
    ll size = matrix1.size();
    vector<vector<ll> > new_matrix(size);
    //we create the size*size matrix that will include the operations
    //first we initiate the matrix with zeros
    for ( int i = 0 ; i < size ; i++ ) {
        new_matrix[i].resize(size);
    }
    ll sum;
    for ( int i = 0 ; i < 1 ; i++ ) {
        for ( int j = 0 ; j < size ; j++ ) {
            sum=0;
            for ( int k = 0 ; k < size ; k++ ){
                sum+=((matrix1[i][k])*(matrix2[k][j]))%mod;
                sum=sum%mod;
            }
            new_matrix[i][j]=sum;
        }

    }
    ll prev_j;
    for ( int i = 1 ; i < size ; i++ ) {
        for ( int j = 0 ; j < size ; j++ ) {
            prev_j=j-1;
            if(j==0){
                prev_j=size-1;
            }
            new_matrix[i][j]=new_matrix[i-1][prev_j];
        }
    }
    matrix1=new_matrix;
}

void PowMatrix(vector<vector<ll> >& matrix ,vector<vector<ll> >& first_matrix ,ll S,ll mod){
    if( S == 0 || S == 1)
        return;
    PowMatrix(matrix,first_matrix, S/2,mod);
    multiplyMatrix(matrix, matrix,mod);
    if (S%2 != 0)
        multiplyMatrix(matrix, first_matrix,mod);
}


void DoDeciphering(vector<vector<ll> >& matrix ,vector<ll>& numbers,ll mod){
    ll size = matrix.size();
    vector<ll> result(size);
    ll sum;
    for ( int i = 0 ; i < size ; i++ ) {
        sum=0;
        for ( int j = 0 ; j < size ; j++ ) {
            sum+=((matrix[i][j])*(numbers[j]))%mod;
            sum=sum%mod;
        }
        result[i]=sum;
    }
    numbers=result;
}

int main() {
    int num_tests;
    string blank;
    unsigned int N;
    ll S,L,R,X;
    //N is number of numbers
    //S the number of times we need to add the besides numbers
    //L and R is who much we add  the number to its left/right
    //X the number of lower digits
    ll temp;
    ll mod;
    cin>>num_tests;
    for(int i=0;i<num_tests;i++){
        mod=1;
        cin>>N>>S>>L>>R>>X;
        vector<ll> numbers(N,0);
        while (X){
            mod *= 10;
            X--;
        }
        for (int j=0;j<N;j++){
            cin>>temp;
            numbers[j]=temp;
        }
        vector<vector<ll> > matrix=CreateMatrix(N,L,R);
        vector<vector<ll> > first=matrix;
        if(S==0){
            for (int j=0;j<N;j++){
                numbers[j]=numbers[j]%mod;
            }
        }
        else if (S==1){
            DoDeciphering(matrix,numbers,mod);
        }
        else if(S>1) {
            PowMatrix(matrix, first, S, mod);
            DoDeciphering(matrix, numbers, mod);
        }
        PrintAnswer(numbers);
        getline(cin,blank);
    }
    return 0;
}