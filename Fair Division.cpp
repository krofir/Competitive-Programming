#include <iostream>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

int main() {
    int num_tests;
    unsigned int price;
    unsigned int num_people;
    int temp_contribute;
    long long temp_sum;
    set <int> temp_limits;
    cin >> num_tests;
    for (int i=0;i<num_tests;i++){
		//initiate min heap and max heap 
        priority_queue <int> max_limits;
        priority_queue <int, vector<int>, greater<int> > limits;
        cin >> price >> num_people;
        temp_sum=0;
        vector <int> max_contribute(num_people);
        for (int j=0;j<num_people;j++){
            cin>>temp_contribute;
            temp_sum+=temp_contribute;
            max_contribute[j]=temp_contribute;
            temp_limits.insert(temp_contribute);
        }
		//if total cost is grater then all Friends limits-we can not buy the present
        if(temp_sum < price){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            vector <int> answer(num_people);
			//build min heap and max heap 
            for(auto limit : temp_limits){
                limits.push(limit);
                max_limits.push(limit);
            }
            int low_limit=0;
            int temp_max_limit=0;
            int counter_low_people;
            int counter_pay_people;
            int rest_people=num_people;
            int rest_price = price;
            int current_max_payment=0;
            bool flag=false;
			//if all the Friends as the same limit - we divide the total cost Equaly
            if(limits.size()==1){
                low_limit=limits.top();
                int avg =(int(floor(double(rest_price)/rest_people)));
                for (int k=0;k<num_people;k++){
                    answer[k]+=avg;
                    rest_price-=avg;
                }
                //now we need to Divide the remainder to the firsts people till we end
                for (int k=0;k<num_people;k++){
                    if(rest_price==0){
                        break;
                    }
                    answer[k]+=1;
                    rest_price-=1;
                }
                flag=true;
            }
			//as long there is a limit in the heap
            while (!limits.empty() && !flag)
            {
                counter_low_people=0;
                counter_pay_people=0;
                low_limit=limits.top();
                limits.pop();
                int avg =(int(floor(double(rest_price)/rest_people)));
                //that mean there are more people left then cents
                //then some of them(the richest) need to pay
                if(avg==0){
                    while(rest_price>0 && !max_limits.empty()){
                        temp_max_limit=max_limits.top();
                        max_limits.pop();
                        for (int k=0;k<num_people;k++){
                            if(max_contribute[k]==temp_max_limit) {
                                answer[k]+=1;
                                rest_price-=1;
                            }
                            if(rest_price==0){
                                break;
                            }
                        }
                    }
                    break;
                }
                if( avg <= low_limit-current_max_payment){
                    for (int k=0;k<num_people;k++){
                        if(max_contribute[k]==low_limit) {
                            counter_low_people++;
                        }
                        if(max_contribute[k]>=low_limit){
                            answer[k]+=avg;
                            counter_pay_people++;
                        }
                    }
                    rest_people-=counter_low_people;
                    rest_price-=counter_pay_people*avg;
                    current_max_payment+=avg;
                }else{
                    for (int k=0;k<num_people;k++){
                        if(max_contribute[k]==low_limit) {
                            counter_low_people++;
                        }
                        if(max_contribute[k]>=low_limit){
                            answer[k]+=low_limit-current_max_payment;
                            counter_pay_people++;
                        }
                    }
                    rest_people-=counter_low_people;
                    rest_price-=counter_pay_people*(low_limit-current_max_payment);
                    current_max_payment+=low_limit-current_max_payment;
                }
                if(current_max_payment<low_limit){
                    limits.push(low_limit);
                    rest_people+=counter_low_people;
                }
            }
           for(int n=0;n<num_people;n++){
               if(n==num_people-1){
                   cout<<answer[n]<<endl;
               }else{
                   cout<<answer[n]<<" ";
               }
           }
        }
        temp_limits.clear();
    }

    return 0;
}