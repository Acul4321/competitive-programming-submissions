#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>
#include <cassert>
#include <numeric>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N;
    string S;
    cin >> N >> S;
    //functions

    auto solve = [&]()->void{
        //solve code
        vector<ll> wrongB1, wrongA1, wrongB2, wrongA2;
        for(ll i=0;i<S.length();i++){
            if( i % 2 == 0){
                if(S[i] == 'B'){
                    wrongB1.push_back(i);
                }
            } else {
                if(S[i] == 'A'){
                    wrongA1.push_back(i);
                }
            }
        }

        for(ll i=0;i<S.length();i++){
            if( i % 2 == 0){
                if(S[i] != 'B'){
                    wrongB2.push_back(i);
                }
            } else {
                if(S[i] != 'A'){
                    wrongA2.push_back(i);
                }
            }
        }
        vector<ll> dif1(wrongA1.size()), dif2(wrongA2.size());
        for(ll i=0;i<wrongA1.size();i++){
            dif1[i] = abs(wrongA1[i]-wrongB1[i]);
        }
        
        for(ll i=0;i<wrongA2.size();i++){
            dif2[i] = abs(wrongA2[i]-wrongB2[i]);
        }

        cout << min(accumulate(dif1.begin(),dif1.end(),0),accumulate(dif2.begin(),dif2.end(),0));
        return;
    };
    solve();
}