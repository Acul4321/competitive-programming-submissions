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
    cout << fixed; //<< setprecision(11);//allows large decimal numbers
    //input code
    ll temp;
    cin >> temp;
    __int128_t X = temp;
    //functions

    auto solve = [&]()->void{
        //solve code
        ll curNum = 1;
        for(ll i = 0;i<=X && curNum <= 100;i++){
            __int128_t factorial = 1;
            for(ll j=1;j<=curNum;j++){
                factorial *= j;
                if(factorial > X) break; 
            }
            // cout << (ll)factorial << '=' << (ll)X << endl;
            if(factorial == X){
                cout << curNum;
                return;
            }
            curNum++;
        }

        return;
    };
    solve();
}