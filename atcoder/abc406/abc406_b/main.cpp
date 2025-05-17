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
#include <climits>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        ll displayVal = 1;
        for(auto a : A){
            if(displayVal > LLONG_MAX/a){
                displayVal = 1;
                continue;
            }
            displayVal *= a;
            if(to_string(displayVal).length() > K) {
                displayVal = 1;
            }
        }
        cout << displayVal;

        return;
    };
    solve();
}