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
    string S;
    cin >> S;
    //functions

    auto solve = [&]()->void{
        //solve code
        int total = 0;
        char cur = 'i';

        for(int i = 0; i < S.size()-1; i++){
            if(S[i] == S[i+1]){
                total++;
            }
        }

        if(S.front() == 'o'){
            total++;
        }

        if(S.back() == 'i'){
            total++;
        }

        cout << total;

        return;
    };
    solve();
}