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
    string X;
    cin >> X;
    //functions

    auto solve = [&]()->void{
        //solve code

        sort(X.begin(), X.end());

        long zeroCount = 0;
        for(char c : X){
            if (c == '0') {
                zeroCount++;
            }
        }
        string zeros = "";
        for(int i = 0; i < zeroCount; i++){
            zeros += "0";
        }

        cout << X.substr(zeroCount,1) << zeros << X.substr(zeroCount+1, X.size() - zeroCount - 1);

        return;
    };
    solve();
}