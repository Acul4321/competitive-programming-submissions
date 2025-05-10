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
    int R,X;
    cin >> R >> X;
    //functions

    auto solve = [&]()->void{
        //solve code
        if(X == 1){
            if(R >= 1600 && R <=2999){
                cout << "Yes";
            } else {
                cout << "No";
            }
        } else{
            if(R >= 1200 && R<=2399){
                cout << "Yes";
            } else{
                cout << "No";
            }
        }

        return;
    };
    solve();
}