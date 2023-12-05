#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>

int getNumber(std::string cubes, std::string color, int pos)
{
    std::string numsub = cubes.substr(0, pos);
    size_t i = numsub.size();
    if (i == 1)
            return (numsub[0] - 48);
    else
    {
        if (numsub[i - 2] <= '9' && numsub [i - 2] >= '0')
            return (10 * (numsub[i - 2] - 48) + numsub[i - 1] - 48);
        else
            return (numsub[i - 1] - 48);
    }
}

int fewestNumberCube(std::string input)
{
    size_t pos = input.find(':');
    std::string cubes;
    if (pos != std::string::npos)
        cubes = input.substr(pos + 2);
    int numr = 1;
    int numg = 1;
    int numb = 1;
    int num;
    for(int i = 0; i < cubes.size(); ++i)
    {
        if (cubes[i] == 'r' && cubes[i - 1] == ' ')
        {
            num = getNumber(cubes, "red", i - 1);
            if (num > numr)
                numr = num;
        }
        else if (cubes[i] == 'g')
        {
            num = getNumber(cubes, "green", i - 1);
            if (num > numg)
                numg = num;
        }
        else if (cubes[i] == 'b')
        {
            num = getNumber(cubes, "blue", i - 1);
            if (num > numb)
                numb = num;
        }
    }
    return numr*numg*numb;    
}

int main()
{
    std::string input = "";
    std::ifstream ifs ("input.txt");
    int sum = 0;
    int gameID = 0;
    while(std::getline(ifs, input))
    {
        gameID++;
        sum += fewestNumberCube(input);
    }
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}