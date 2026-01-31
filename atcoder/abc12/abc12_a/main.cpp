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
#include <numeric>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N;
    cin >> N;
    vector<ll> A(N*3);
    for(ll i = 0; i < N*3; i++) {
        cin >> A[i];
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        sort(A.begin(), A.end(), greater<ll>());
        ll strength = 0;
        for(int i = 1; i < 2*N; i += 2) {
            strength += A[i];
        }

        cout << strength << endl;
        return;
    };
    solve();
}