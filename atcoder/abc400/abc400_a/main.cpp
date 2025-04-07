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
    double A;
    cin >> A;
    //functions

    auto solve = [&]()->void{
        //solve code
        double ans = 400/A;
        if (floor(ans) == ans){
            cout << (int)ans;
        } else {
            cout << -1;
        }

        return;
    };
    solve();
}