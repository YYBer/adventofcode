#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>
#include <vector>
#include <locale>
#include <map>

struct Token {
    std::string left;
    std::string right;
};

void    printMap(std::map<std::string, Token> map)
{
    for(std::map<std::string, Token>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " = (" << it->second.left  << " , "<< it->second.right << ")\n"; 
    }
}

std::string moveAction(char c, std::string name, std::map<std::string, Token> map)
{
    for(std::map<std::string, Token>::iterator it = map.begin(); it != map.end(); ++it)
    {
        if (it->first == name)
        {
            if (c == 'L')
                return it->second.left;
            else return it->second.right;
        }
    }
    return NULL;
}

void moveSum(std::string instruction, std::map<std::string, Token> map, int& sum, bool start,std::string check)
{
    for (int i = 0; i < instruction.size(); ++i)
    {
        if(i == 0 && start == true)
            check = moveAction(instruction[i], "AAA", map);
        else
            check = moveAction(instruction[i], check, map);
        start = false;
        if (check != "ZZZ")
            sum++;
        else return;
    }
    if (check != "ZZZ")
        moveSum(instruction, map, sum, start, check);
}


int main()
{
    std::ifstream ifs ("input.txt");
    std::string line;
    std::getline(ifs, line);
    std::string instruction = line;
    std::getline(ifs, line);
    std::map<std::string, Token> map;
    while(std::getline(ifs, line))
    {
        std::string name = line.substr(0, 3);
        std::string pair = line.substr(line.find('(') + 1, line.find(')'));
        std::string left = pair.substr(0, pair.find(','));
        std::string righttmp = pair.substr(5);
        std::string right = righttmp.substr(0, righttmp.find(')'));
        Token toc = {left, right};
        map.insert(std::make_pair(name, toc));
    }
    // printMap(map);
    int sum = 1;
    bool start = true;
    std::string check;
    moveSum(instruction, map, sum, start, check);
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}