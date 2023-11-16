#include<bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr , int low , int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low ; j < high ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i + 1;
}


void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSortDeterministic(arr, low, pivotIndex - 1);
        quickSortDeterministic(arr, pivotIndex + 1, high);
    }
}

// Randomized QuickSort
int getRandomPivot(int low, int high) {
    srand(time(nullptr));
    return low + rand() % (high - low + 1);
}

void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Randomly choose a pivot
        int randomPivot = getRandomPivot(low, high);
        swap(arr[randomPivot], arr[high]);

        int pivotIndex = partition(arr, low, high);
        quickSortRandomized(arr, low, pivotIndex - 1);
        quickSortRandomized(arr, pivotIndex + 1, high);
    }
}

int main(){

    vector<int> arr = {1,5,2,4,8,7,3,6};
    // quickSortDeterministic(arr , 0 , 7);
    // for(auto it : arr) cout << it << ' ';
    // cout << endl;

    // quickSortRandomized(arr , 0 , 7);
    // for(auto it : arr) cout << it << ' ';
    // cout << endl;


    return 0;
}