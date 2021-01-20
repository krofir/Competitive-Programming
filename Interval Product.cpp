#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long BIT[100000]= {0}, a[100000],n;
void update(int x, long long val)
{
    for(; x <= n; x += x&-x)
        BIT[x] += val;
}
long long query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}

void clear_BIT(){
    for(int i=0;i<100000;i++){
        BIT[i]=0;
    }
}

int main() {
    unsigned int N;
    int K;
    int temp;
    char op;
    int first_index,second_index;
    int num_neg=0,zero_flag=0;
    while (scanf("%lld", &n) != EOF) {
        cin>>K;
        for(int i=1;i<=n;i++){
            cin>>temp;
            if(temp>0){
                a[i]=0;
            }else if (temp<0){
                a[i]=1;
            }else{
                //because the max sum is 100K and the min is 0 we want to know for sure that there is a zero
                //when we sum the array we notice the zero - when we get negative value
                a[i]=-100001;
            }
            update(i, a[i]);
        }
        for(int i=0;i<K;i++){
            cin>>op>>first_index>>second_index;
            if(op=='C'){
                if(second_index>0){
                    update(first_index, -a[first_index]); //update to be 0 because positive
                    a[first_index]=0;
                }else if (second_index<0){
                    if(a[first_index]==0){
                        update(first_index, 1); //update to be 1 because negative
                    }else if(a[i]<0){ //there is zero
                        update(first_index,-a[first_index]+1); //update to be 1 because negative
                    }
                    a[first_index]=1;
                }else{ //need to change the number to be zero= -100001
                    if(a[first_index]==0){
                        update(first_index, -100001); //update to be "zero" = -100001
                    }else if(a[first_index]>0){ //there is a negative number
                        update(first_index,-100001-1); //update to be "zero" = -100001
                    }
                    a[first_index]=-100001;
                }
            }
            else if(op=='P') {
                long long sum = query(second_index) - query(first_index-1);
                if (sum < 0) {
                    cout << '0';
                } else if (sum>0) {
                    if(sum%2==0){
                        cout << '+';
                    }else{
                        cout << '-';
                    }
                } else {
                    cout << '+';
                }
            }
        }
    cout<<endl;
    clear_BIT();
    }
return 0;
}


