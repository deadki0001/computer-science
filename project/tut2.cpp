#include <cstdlib>
#include <iostream>
#include <string> // allow us to work with string manipulation
#include <limits> // min and max values for data types

using namespace std;

int g_iRandNum = 0; // hungrian notation for global variable // try to avoid using global variables

const double PI = 3.14159265; // variables wont change during the couse of the program

int main(){
    bool bMarried = true;
    char chMyGrade = 'A'; // 256 different characters
    unsigned short int u16Age = 43; // 0 - 65536
    short int siWeight = 180;          // -32 768 > 32 000
    int nDays = 7; // in the billons -2 Billion > 2 Billion
    long lBigNum = 100000;
    float fPi = 3.14159; // Precise to 6 Digits after the decimal point
    
    cout << "Min Double "  << numeric_limits<double>::min() << endl;  // doubles have 16 points of preceision
    cout << "Max Double "  << numeric_limits<double>::max() << endl;    

    double dbBigDouble = 1.1111111111111111;
    double dbBigDouble2 = 1.1111111111111111;
    double dbBigDoubleSum = dbBigDouble + dbBigDouble2;
    printf("dbFloatSum Precision : %.20f\n", dbBigDoubleSum);


    long double ldPi = 3.14;
    auto whatWillIBe = true;

    cout << "int Size " << sizeof(int) << endl;

    printf("%c %d %5d %3.f %s\n", 'A', 10, 5, 3.1234, "Hi");

    return 0;
    
}

