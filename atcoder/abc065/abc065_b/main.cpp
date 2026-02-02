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
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = --a;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        ll cur = A[0];
        ll count = 1;
        while(cur != 1 && count < N){
            cur = A[cur];
            count++;
        }

        if(cur == 1){
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }

        return;
    };
    solve();
}