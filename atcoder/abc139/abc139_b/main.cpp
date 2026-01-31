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
#include <utility>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    int A, B;
    cin >> A >> B;
    //functions

    auto solve = [&]()->void{
        //solve code
        int total = 0;
        int socketCount = 1;
        if(A >= B){
            cout << socketCount << endl;
        } else {
            total += A;
            A--;
            while(total < B){
                socketCount++;
                total += A;
            }
            cout << socketCount << endl;
        }

        return;
    };
    solve();
}