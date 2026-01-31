#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>
#include <cassert>
#include <numeric>
#include <utility>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N;
    cin >> N;
    vector<ll> H(N);
    for(ll i=0; i<N; i++) cin >> H[i];
    //functions

    auto solve = [&]()->void{
        //solve code
        if(N == 1){
            cout << "Yes";
            return;
        }

        if(H[0] >= H[1]){
            H[0]--;
        }

        ll prev = H[0];
    
        for(ll i=1; i<N-1; i++){
            if(H[i] > prev){
                H[i]--;
            }
        }
        ll cur = H[0];
    
        for(ll i=1; i<N; i++){
            if(H[i] < cur){
                cout << "No";
                return;
            }
            cur = H[i];
        }

        cout << "Yes";

        return;
    };
    solve();
}