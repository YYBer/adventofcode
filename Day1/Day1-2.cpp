#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cctype>

int main (){
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::map<int, std::string> myMap;
    myMap.insert(std::make_pair(1, "one"));
    myMap.insert(std::make_pair(2, "two"));
    myMap.insert(std::make_pair(3, "three"));
    myMap.insert(std::make_pair(4, "four"));
    myMap.insert(std::make_pair(5, "five"));
    myMap.insert(std::make_pair(6, "six"));
    myMap.insert(std::make_pair(7, "seven"));
    myMap.insert(std::make_pair(8, "eight"));
    myMap.insert(std::make_pair(9, "nine"));
    int sum = 0;
    int result = 0;
    std::string input = "";
   // std::ifstream ifs("infile.txt");
    std::ifstream ifs("infiletest.txt");
    size_t i;
    size_t j;
    while(std::getline(ifs, input))
    {
        for(i = 0; i < input.size(); ++i)
        {
            if (input[i]<= '9' && input[i] >= '0')
            {
                a = input[i] - 48;
                break;
            }
        }
        for (std::map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it)
        {
            j = input.find(it->second);
            // std::cout << "jjjjjj: " << j << std::endl;
            // std::cout << it->second << std::endl;
            if (j != std::string::npos)
            {
                c = it->first + 1;
                // std::cout << " ccccc : " << c << std::endl;
                break;
            }
        }
        // std::cout << "i: " << i << " j: " << j  << " a: " << a << " c: " << c << std::endl;
        if(i > j)
            a = c;
        i = 0;
        j = 0;  
        for(i = input.size(); i >= 0; --i)
        {
            if (input[i]<= '9' && input[i] >= '0')
            {
                b = input[i] - 48;
                break;
            }
        } 
        std::map<int, std::string>::reverse_iterator it; 
        for (it = myMap.rbegin(); it != myMap.rend(); ++it) {
        j = input.rfind(it->second);
        if (j != std::string::npos)
        {
            d = it->first;
            break;
        }
        // std::cout << "end: i: " << i << " j: " << j << std::endl;
        std::cout << "end: i: " << i << " j: " << j  << " b: " << b << " d: " << d << std::endl;
        if (i < j && j != std::string::npos)
            b = d;
    }   
        sum = 10*a + b;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        std::cout << "sum " << sum << std::endl; 
        result += sum;
    }
    std::cout << result << std::endl;
}
