#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cctype>


int getFirstNumber(std::string input, std::string num[])
{
    int a = 0;
    int b = 0;
    int i;
    int j;
    int pos;
    for(i = 0; i < input.size(); ++i)
    {
        if (input[i]<= '9' && input[i] >= '0')
        {
            a = input[i] - 48;
            break;
        }
    }
    int tmp = 999;
    for(j = 1; j < 10; ++j)
    {
        pos = input.find(num[j]);
        if (pos != std::string::npos && pos < tmp && pos != -1)
        {
            b = j;
            tmp = pos;
        }
    }
    if (tmp < i)
        a = b;
    return a;
}
int getLastNumber(std::string input, std::string num[])
{
    int c = 0;
    int d = 0;
    int i;
    int j;
    int pos;
    for(i = input.size(); i >= 0; --i)
    {
        if (input[i]<= '9' && input[i] >= '0')
        {
            c = input[i] - 48;
            break;
        }
    }
    int tmp = 0;
    for (j = 1; j < 10; ++j)
    {
        pos = input.rfind(num[j]);
        if (pos != std::string::npos && pos > tmp && pos != -1)
        {
            d = j;
            tmp = pos;
        }
    }
    if (tmp > i)
        c = d;
    return c;
}

int main (){
    std::string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum = 0;
    int result = 0;
    std::string input = "";
    std::ifstream ifs("infile.txt");
    while(std::getline(ifs, input))
    {
        int a = getFirstNumber(input, num);
        int c = getLastNumber(input, num);
        sum = 10*a + c;
        std::cout << "sum " << sum << std::endl; 
        result += sum;
    }
    std::cout << result << std::endl;
}
