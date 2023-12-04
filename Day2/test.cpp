#include <iostream>
#include <string>
#include <sstream>

// int getNumberBeforeColor(const std::string& input, const std::string& color) {
//     std::istringstream iss(input);
//     std::string word;
//     int prevNumber = -1; // Default value if color not found
    
//     while (iss >> word) {
//         if (word == color) {
//             return prevNumber; // Return the number before the color
//         }
//         std::istringstream check(word);
//         int number;
//         if (check >> number) {
//             prevNumber = number; // Store the number before the color
//         }
//     }
//     return -1; // Return default value if color not found
// }

// int main() {
//     std::string input = "7 green, 14 red, 5 blue; 8 red, 4 green";

//     int numberBeforeGreen = getNumberBeforeColor(input, "green");
//     if (numberBeforeGreen != -1) {
//         std::cout << "Number before 'green': " << numberBeforeGreen << std::endl;
//     } else {
//         std::cout << "'green' not found or no number before it" << std::endl;
//     }

//     int numberBeforeRed = getNumberBeforeColor(input, "red");
//     if (numberBeforeRed != -1) {
//         std::cout << "Number before 'red': " << numberBeforeRed << std::endl;
//     } else {
//         std::cout << "'red' not found or no number before it" << std::endl;
//     }

//     return 0;
// }



int getNumber(std::string cubes, std::string color)
{
    size_t pos = cubes.find(color);
    // std::cout << "pos " << pos << std::endl;
    std::string numsub;
    std::istringstream cubesline(cubes);
    if (pos != std::string::npos)
    {
        // std::cout << "cubes " << cubes << " cubes[pos] " << cubes[pos]<< std::endl;
        numsub = cubes.substr(0, pos);
        int i = numsub.size();
        // std::cout << "i " << i  << " numsub: " << numsub  << " dig1: " << numsub[i - 3] << " dig2: "<< numsub[i - 2] << std::endl;
        if  (i == 1)
            return (numsub[0] - 48);
        else
        {
            if (numsub[i - 3] <= '9' && numsub [i - 3] >= '0')
                return (10 * (numsub[i - 3] - 48) + numsub[i - 2] - 48);
            else
                return (numsub[i - 2] - 48);
        }
    }
    return -1;
}

int main()
{
    std::cout << getNumber("7 green, 14 red, 5 blue;", "green") << std::endl;
}