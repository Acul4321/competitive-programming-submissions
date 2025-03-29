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
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T;
    cin >> T;
    //functions

    auto solve = [&]()->void{
        //solve code
        int total = 0;
        for(int i = 0; i<N ; i++){
            if(S[i] != T[i]){
                total++;
            }
        }

        cout << total;

        return;
    };
    solve();
}