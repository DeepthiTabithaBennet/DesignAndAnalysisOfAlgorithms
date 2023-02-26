#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
  
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
        i = 0;
        j = 0;
        k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

/*———————————————————————————————————————————————————————————————————————————*/
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

/*———————————————————————————————————————————————————————————————————————————*/
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*———————————————————————————————————————————————————————————————————————————*/
int main() {
  
    int n;
    int arr[50];
 
    cout << "Enter the number of elements : ";
    cin >> n;
 
    cout << "Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
 
    cout << endl;
    cout << "The Sorted array using MergeSort : ";
    printArray(arr, n);
    return 0;
}
