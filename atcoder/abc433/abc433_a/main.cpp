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
    ll X, Z, Y;
    cin >> X >> Y >> Z;
    //functions

    auto solve = [&]()->void{
        //solve code

        if(X >= Z*Y && (X-Z*Y) % (Z-1) == 0){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        return;
    };
    solve();
}