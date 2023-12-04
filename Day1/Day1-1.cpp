#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

int main (){
    int a = 0;
    int b = 0;
    int sum = 0;
    int result = 0;
    std::string input = "";
    std::ifstream ifs("infile.txt");
    while(std::getline(ifs, input))
    {
        for(int i = 0; i < input.size(); ++i)
        {
            if (input[i]<= '9' && input[i] >= '0')
            {
                a = input[i] - 48;
                break;
            }
        }
        for(int i = input.size(); i >= 0; --i)
        {
            if (input[i]<= '9' && input[i] >= '0')
            {
                b = input[i] - 48;
                break;
            }
        }
        sum = 10*a + b;
        a = 0;
        b = 0;
        std::cout << "sum " << sum << std::endl; 
        result += sum;
    }
    ifs.close();
    std::cout << result << std::endl;
}