#include <iostream>
using namespace std;

/*———————————————————————————————————————————————————————————————————————————*/
// Standard Lomuto partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/*———————————————————————————————————————————————————————————————————————————*/
// Implementation of QuickSelect
int kthSmallest(int a[], int left, int right, int k) {

    while (left <= right) {

        // Partition a[left..right] around a pivot and find the position of the pivot
        int pivotIndex = partition(a, left, right);

        // If pivot itself is the k-th smallest element
        if (pivotIndex == k - 1)
            return a[pivotIndex];

        // If there are more than k-1 elements on left of pivot, then k-th smallest must be on left side.
        else if (pivotIndex > k - 1)
            right = pivotIndex - 1;

        // Else k-th smallest is on right side.
        else
            left = pivotIndex + 1;
    }    
    return -1;
}

/*———————————————————————————————————————————————————————————————————————————*/
int main(){
    
    int n, k;
    cout << "Enter the Number of Elements in the Array : ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the Elements of the Array : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nEnter the value of k : ";
    cin >> k;
    
    cout << endl;
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\nK-th smallest element is " << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
