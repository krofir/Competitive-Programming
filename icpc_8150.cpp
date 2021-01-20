#include <iostream>

using namespace std;

int main() {
    int W,N,area;
    int w_i,l_i;
    while (scanf("%d",&W) != EOF) {
        area=0;
        cin>>N;
        for (int i=0;i<N;i++){
            cin>>w_i>>l_i;
            area=area + w_i*l_i;
        }
        cout<<area/W<<endl;
    }
    return 0;
}
