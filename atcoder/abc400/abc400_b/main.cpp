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
    ll N,M;
    cin >> N >> M;
    //functions

    auto solve = [&]()->void{
        //solve code
        ll i=1;
        ll total = 1;
        for(int x=0;x<M;x++){
            total += pow(N,i);
            i++;
        }
        if(total <= 1000000000 && total >= 0){
            cout << total;
        } else {
            cout << "inf";
        }

        return;
    };
    solve();
}