#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr , int low , int high){
    int i = low - 1;
    int pivot = arr[high];
    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i + 1;
}

void quick(vector<int> &arr , int low , int high){
    if(low < high){
        int pivot = partition(arr , low , high);
        quick(arr , low , pivot - 1);
        quick(arr , pivot + 1 , high);
    }
}


void randomized(vector<int> &arr , int low , int high){
    if(low < high){
        int rpivot = low + rand() % (high - low + 1);
        swap(arr[rpivot] , arr[high]);
        int pivot = partition(arr , low , high);
        quick(arr , low , pivot - 1);
        quick(arr , pivot + 1 , high);
    }
}

int main(){

    vector<int> arr = {1,5,2,4,8,7,3,6};
    randomized(arr , 0 , 7);
    for(auto it : arr) cout << it << ' ';

    return 0;
}