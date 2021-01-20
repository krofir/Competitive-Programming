
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long

// O (logn)
//this function return the power of 2 that Closest to you from below
ll findPowOfTwo(ll num){
    ll temp = 2 ;
    ll counter =1 ;
    while (temp <= num){
        temp*=2;
        counter++;
    }
    counter--;
    return counter;
}

//Recursive function
//this function find the number of ones that is till the number 2^n - inclusive the number
ll numOfOnesPowerOfTwo(ll n){
    if (n==0){
        return 1;
    }else if (n==1){
        return 1;
    }else if (n==2){
        return 5;
    }else{
        ll low = numOfOnesPowerOfTwo(n-1);
        ll num = pow(2,n-1);
        return (low*2) + (num-1);
    }
}

//this function find the number of ones that is in some binary number
ll numOfOnesSomeNumber(ll num){
    ll counter=0;
    while (num>0){
        if(num%2==1){
            counter++;
        }
        num=num/2;
    }
    return counter;
}


//this function find the number of ones that is till the wanted number - including himself
ll numOfOnesTillSomeNumberInclude(ll num){
    if(num==1 || num==0){
        return num;
    }else if (num==2){
        return 2;
    }else if (num==3){
        return 4;
    }
    ll n_a=findPowOfTwo(num);
    ll ones_a=numOfOnesPowerOfTwo(n_a);
    ll power=pow(2,n_a);
    if(num==power){
        return ones_a;
    }
    ll diff_a=num-power; //how much numbers is between A and nearest 2^n
    ones_a+=diff_a;
    ll temp=numOfOnesTillSomeNumberInclude(diff_a);
    ones_a+=temp;
    return ones_a;
}

int main() {
    ll A,B;
    while (scanf("%lld %lld", &A,&B) != EOF){
        if(A==B){
            ll low = numOfOnesSomeNumber(A);
            cout<<low<<endl;
        }else{
            if(A==0){
                ll low = numOfOnesTillSomeNumberInclude(B);
                cout<<low<<endl;
            }else{
                //calculate number of ones till A - include A
                ll ones_a=numOfOnesTillSomeNumberInclude(A);
                //calculate number of ones till B - include B
                ll ones_b=numOfOnesTillSomeNumberInclude(B);
                //find the answer
                ll low = numOfOnesSomeNumber(A);
                ll ans=ones_b-ones_a+low;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
