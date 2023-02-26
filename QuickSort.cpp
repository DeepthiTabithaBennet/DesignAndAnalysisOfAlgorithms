#include <bits/stdc++.h>
using namespace std;

/*———————————————————————————————————————————————————————————————————————————*/
// A utility function to swap two elements
void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

/*———————————————————————————————————————————————————————————————————————————*/
int partition (int arr[], int low, int high){
  int pivot = arr[high]; // pivot
  
  int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

  for (int j = low; j <= high - 1; j++){
    // If current element is smaller than the pivot
    if (arr[j] < pivot){
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
/*———————————————————————————————————————————————————————————————————————————*/
void quickSort(int arr[], int low, int high){
  if (low < high){
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

/*———————————————————————————————————————————————————————————————————————————*/
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*———————————————————————————————————————————————————————————————————————————*/
int main(){

    int n, k;
    int arr[50];
  
    cout << "Enter the number of elements : ";
    cin >> n;
  
    cout << "Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);

    cout << "\nThe Sorted array using QuickSort : ";
    printArray(arr, n);
    
    return 0;
}
