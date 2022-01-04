//
// Created by Agnieszka on 04.01.2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include "funkcje_pomocnicze.h"
using namespace std;
#ifndef MAIN_CPP_KLASA_TESTOWA_H
#define MAIN_CPP_KLASA_TESTOWA_H
class test {

    int a=5;
    string b="lalalla";

public:
    test(){
        a=5;
        b="lalalla";
    }

    test(int a,string b){
        this->a=a;
        this->b=b;
    };


    friend ostream& operator<< (ostream& stream, const test& test) {
        stream << test.a<<"\t"<<test.b;
        return stream;
    }

    friend istream& operator>> (istream& stream, test& test) {
        stream >> test.a >> test.b;
        return stream;
    }


    friend bool operator<(const test& test_1, const test& test) {
        return test_1.a < test.a;
    }

    friend bool operator>(const test& test_1, const test& test) {
        return test_1.a > test.a;
    }


    string to_string();
};

#endif //MAIN_CPP_KLASA_TESTOWA_H
