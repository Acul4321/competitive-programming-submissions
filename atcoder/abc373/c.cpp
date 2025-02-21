#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    vector<int> B(N);
    for(int i=0;i<N;i++){
        cin >> B[i];
    }

    auto solve = [&]()->void{
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        //int Amax = *max_element(A.begin(),A.end());
        //int Bmax = *max_element(B.begin(),B.end());
        int Amax = A[N-1];
        int Bmax = B[N-1];
        cout << Amax + Bmax;

        return;
    };
    solve();
}
