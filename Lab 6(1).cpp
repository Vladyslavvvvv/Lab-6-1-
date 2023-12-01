#include <iostream>
#include <cmath>

using namespace std;

template <class T>
T GeometricMean(const T* array, int size) {
    if (size == 0) {
        cout << "Error: Array size is zero." << endl;
        return static_cast<T>(0);
    }

    T product = 1;
    for (int i = 0; i < size; ++i) {
        if (array[i] <= 0) {
            cout << "Error: Non-positive value found in the array." << endl;
            return static_cast<T>(0);
        }
        product *= array[i];
    }

    return pow(product, 1.0 / size);
}

int main() {
    int size;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Error: Invalid array size." << endl;
        return 1; // Exit with an error code
    }

    // Dynamically allocate memory for the array
    double* doubleArray = new double[size];

    // Prompt the user to enter values for the array
    cout << "Enter values for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Enter value for element [" << i << "]: ";
        cin >> doubleArray[i];
    }

    // Calculate and display the geometric mean
    double geometricMean = GeometricMean(doubleArray, size);

    if (geometricMean != 0) {
        cout << "Geometric Mean: " << geometricMean << endl;
    }

    // Deallocate the dynamically allocated memory
    delete[] doubleArray;

    return 0;
}