#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream in_file("poem.txt");
    ofstream out_file("poem-new.txt");
    if (!in_file) {
        cerr << "Error Creating File" << endl;
        return 1;
    }
    if (!out_file) {
        cerr << "Error Creating File" << endl;
        return 1;        
    }

    string line{};
    while (getline(in_file, line))
    out_file << line << endl;

    cout << "File copied" << endl;
    in_file.close();
    out_file.close();
	return 0;
}