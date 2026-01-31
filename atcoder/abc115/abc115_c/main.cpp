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
#include <utility>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for(ll i = 0; i < N; i++) {
        cin >> H[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        sort(H.begin(), H.end());
        ll minDif = LLONG_MAX;

        for(ll i = 0; i<=N-K; i++){
            ll dif = H[i+K-1] - H[i];
            minDif = min(minDif,dif);
        }
        cout << minDif << endl;

        return;
    };
    solve();
}