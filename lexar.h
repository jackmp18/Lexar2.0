#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;

bool isNumber(std::string const& str) {
    // forgot what I was trying to do here but it works.
    return std::regex_match(str, std::regex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$"));
}

char isSeperators(std::string str) {
    char cstr = str[0];
    return cstr;
}

char isOperators(std::string str) {
    char cstr = str[0];
    return cstr;
}

void lexar(std::ofstream& oFile, std::string lexeme) {
    std::vector<std::string>::iterator checkKeywords;
    std::vector<char>::iterator checkSeperators;
    std::vector<char>::iterator checkOperators;

    // vector of possible keywords, seperators, and operators
    std::vector<std::string> keywords{ "bool", "break", "case", "char", "double",
                                        "float", "if", "int", "void", "while", "last" };
    std::vector<char> seperators{ '(', ')', '{', '}', ';' };
    std::vector<char> operators{ '+', '-', '*', '/', '=' };

    // identifies individual lexeme 
    checkKeywords = std::find(keywords.begin(), keywords.end(), lexeme);
    checkSeperators = std::find(seperators.begin(), seperators.end(), isSeperators(lexeme));
    checkOperators = std::find(operators.begin(), operators.end(), isOperators(lexeme));

    if (checkKeywords != keywords.end()) {
        oFile << "Keyword" << "              " << lexeme << "\n";
    }
    else if (isNumber(lexeme)) {
        oFile << "Real" << "                 " << lexeme << "\n";
    }
    else if (checkSeperators != seperators.end()) {
        oFile << "Seperator" << "            " << lexeme << "\n";
    }
    else if (checkOperators != operators.end()) {
        oFile << "Operator" << "             " << lexeme << "\n";
    }
    else {
        oFile << "Identifier" << "           " << lexeme << "\n";
    }
}

bool q4() { // final state
    return true;
}

bool q3(string input, int location, int length) {
    if (input[location] == 'e' && location <= length) {
        location++;
        return true;
    }
    else {
        return false;
    }
}

bool q2(string input, int location, int length) {
    if (input[location] == 'l' && location <= length) {
        location++;
        return true;
    }
    else {
        return false;
    }
}

bool q1(string input, int location, int length) {
    if (input[location] == 'i' && location <= length) {
        location++;
        return true;
    }
    else {
        return false;
    }
}

bool q0(string input, int location, int length) {
    if (input[location] == 'w' && location <= length) {
        location++;
        q0(input, location, length);
    }
    else if (input[location] == 'h' && location <= length && input[location - 1] == 'w') { // also W to insure case such as "hile"
        location++;
        return true;
    }
    else {
        return false;
    }
}



string FSA(string input, int length) {
    int i = 0;
    if (q0(input, i, length)) {
        i++;
        i++;
        if (q1(input, i, length)) {
            i++;
            if (q2(input, i, length)) {
                i++;
                if (q3(input, i, length)) {
                    if (q4()) {
                        return "Accept Q4";
                    }
                }
                else {
                    return "Regect Q3";
                }
            }
            else {
                return "Regect Q2";
            }
        }
        else {
            return "Regect Q1";
        }
    }
    else {
        return "Regect Q0";
    }
}







