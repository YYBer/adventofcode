#include <iostream>
#include <string>
#include <map>

int main() {
    std::string inputString = "aninefivetwoonedfs";
    int foundNumber = -1;

    std::map<std::string, int> numberMap;
    numberMap["one"] = 1;
    numberMap["two"] = 2;
    numberMap["three"] = 3;
    numberMap["four"] = 4;
    numberMap["five"] = 5;
    numberMap["six"] = 6;
    numberMap["seven"] = 7;
    numberMap["eight"] = 8;
    numberMap["nine"] = 9;

    size_t found;
    std::map<std::string, int>::iterator it;
    for (it = numberMap.begin(); it != numberMap.end(); ++it) {
        found = inputString.find(it->first);
        if (found != std::string::npos) {
            foundNumber = it->second;
            break;
        }
    }

    if (foundNumber != -1) {
        std::cout << "The number found is: " << foundNumber << std::endl;
    } else {
        std::cout << "No number found in the string." << std::endl;
    }
    std::cout << "found" << found << std::endl;

    return 0;
}
