#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <stdio.h>
#define ll long long
using namespace std;

int main() {
    //input code
    int N;
    cin >> N;
    vector<int> K(N);

    for(int i=0;i<N;i++){
        cin >> K[i];
    }

    auto solve = [&]()->void{
        //solve code
        sort(K.begin(),K.end());

        ll dif=INFINITY;
        for(int i=0;i<1<<N;i++){
            ll A = 0;
            ll B = 0;
            for(int j=0;j<N;j++){
                if(((i>>j)&1) == 1){
                    A +=K[j];
                }
                else{
                    B +=K[j];
                }
            }
            dif = min(dif,max(A,B));
        }
        cout << dif << endl;

        return;
    };
    solve();
}