#include <cstdlib>          // Preprocessor Directive  // Functions for converting from one data type to another int/string - Similar to the Import Command
#include <iostream> // if you want to receive input and output to a user 
using namespace std;

int main(int argc, char* argv[]){          // all the codes will be executed from the function called main. // arguments are words or characters with spaces in between them //argv[] = an array of strings
    cout << "Hello World" << endl;            // the cout function comes from the iostream library // if you need to output information on the Users Monitor --> use the cout command // endl basically states that the function must be carried out immediately.

    if(argc != 1){
        cout << "You entered" << argc << "arguments\n";
        
        for(int i = 0; i < argc; ++i){
            cout << argv[i] << "\n";
        }
    }
    return 0;  // This would mean that the program executed without any errors
}            
                        




      
                                   