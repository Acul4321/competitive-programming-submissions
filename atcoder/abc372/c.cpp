#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    //input code
    int Slen,Qlen;
    cin >> Slen >> Qlen;

    string S;
    cin >> S;
    vector<pair<int,char>> Q(Qlen);
    for(int i=0;i<Qlen;i++){
        int X;
        char C;
        cin >> X >> C;
        Q[i] = make_pair(X,C);
    }
    string sub = "ABC";

    auto solve = [&]()->void{ // solved using editorial 
        //solve code
        int occ = 0;
        for(int i = 0;i < S.length()-2;i++){
            string word = S.substr(i,3);
            if(word == sub){
                occ ++;
            }
        }
        for(auto [i,rep] :Q){
            for(int s=i-2;s < i+1;s++){
                char first = S[s-1];
                char mid = S[s];
                char end = S[s+1];
                //cout << first << mid << end << endl;
                if(first == 'A' and mid == 'B' and end == 'C') {
                    occ--;
                }
            }

            S[i-1] = rep; //mutate word at ith letter to rep

            for(int s=i-2;s < i+1;s++){
                char first = S[s-1];
                char mid = S[s];
                char end = S[s+1];
                //cout << first << mid << end << endl;
                if(first == 'A' and mid == 'B' and end == 'C') {
                    occ++;
                }
            }
            cout << endl << occ << endl;
        }
        return;
    };
    solve();
}