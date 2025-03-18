#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void generateValues(double*& array, int num) {
    int generateValuesSize = num + 10;
    array = new double[generateValuesSize];
    int x = -10;
    double* ptr = array;

    for (int i = 0; i < generateValuesSize; i++) {
        int A = rand() % 101 - 50;
        int B = rand() % 101 - 50;
        int C = rand() % 101 - 50;
        int D = rand() % 101 - 50;

        double val = A * x * x + B * sin(C * x) + D;
        *ptr = val;
        x++;
        ptr++;
    }
}

void getgenerateValuesStats(double* array, int count, double& avg, double& deviation, double& posTotal, double& negTotal) {
    double total = 0;
    posTotal = 0;
    negTotal = 0;

    double* current = array;
    for (int i = 0; i < count; i++) {
        total += *current;
        if (*current > 0) posTotal += *current;
        if (*current < 0) negTotal += *current;
        current++;
    }

    avg = total / count;

    double varSum = 0;
    current = array;
    for (int i = 0; i < count; i++) {
        double diff = *current - avg;
        varSum += diff * diff;
        current++;
    }

    deviation = sqrt(varSum / count);
}

typedef double (*MathFunc)(double);

double sqrtFunc(double x) { return x >= 0 ? sqrt(x) : x; }
double logFunc(double x) { return x > 0 ? log(x) : x; }
double recipFunc(double x) { return x != 0 ? 1 / x : x; }

void transformgenerateValues(double* source, double*& result, int count, MathFunc transform) {
    result = new double[count];
    double* src = source;
    double* dest = result;

    for (int i = 0; i < count; i++) {
        *dest = transform(*src);
        src++;
        dest++;
    }
}

double sumgenerateValuesRecursive(double* vals, int remaining) {
    if (remaining == 0) return 0;
    return *vals + sumgenerateValuesRecursive(vals + 1, remaining - 1);
}

void swapgenerateValuesPointers(double** first, double** second) {
    double* temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    srand(time(0));
    int userInput;
    cout << "Enter a value for n: ";
    cin >> userInput;

    int actualSize = userInput + 10;
    double* arraygenerateValues = nullptr;
    generateValues(arraygenerateValues, userInput);

    double average, stdDev, posSum, negSum;
    getgenerateValuesStats(arraygenerateValues, actualSize, average, stdDev, posSum, negSum);

    cout << "\nStatistics:\n";
    cout << "Mean: " << average << endl;
    cout << "Standard Deviation: " << stdDev << endl;
    cout << "Sum of Positives: " << posSum << endl;
    cout << "Sum of Negatives: " << negSum << endl;

    cout << "\nChoose a transformation:\n";
    cout << "1 = sqrt, 2 = log, 3 = inverse: ";
    int userChoice;
    cin >> userChoice;

    MathFunc mathTransform = nullptr;
    if (userChoice == 1) mathTransform = sqrtFunc;
    else if (userChoice == 2) mathTransform = logFunc;
    else if (userChoice == 3) mathTransform = recipFunc;

    double* transformedarray = nullptr;
    transformgenerateValues(arraygenerateValues, transformedarray, actualSize, mathTransform);

    cout << "\nTransformed Values:\n";
    double* displayPtr = transformedarray;
    for (int i = 0; i < actualSize; i++) {
        cout << *(displayPtr++) << endl;
    }

    double recursiveTotal = sumgenerateValuesRecursive(arraygenerateValues, actualSize);
    cout << "\nRecursive Total Sum: " << recursiveTotal << endl;

    double* backupgenerateValues = nullptr;
    generateValues(backupgenerateValues, userInput);

    swapgenerateValuesPointers(&arraygenerateValues, &backupgenerateValues);

    cout << "\nAfter Swap - First 5 elements from swapped generateValues:\n";
    for (int i = 0; i < 5; i++) {
        cout << *(arraygenerateValues + i) << endl;
    }

    delete[] arraygenerateValues;
    delete[] backupgenerateValues;
    delete[] transformedarray;

    return 0;
}
