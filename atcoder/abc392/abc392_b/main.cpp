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
    int N,M;
    cin >> N >> M;
    vector<int> seq(M);
    for(int i=0;i<M;i++){
        int temp;
        cin >> temp;
        seq[i] = temp;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        int count =0;
        for(int i=0;i<N;i++){
            if(std::find(seq.begin(), seq.end(), i+1) == seq.end()){
                count++;
            }
        }
        cout << count << endl;
        for(int i=0;i<N;i++){
            if(std::find(seq.begin(), seq.end(), i+1) == seq.end()){
                cout << i+1 << ' ';
            }
        }
        return;
    };
    solve();
}