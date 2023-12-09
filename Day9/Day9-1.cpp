#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>
#include <vector>
#include <locale>
#include <map>

void    printMap(std::map<int, std::string> map)
{
    for(std::map<int, std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " line: " << it->second << "\n"; 
    }
}

int lineHandle(std::string line)
{
    std::map<int, int> numbers;
    std::map<int, int> diff;
    std::istringstream iss(line);
    int num;
    int i = 0;
    while (iss >> num)
    {
        numbers[i] = num;
        i++;
    }
    for(int j = 0; j < i - 1; ++j)
        diff[j] = numbers[j + 1] - numbers[j];
    for(int j = 0; j < diff.size() - 1; ++j)
    {
        int diff = numbers[j + 1] - numbers[j];
        if (diff != 0)
            break;
    }

   
    
}


int mapFrame(std::map<int, std::string> map)
{
    int sum = 0;
    for(std::map<int, std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::string line = it->second;
        sum = lineHandle(line);
        sum += sum;
    }
    return sum;
}

int main()
{
    std::ifstream ifs ("test.txt");
    std::string line;
    int i = 0;
    std::map<int, std::string> map;
    while(std::getline(ifs, line))
    {
        map[i] = line;
        i++;
    }
    // printMap(map);
    int sum = mapFrame(map);
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}