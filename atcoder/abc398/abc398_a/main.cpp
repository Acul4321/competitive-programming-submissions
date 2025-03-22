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
    //functions

    auto solve = [&]()->void{
        //solve code
        string answer = "";
        if(N%2==0){
            answer = "==";
            while(answer.length()<N){
                answer = '-' + answer + '-';
            }
        } else {
            answer = '=';
            while(answer.length()<N){
                answer = '-' + answer + '-';
            }
        }
        cout << answer << endl;

        return;
    };
    solve();
}