#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int n; 

// Функція для введення кількості елементів масиву
int control() {
    while (true) {
        cout << "Enter the number of elements of the array: ";
        cin >> n;
        if (cin.get() == '\n' && n > 0) break;
        else {
            cout << "An integer is expected!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return n;
}
// Функція для обміну значень двох змінних
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int* arr) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


void genRandom(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2001 - 1000;
    }
}

void genSpad(int* arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = 1000 - i;
    }
}


void duplicateValue(int* arr, int value) {
    for (int i = 0; i < n; i++) {
        arr[i] = value;
    }
}


void genTheSameValue(int* arr) {
    duplicateValue(arr, rand() % 2001 - 1000);
    int index1 = rand() % n;
    int index2;
    do {
        index2 = rand() % n;
    } while (index2 == index1);

    arr[index2] = arr[index1];
}

int main() {
    n = control();

    int* randomArr = new int[n];
    genRandom(randomArr);

    int* descendArr = new int[n];
    genSpad(descendArr);

    int uniformValue = rand() % 2001 - 1000;
    int* uniformArr = new int[n];
    duplicateValue(uniformArr, uniformValue);

    int* duplicateArr = new int[n + 2];
    genTheSameValue(duplicateArr);

    clock_t start_time1 = clock();
    selectionSort(randomArr);
    clock_t end_time1 = clock();

    clock_t start_time2 = clock();
    selectionSort(descendArr);
    clock_t end_time2 = clock();

    clock_t start_time3 = clock();
    selectionSort(uniformArr);
    clock_t end_time3 = clock();

    clock_t start_time4 = clock();
    selectionSort(duplicateArr);
    clock_t end_time4 = clock();

    cout << "Selection sort for random array: " << (end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "Selection sort for spad: " << (end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "Selection sort for uniform array: " << (end_time3 - start_time3) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << "Selection sort for array with two equal values: " << (end_time4 - start_time4) * 1000 / CLOCKS_PER_SEC << "ms" << endl;

    delete[] randomArr;
    delete[] descendArr;
    delete[] uniformArr;
    delete[] duplicateArr;

    system("pause");
    return 0;
}
