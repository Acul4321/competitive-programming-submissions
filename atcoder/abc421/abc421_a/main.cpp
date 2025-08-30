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

    vector<string> Rooms(N);
    for(int i=0;i< N;i++){
        string temp;
        cin >> temp;
        Rooms[i] = temp;
    }

    int X;
    string Y;

    cin >> X >> Y;
    //functions

    auto solve = [&]()->void{
        //solve code
        if(Rooms[X-1] == Y){
            cout << "Yes";
        } else {
            cout << "No";
        }

        return;
    };
    solve();
}