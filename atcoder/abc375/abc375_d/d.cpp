#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    string S;
    cin >> S;

    auto solve = [&]()->void{
        //solve code
        ll count=0;
        for(ll startInd = 0;startInd < S.length();startInd++){
            for(ll endInd = 0;endInd < S.length();endInd++){
                if(S[startInd] == S[endInd] and (startInd+1 < endInd)){
                    count+= endInd-startInd;
                }
            }
        }
        cout << count;

        return;
    };
    solve();
}