#include <iostream>
#include <algorithm>
using namespace std;

int countSwapes(string S,string T) {
    int count=0;
    for (int j=0;j<S.size();j++){
        if(S[j]!=T[j])
            count++;
    }
    return count/2;
}

int main() {
    int test_size;
    int count = 1;
    string S;
    string T;
    cin >> test_size;
    if (test_size > 200) {
        return 0;
    }
    for (int i = 0; i < test_size; i++) {
        int num_moves = 0;
        cin >> S;
        cin >> T;
        int num_of_ones_S = std::count(S.begin(), S.end(), '1');
        int num_of_zeros_S = std::count(S.begin(), S.end(), '0');
        int num_of_qumark_S = std::count(S.begin(), S.end(), '?');
        int num_of_ones_T = std::count(T.begin(), T.end(), '1');
        int num_of_zeros_T = std::count(T.begin(), T.end(), '0');
        if (num_of_zeros_S + num_of_qumark_S < num_of_zeros_T
            || num_of_ones_S > num_of_ones_T) {
            cout << "Case " << count++ << ": -1" << endl;
            continue;
        } else if (S == T) {
            cout << "Case " << count++ << ": 0" << endl;
            continue;
        }
        int lack_ones = num_of_ones_T - num_of_ones_S;
        if (lack_ones == 0) {
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '?') {
                    S[j] = '0';
                    num_moves++;
                }
            }
            num_moves += countSwapes(S, T);
            cout << "Case " << count++ << ": " << num_moves << endl;
            continue;
        } else { //there is less ones in S then in T
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '?' && lack_ones > 0) {
                    if (T[j] == '1') {
                        S[j] = '1';
                        lack_ones--;
                        num_moves++;
                    }
                }
            }
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '0' && lack_ones > 0) {
                    if (T[j] == '1') {
                        S[j] = '1';
                        lack_ones--;
                        num_moves++;
                    }
                }
            }
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '?' && lack_ones > 0) {
                    S[j] = '1';
                    lack_ones--;
                    num_moves++;
                }
            }
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == '0' && lack_ones > 0) {
                    S[j] = '1';
                    lack_ones--;
                    num_moves++;
                }
            }
            if(lack_ones>0){
                cout << "Case " << count++ << ": -1" << endl;
                continue;
            }else{
                for (int j = 0; j < S.size(); j++) {
                    if (S[j] == '?') {
                        S[j] = '0';
                        num_moves++;
                    }
                }
            }
            num_moves += countSwapes(S, T);
            cout << "Case " << count++ << ": " << num_moves << endl;
            continue;
        }
    }
    return 0;
}
