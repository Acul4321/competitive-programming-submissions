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
    //input code
    int N;
    cin >> N;
    vector<pair<ll,ll>> garbage(N);
    for(int i=0;i<N;i++){
        ll q,r;
        cin >> q >> r;
        garbage[i] = make_pair(q,r);
    }
    int Q;
    cin >> Q;
    vector<pair<ll,ll>> query(Q);
    for(int i=0;i<Q;i++){
        ll t,d;
        cin >> t >> d;
        t--;
        query[i] = make_pair(t,d);
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        for(auto [t,d]:query){
            // ll inc = d;
            // while(MOD(inc,garbage[t].first) != garbage[t].second){
            //     inc++;
            //     //cout << "Increment:" << inc <<"%" <<garbage[t].first <<"<=" <<garbage[t].second << endl;
            // }
            if(MOD(d,garbage[t].first) == garbage[t].second){
                cout << d << endl;
            }else if(MOD(d,garbage[t].first) < garbage[t].second){
                cout <<MOD(d,garbage[t].first) -garbage[t].second << endl;
            }else{
                cout << d-MOD(d,garbage[t].first)-1<< endl;
            }
            //cout << d << endl;
        }

        return;
    };
    solve();
}