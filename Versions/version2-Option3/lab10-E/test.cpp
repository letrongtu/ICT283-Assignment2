#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

#include "Validator.h"

int main() {
    string filename = "1";

    if(isValidNumber(filename)){
        cout << "Here" << endl;
    }

    return 0;
}
