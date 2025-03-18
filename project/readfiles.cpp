#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string line;
    int num;
    double total;
	
	ifstream in_file;
	in_file.open("test.txt");
	if (!in_file) {
		cerr << "Problem Opening File" << endl;
		return 1;
	}
	
    in_file >> line >> num >> total;

    cout << line << endl;
    cout << num << endl;
    cout << total << endl;
    in_file.close();
	return 0;
}