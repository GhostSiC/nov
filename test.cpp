
#include <iostream>
#include <string>


void ex3(std::string& str) {

    std::cout << '|' << str << '|' << '\n';

    for (int i = 0; i < str.length() - 1; i++) {
        if (isalpha(str.at(i))) {
            //str = str.substr(i);
            str.erase(0, i);
            break;
        }
    }

    for (int i = str.length() - 1; i >= 0; i--) {
        if (isalpha(str.at(i))) {
            //str = str.substr(0, i+1);
            str.erase(i + 1);
            break;
        }
    }
    std::cout << '|' << str << '|' << '\n';
    std::cout << str.length() << '\n';

}


template <class T>
T ex3_1(T data) {

    //check if string or const char* (only this 2 type can have whitespace)
    if (!std::is_same<T, std::string>::value && !std::is_same<T,const char*>::value )
        return data;


    //std::string data_as_string = data;

    //used lambda bc dont want to use break in for
    [&](){
        for (int i = 0; i < data.length() - 1; i++) {
            if (!isspace(data.at(i))) {
                data.erase(0, i);
                return data;
            }
        }
    }();
    
    
    [&](){
        for (int i = data.length() - 1; i >= 0; i--) {
            if (!isspace(data.at(i))) {
                data.erase(i + 1);
                return data;
            }
        }
    }();

    std::cout << '|' << data << '|' << '\n';

    return data;
}

int main()
{
    std::string tekst_to_check = "   \t  przykladowy string  ";
    int int_to_check = 123;
    const char* test_char = "  \t inny tekst      ";
    
    std::cout << ex3_1<std::string>(tekst_to_check) << '\n';
    std::cout << ex3_1<const char*>(test_char) << '\n';
    //std::cout << ex3_1<int>(123) << '\n';
    
}
