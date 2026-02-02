#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>
#include <cassert>
#include <numeric>
#include <utility>
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
        bool even = false;
        S.pop_back();
        ll operations = 1;
        while(!even){
            if(S.length() % 2 != 0){
                S.pop_back();
                operations++;
                continue;
            }else{
                for(ll i=0; i < S.length() / 2;i++){
                    even = true;
                    if(S[i] != S[i + S.length() / 2]) {
                        even = false;
                        break;
                    }
                }

                if(!even) {
                    S.pop_back();
                    operations++;
                }
            }
        }
        cout << S.length() << endl;

        return;
    };
    solve();
}