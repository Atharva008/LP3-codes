#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool is_safe(int row , int col , vector<string> &board){
    int n = board.size();
    int r = row , c = col;

    while(row >= 0 and col >= 0){
        if(board[row][col] == 'Q') return false;
        row--; col--;
    }
    row = r , col = c;
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    row = r , col = c;
    while(row < n and col >= 0){
        if(board[row][col] == 'Q') return false;
        row++; col--;
    }
    return true;
}

void solve(int col , int n , vector<string> &board , vector<vector<string>> &ans){

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0 ; row < n ; row++){
        if(is_safe(row , col , board)){
            board[row][col] = 'Q';
            solve(col + 1 , n , board , ans);
            board[row][col] = '.';
        }
    }

}

int main(){

    int n;
    cin >> n;

    string s(n , '.');
    vector<string> board(n , s);
    vector<vector<string>> ans;

    solve(0 , n , board , ans);
    
    for(auto b : ans){
        for(int i = 0 ; i < b.size() ; i++){
            for(int j = 0 ; j < b[i].size() ; j++){
                cout << b[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }


    return 0;
}