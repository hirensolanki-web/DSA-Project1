#include <iostream>
using namespace std;

// ----------- Selection Sort -----------
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ----------- Merge Sort -----------
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[100];

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int i = left, m = 0; i <= right; i++, m++) {
        arr[i] = temp[m];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ----------- Linear Search -----------
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}

// ----------- Binary Search -----------
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// ----------- Display Array -----------
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ----------- Main Menu -----------
int main() {
    int arr[100], n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                selectionSort(arr, n);
                cout << "Array sorted using Selection Sort:\n";
                display(arr, n);
                break;

            case 2:
                mergeSort(arr, 0, n - 1);
                cout << "Array sorted using Merge Sort:\n";
                display(arr, n);
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> key;
                int index1 = linearSearch(arr, n, key);
                if(index1 != -1)
                    cout << "Element found at index " << index1 << endl;
                else
                    cout << "Element not found\n";
                break;

            case 4:
                cout << "Enter element to search: ";
                cin >> key;
                int index2 = binarySearch(arr, n, key);
                if(index2 != -1)
                    cout << "Element found at index " << index2 << endl;
                else
                    cout << "Element not found\n";
                break;

            case 5:
                display(arr, n);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}