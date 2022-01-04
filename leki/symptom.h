//
// Created by Agnieszka on 04.01.2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include "funkcje_pomocnicze.h"
using namespace std;

#ifndef MAIN_CPP_SYMPTOM_H
#define MAIN_CPP_SYMPTOM_H
/// Klasa obrazująca symptom choroby
class symptom {
    int id; /*!< zmienna typu int, w której przechowywane jest ID objawu */
    string name; /*!< zmienna typu string, w której przechowywana jest nazwa objawu */

public:
    symptom() {
        id = 0;
        name = "";
    }

    symptom(int id, string name) {
        this->id = id;
        this->name = name;
    }

    symptom(const symptom& sym) {
        id = sym.id;
        name = sym.name;
    }

    symptom& operator=(const symptom& sym) {
        id = sym.id;
        name = sym.name;
        return *this;
    }

    friend bool operator<(const symptom& sym1, const symptom& sym2) {
        return sym1.name < sym2.name;
    }
    friend bool operator>(const symptom& sym1, const symptom& sym2) {
        return sym1.name > sym2.name;
    }
    friend ostream& operator<< (ostream& stream, const symptom& sym) {
        stream << sym.name;
        return stream;
    }

    /// Metoda odpowiedzialna za zwracanie ID symptomu, czyli jego unikalnego nuemru
    ///
    /// @returns id - zwraca zmienną typu int, w któej przechowywane jest ID symptomu
    int get_id();

    /// Metoda odpowiedzialna za zwracanie nazwy symptomu
    ///
    /// @returns name - zwraca zmienną typu string, w któej przechowywana jest nazwa symptomu
    string get_name();
};
#endif //MAIN_CPP_SYMPTOM_H
