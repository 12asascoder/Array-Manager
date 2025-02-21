#include <iostream>
#include <algorithm>
using namespace std;

void insertElement(int arr[], int& size, int element) {
    arr[size++] = element;
}

void deleteElement(int arr[], int& size, int element) {
    int pos = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

bool searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

void displayElements(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int size) {
    sort(arr, arr + size);
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Search for an element\n";
        cout << "4. Display all elements\n";
        cout << "5. Sort the array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                insertElement(arr, size, element);
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                deleteElement(arr, size, element);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                if (searchElement(arr, size, element)) {
                    cout << "Element found in the array.\n";
                } else {
                    cout << "Element not found in the array.\n";
                }
                break;
            case 4:
                cout << "Elements in the array: ";
                displayElements(arr, size);
                break;
            case 5:
                sortArray(arr, size);
                cout << "Array sorted in ascending order.\n";
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

