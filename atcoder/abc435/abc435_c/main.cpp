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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        temp--;
        A[i] = temp;
    }

    //functions

    auto solve = [&]()->void{
        //solve code
        ll falling = A[0];
        ll total = 0;
        while (falling != 0 && total < N) {
            total += falling;
            falling = A[total];
        }
        cout << min(total, N-1) + 1<< "\n";

        return;
    };
    solve();
}