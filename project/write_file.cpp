#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	
    ofstream out_file("output.txt", ios::app);
    if (!out_file) {
        cerr << "Error Creating File" << endl;
        return 1;
    }

    string line;

    cout << "Enter something to write to the file: ";
    getline(cin, line);
    out_file << line << endl;

    out_file.close();
	return 0;
}