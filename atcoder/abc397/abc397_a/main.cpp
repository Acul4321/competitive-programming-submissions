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
    double X;
    cin >> X;
    //functions

    auto solve = [&]()->void{
        //solve code
        if(X>= 38.0){
            cout << 1; 
        } else if(X>=37.5){
            cout << 2;
        } else{
            cout << 3;
        }

        return;
    };
    solve();
}