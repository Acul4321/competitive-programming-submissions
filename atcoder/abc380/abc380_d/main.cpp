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
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> K(Q);
    for(ll i=0;i<Q;i++){
        ll temp;
        cin >> temp;
        temp--;
        K[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        string fS = S;
        for(char &l:fS){
            if(islower(l)){
                l = toupper(l);
            }else if(isupper(l)){
                l = tolower(l);
            }
        }
        
        ll length = S.length()*3;
        ll ind;
        for(ll i:K){
            ind = i % length+1;
            ind--;
            if(ind <= S.length()-1){ //base S
                cout << S[ind] << ' ';
                continue;
            }else if(ind <= S.length()*2){ //base fS
                ind = ind % S.length();
                cout << fS[ind] << ' ';
                continue;
            }else if(ind > S.length()*2-1){
                ind = ind % S.length();
                cout << S[ind] << ' ';
                continue;
            }
        }

        return;
    };
    solve();
}