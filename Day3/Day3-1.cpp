#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>
#include <vector>

int getPos(std::string input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (i == input.size() - 1)
        {
            if ((input[i] >= '0' && input[i] <= '9'))
                return i;
        }
        else if (i == input.size() - 2)
        {
            if ((input[i] >= '0' && input[i] <= '9' && input[i + 1] >= '0' && input[i + 1] <= '9'))
            return i + 1;
        }
        else if (input[i] >= '0' && input[i] <= '9' && input[i + 1] >= '0' && input[i + 1] <= '9' && input[i + 2] >= '0' && input[i + 2] <= '9')
            return i + 2;
        else if ((input[i] >= '0' && input[i] <= '9' && input[i + 1] >= '0' && input[i + 1] <= '9' && (input[i + 2] < '0' || input[i + 2] > '9')))
            return i + 1;
        else if ((input[i] >= '0' && input[i] <= '9' && (input[i + 1] < '0' || input[i + 1] > '9' )))
            return i;
    }
    return -1;    
}

int getNumber(std::string input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (i == input.size() - 1)
        {
            if ((input[i] >= '0' && input[i] <= '9'))
                return (input[i] - 48);
        }
        else if (i == input.size() - 2)
        {
            if ((input[i] >= '0' && input[i] <= '9' && input[i + 1] >= '0' && input[i + 1] <= '9'))
            return (10 * (input[i] - 48) + (input[i + 1] - 48));
        }
        else if (input[i] >= '0' && input[i] <= '9' && input[i + 1] >= '0' && input[i + 1] <= '9' && input[i + 2] >= '0' && input[i + 2] <= '9')
            return (100 * (input[i] - 48) + 10 * (input[i + 1] - 48) + input[i + 2] - 48);
        else if ((input[i] >= '0' && input[i] <= '9' && input[i + 1] >= '0' && input[i + 1] <= '9' && (input[i + 2] < '0' || input[i + 2] > '9')))
            return (10 * (input[i] - 48) + (input[i + 1] - 48));
        else if ((input[i] >= '0' && input[i] <= '9' && (input[i + 1] < '0' || input[i + 1] > '9' )))
            return (input[i] - 48);
    }
    return -1;
}

bool adjacentCheck(char c)
{
    if (c != '.')
        return true;
    return false;
}

bool validtopline(std::string input, std::string nextline, int pos)
{
    if (pos == 3)
    {
        if (adjacentCheck(input[pos + 1]) || adjacentCheck(nextline[pos-3]) \
        || adjacentCheck(nextline[pos-2]) || adjacentCheck(nextline[pos-1]) || adjacentCheck(nextline[pos]) || adjacentCheck(nextline[pos + 1]))
            return true;
    }
    else if (pos == input.size())
    {
        if (adjacentCheck(input[pos-3]) || adjacentCheck(nextline[pos-3]) \
        || adjacentCheck(nextline[pos-2]) || adjacentCheck(nextline[pos-1]) || adjacentCheck(nextline[pos]))
            return true;
    }             
    else if (adjacentCheck(input[pos-3]) || adjacentCheck(input[pos + 1]) || adjacentCheck(nextline[pos-3]) \
    || adjacentCheck(nextline[pos-2]) || adjacentCheck(nextline[pos-1]) || adjacentCheck(nextline[pos]) || adjacentCheck(nextline[pos + 1]))
        return true;
    return false;
}

int validNumber(std::string input, std::vector<std::string> map)
{
    int num;
    int pos;
    std::vector<std::string>::iterator it = map.begin();
    if ((*it) == input)
    {
        num = getNumber(input);
        pos = getPos(input);
        if (num >= 100)
        {
            it++;
            std::string nextline = (*it);
            if (validtopline(input, nextline, pos))
                return 

        }
    }
}


int validNumberSum(std::string input, std::vector<std::string> map)
{
    if (linenum == 0)


}




int main()
{
    std::string input = "";
    std::string lastline= "";
    std::ifstream ifs ("input.txt");
    int num;
    int sum;
    int linenum = 0;
    std::vector<std::string> map;
    while(std::getline(ifs, input))
    {
        map.push_back(input);
        num = validNumberSum(input, map);
        if (num != -1)
            sum += num;
        linenum++;
    }
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}