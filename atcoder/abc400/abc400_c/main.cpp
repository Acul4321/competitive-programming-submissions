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
    //functions
    
    auto solve = [&]()->void{ //solved using editorial
        //solve code
        ll c1 = sqrtl(N/2);
        ll c2 = sqrtl(N/4);

        cout << c1 + c2;

        return;
    };
    solve();
}