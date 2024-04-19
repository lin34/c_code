#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
class TextInput
{
public:
    std::vector<char> text;
    virtual void add(char c) {
        text.push_back(c);
    }

    std::string getValue() {
        //std::string out = str(text.begin(), text.end());
        std::string str(text.begin(), text.end()); 
        return str;
    }
};

class NumericInput : public TextInput {
    void add(char c) override{
        if (isdigit(c)){
            text.push_back(c);
        }
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif