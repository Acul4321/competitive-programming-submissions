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
    vector<int> A(N);
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        A[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        int prev = A[0];
        for(int i=1;i<N;i++){
            if(prev >= A[i]){
                cout << "No";
                return;
            }
            
            prev = A[i];
        }
        cout << "Yes";

        return;
    };
    solve();
}