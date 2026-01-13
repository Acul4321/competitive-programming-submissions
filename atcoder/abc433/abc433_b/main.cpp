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
#include <unordered_map>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        cout << -1 << endl;
        
        for(ll i = 1; i < N; i++) {
            ll index = i-1;
            while(index >= 0){
                if(A[index] > A[i]){
                    cout << index + 1 << endl;
                    break;  
                } 
                index--;
            }
            if(index < 0) {
                cout << -1 << endl;
            }
        
        }

        return;
    };
    solve();
}