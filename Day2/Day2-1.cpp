#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>

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

bool validGame(std::string input)
{
    // int red = 12;
    // int green = 13;
    // int blue = 14;
    size_t pos = input.find(':');
    std::string cubes;
    if (pos != std::string::npos)
        cubes = input.substr(pos + 2);
    int num = -1;
    // std::cout << "cubes" << cubes << std::endl;
    for(int i = 0; i < cubes.size(); ++i)
    {
        num = getNumber(cubes, "green");
        std::cout << " green_num1: " << num;
        if (num >= 13)
            return false;
        num = getNumber(cubes, "red");
        std::cout << " red_num2: " << num;
        if (num >= 12)
            return false;
        num = getNumber(cubes, "blue");
        std::cout << " blue_num3: " << num << std::endl;
        if (num >= 14)
            return false;
        // std::cout << "num " << num << std::endl;
    }
    return true;    
}

int main()
{
    std::string input = "";
    std::ifstream ifs ("test.txt");
    int sum = 0;
    int gameID = 31;
    while(std::getline(ifs, input))
    {
        gameID += 1;
        if (validGame(input))
            sum += gameID;
    }
    std::cout << "sum: "<< sum << std::endl;
}