#include <iostream>
using namespace std;

int findMinRec(int arr[], int n){
// if size is 0, whole array has been traversed
    if (n == 1)
        return arr[0];
    return min(arr[n-1], findMinRec(arr, n-1));
}

/*———————————————————————————————————————————————————————————————————————————*/
int getMin(int arr[], int N){
    int min = arr[0];
    for(int i = 1; i < N; i++){
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}

/*———————————————————————————————————————————————————————————————————————————*/
int findMaxRec(int arr[], int n){
    // if size is 0, whole array has been traversed
    if (n == 1)
        return arr[0];
    return max(arr[n-1], findMaxRec(arr, n-1));
}

/*———————————————————————————————————————————————————————————————————————————*/
int getMax(int arr[], int N){
    int max = arr[0];
    for(int i = 1; i < N; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
/*———————————————————————————————————————————————————————————————————————————*/
int main(){
  
    int arr[50];
    int n;

    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements in an array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << endl;
    int minrec = findMinRec(arr, n);
    cout << "The Minimum element (Recursion) is : " << minrec << endl;

    int maxrec = findMaxRec(arr, n);
    cout << "The Maximum element (Recursion) is : " << maxrec << endl;

    cout << endl;
    int min = getMin(arr, n);
    cout<<"The Minimum element (Iterative) is : " << min << endl;

    int max = getMax(arr, n);
    cout << "The Minimum element (Iterative) is : " << max;
    
    cout << endl;

    return 0;
}
