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

//modular exponentiation: calculates a^b mod c where a^b is a crazy big number and would usually overflow. Change mod above as needed
ll mpow(ll base, ll exp)
{
    ll mod=1e9+7;
    //ll mod=1000;
    base %= mod;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N, K;
    cin >> N >> K;
    //functions
    
    auto solve = [&]()->void{
        //solve code
        if(N < K){
            cout << 1;
            return;
        }
        
        vector<ll> A(N+2, 1);
        ll mod = 1000000000;
        ll sum = 0;

        for(ll i = 0; i < K; i++){
            A[i] = 1;
            sum = MOD(sum + 1, mod);
        }

        for( ll i = K + 1; i <= N + 1; i++){
            A[i] = sum;
            sum = MOD(sum - A[i-K] + A[i], mod);
        }

        cout << MOD(A[N + 1], mod);

        return;
    };
    solve();
}