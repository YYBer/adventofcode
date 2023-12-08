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

bool moveCheck(char c, std::string name, std::map<std::string, Token> map)
{
    std::string check = moveAction(c, name, map);
    if (check == "ZZZ")
        return true;
    return false;
}

void moveSum(std::string instruction, std::map<std::string, Token> map, int sum)
{
    std::string check;
    for (int i = 1; i < instruction.size(); ++i)
    {
        check = moveAction(instruction[0], "AAA", map);
        std::cout << "check:" << check << std::endl;
        if (check != "ZZZ")
        {
            if (!moveCheck(instruction[i], check, map))
                sum += 1;
        }
        else return;
    }
    if (check != "ZZZ")
    {
        sum++;
        moveSum(instruction, map, sum);
    }
}


int main()
{
    // std::ifstream ifs ("input.txt");
    std::ifstream ifs ("test2.txt");
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
        // std::cout << "left:" << left << std::endl;
        // std::cout << "pair:"<< pair << std::endl;
        std::string righttmp = pair.substr(5);
        std::string right = righttmp.substr(0, righttmp.find(')'));
        // // std::cout << "right:" << right << std::endl;
        map.insert(std::make_pair(name, Token{left, right}));
    }
    printMap(map);
    int sum = 1;
    moveSum(instruction, map, sum);
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}