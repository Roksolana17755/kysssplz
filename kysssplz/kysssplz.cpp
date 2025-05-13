#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "enter size: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "menu: " << endl;
        cout << "1. add element" << endl;
        cout << "2. erase memory" << endl;
        cout << "3. middle value" << endl;
        cout << "0. exit" << endl;
        cout << "your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int newValue;
            cout << "enter new element: ";
            cin >> newValue;

            int* newArr = new int[size + 1];
            for (int i = 0; i < size; i++)
                newArr[i] = arr[i];
            newArr[size] = newValue;

            delete[] arr;
            arr = newArr;
            size++;
            break;
        }
        case 2: {
            delete[] arr;
            arr = nullptr;
            size = 0;
            cout << "memory is erased";
            break;
        }
        case 3: {
            if (size == 0 || arr == nullptr) {
                cout << "aaray is empty";
            }
            else {
                int sum = 0;
                for (int i = 0; i < size; i++)
                    sum += arr[i]; 
                cout << "middle value: " << (double)sum / size << endl;
            }
            break;
        }
        case 0:
            cout << "exit";
            break;

        default:
            cout << "wrong choice, try again";
        }
    } while (choice != 0);

    delete[] arr;
    return 0;
}
