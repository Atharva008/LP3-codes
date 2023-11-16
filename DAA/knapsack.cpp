#include<bits/stdc++.h>
using namespace std;



int f(int idx , int capacity , vector<int> &weight , vector<int> &val, vector<vector<int>> &dp , int n){
    if(idx == 0){
        if(weight[0] <= capacity){
            return val[0];
        }
        return 0;
    }

    if(dp[idx][capacity] != -1) return dp[idx][capacity];

    int notake = f(idx - 1 , capacity , weight , val , dp , n);
    int take = 0;   
    if(weight[idx] <= capacity){
        take = val[idx] + f(idx - 1 , capacity - weight[idx] , weight , val , dp , n);
    }


    return dp[idx][capacity] = max(take , notake);

}

int main(){

    
    int capacity = 8;
    vector<int> weight = {3, 4 , 5};
    vector<int> val = {30 , 40 , 50};
    int n = weight.size();


    vector<vector<int>> dp(n , vector<int>(capacity + 1 , -1));

    int ans = f(n - 1 , capacity , weight , val , dp , n);
    cout << ans << endl;


    return 0;
}