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

void moveSum(std::string instruction, std::map<std::string, Token> map, int& sum, std::string check)
{
    for (int i = 0; i < instruction.size(); ++i)
    {
        check = moveAction(instruction[i], check, map);
        if (check != "ZZZ")
            sum++;
        else return;
    }
    if (check != "ZZZ")
        moveSum(instruction, map, sum, check);
}

void moveFrame(std::string instruction, std::map<std::string, Token> map)
{
    std::map<std::string, Token>::iterator it;

}

int moveRoutine(std::string instruction, std::map<std::string, Token> map, std::map<std::string, Token>::iterator it)
{
    while (it != map.end())
    {
        if (it->first[2] == 'A')
        {
            int sum = 1;
            moveSum(instruction, map, sum, it->first);
            return sum;
        }
        ++it;
    }


}

int main()
{
    // std::ifstream ifs ("input.txt");
    std::ifstream ifs ("test3.txt");
    std::string line;
    std::getline(ifs, line);
    std::string instruction = line;
    std::getline(ifs, line);
    std::map<std::string, Token> map;
    while(std::getline(ifs, line))
    {
        std::string name = line.substr(0, 3);
        size_t openPos = line.find('(');
        size_t closePos = line.find(')');
        std::string left = line.substr(openPos + 1, line.find(',') - openPos - 1);
        std::string right = line.substr(line.find(',') + 1, closePos - line.find(',') - 1);
        Token toc = {left, right};
        map.insert(std::make_pair(name, toc));
    }
    printMap(map);
    // int sum = 1;
    // bool start = true;
    // std::string check;
    // moveSum(instruction, map, sum, start, check);
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}