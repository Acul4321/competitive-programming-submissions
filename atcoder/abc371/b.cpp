#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    //input code
    int N;
    int M;
    cin >> N >> M;

    vector<pair<int,char>> babies(M);
    for(int i=0;i<M;i++){
        int A;
        char B;
        cin >> A >> B;
        babies[i] = make_pair(A,B);
    }

    auto solve = [&]()->void{
        //solve code
        vector<int> taroFam = {0};
        for(auto [first,second]:babies){
            if(find(taroFam.begin(),taroFam.end(),first) == taroFam.end()){//if not foud
                if (second == 'M') {
                    cout << "Yes" << endl;
                    taroFam.push_back(first);
                    continue;
                }
            }
            cout << "No" << endl;
        }

        return;
    };
    solve();
}