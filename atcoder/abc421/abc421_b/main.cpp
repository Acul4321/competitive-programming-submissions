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
    ll a1,a2;
    cin >> a1 >> a2;
    //functions

    auto solve = [&]()->void{
        //solve code
        vector<ll> fib(10);
        fib[0] = a1;
        fib[1] = a2;

        for(int i=2;i<10;i++){

            ll x = fib[i-1] + fib[i-2];
            ll rev = 0;
            while(x > 0) {
                rev = rev * 10 + (x % 10);
                x /= 10;
            }

            fib[i] = rev;

        }

        cout << fib[9];
        return;
    };
    solve();
}