#include<bits/stdc++.h>
using namespace std;

int recursive(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return recursive(n - 1) + recursive(n - 2);
}

void iterative(int n){
    int f0 = 0 , f1 = 1;
    cout << f0 << ' ' << f1 << ' ';
    for(int i = 2 ; i < n ; i++){
        int fnew = f0 + f1;
        cout << fnew << ' ';
        f0 = f1;
        f1 = fnew;
    }
}


int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++) cout << recursive(i) << ' ';
    cout << endl;
    iterative(n);
}
