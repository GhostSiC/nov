
#include <iostream>

void ex3() {

    std::string str = "   \t  przykladowy string  ";

    std::cout << '|' << str << '|' << '\n';

    for (int i = 0; i < str.length() - 1; i++) {
        if (isalpha(str.at(i))) {
            //str = str.substr(i);
            str.erase(0, i);
            break;
        }    
    }

    for (int i = str.length() - 1; i >= 0 ; i--) {
        if (isalpha(str.at(i))) {
            //str = str.substr(0, i+1);
            str.erase(i+1);
            break;
        }
    }
    std::cout << '|' << str << '|' << '\n';
    std::cout << str.length() << '\n';
}

int main()
{
    ex3();
}
