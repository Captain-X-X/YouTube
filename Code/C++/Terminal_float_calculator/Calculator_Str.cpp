#include <iostream>

int main(){
    std::string Str1, Str2;
    bool Sentence = false;

    std::cout << "Input 2 Strings:";
    std::cin >> Str1 >> Str2;

    if (Sentence)
        std::cout << Str1 << Str2 << '\n';
        return 0;

    std:: cout << Str1 + Str2 << '\n';

    return 0;
}