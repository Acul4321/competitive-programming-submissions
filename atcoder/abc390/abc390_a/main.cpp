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
    vector<int> A(5);
    for(int i=0;i<5;i++){
        int temp;
        cin >> temp;
        A[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        if(is_sorted(A.begin(),A.end())){
            cout << "No";
            return;
        }
        bool flag = false;
        for(int i=1;i<5;i++){
            if(flag && A[i-1] > A[i]){
                cout << "No";
                return;
            } else if(A[i-1] > A[i]) { 
                swap(A[i-1],A[i]);
                flag = true;
            }
        }
        if(is_sorted(A.begin(),A.end())){
            cout << "Yes";
            return;
        }
        cout << "No";

        return;
    };
    solve();
}