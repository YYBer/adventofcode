#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>
#include <vector>
#include <locale>

std::vector<int> createList(std::string sub)
{
    std::vector<int> list;
    int num = 0;
    for (int i = 0; i < sub.size(); ++i)
    {
        if (isdigit(sub[i]) && isdigit(sub[i + 1]))
        {
            num = 10 * (sub[i] - 48) + sub[i + 1] - 48;
            list.push_back(num);
        }
        else if (isdigit(sub[i]) && !isdigit(sub[i + 1]) && !isdigit(sub[i - 1]))
        {
            num = sub[i] - 48;
            list.push_back(num);
        }
    }
    return list;
}

bool loopCheck(int num, std::vector<int> list2)
{
    for (std::vector<int>::iterator it = list2.begin(); it != list2.end(); ++it)
    {
        if ((*it) == num)
            return true;
    }
    return false;
}

int sumconsult(int sum)
{
    int result = 1;
    if (sum <= 2)
        return sum;
    else{
        for(int i = 1; i < sum; ++i)
            result *= 2;
    }
    return result;
    
}
int lineCheck(std::vector<int> list1, std::vector<int> list2)
{
    int sum = 0;
    for (std::vector<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        if (loopCheck((*it), list2))
            sum++;
    }
    int result = sumconsult(sum);
    return result;
}

int main()
{
    std::string input = "";
    std::string lastline= "";
    std::ifstream ifs ("input.txt");
    int sum = 0;
    while(std::getline(ifs, input))
    {
        std::string line = input.substr(9);
        size_t pos = line.find('|');
        std::string sub1 = line.substr(0, pos - 1);
        std::string sub2 = line.substr(pos + 2);
        std::vector<int> list1 = createList(sub1);
        std::vector<int> list2 = createList(sub2);
        sum += lineCheck(list1, list2);
        list1.clear();
        list2.clear();
    }
    std::cout << "sum: "<< sum << std::endl;
    ifs.close();
}