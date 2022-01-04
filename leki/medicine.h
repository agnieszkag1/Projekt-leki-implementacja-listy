//
// Created by Agnieszka on 04.01.2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include "linked_list.cpp"
#include "funkcje_pomocnicze.h"
#include "symptom.h"


using namespace std;
#ifndef MAIN_CPP_MEDICINE_H
#define MAIN_CPP_MEDICINE_H
class medicine {
    int id; /*!< zmienna typu int, w której przechowywane jest ID leku */
    string name;  /*!< zmienna typu string, w której przechowywana jest nazwa leku  */
    int age_min; /*!< zmienna typu int, w której przechowywany jest minimalny wiek dla osoby używającej lek */
    int age_max; /*!< zmienna typu int, w której przechowywany jest maksymalny wiek dla osoby używającej lek */
    linked_list<symptom> symptoms; /*!< zmienna typu linked_list<symptom>, w której przechowywana jest lista objawów, na które działa dany lek  */

public:

    medicine() {
        id = 0;
        name = "";
        age_min = 0;
        age_max = 0;
    }

    medicine(int id, string name, int age_min, int age_max, linked_list<symptom> symptoms) {
        this->id = id;
        this->name = std::move(name);
        this->age_min = age_min;
        this->age_max = age_max;
        this->symptoms = symptoms;
    }

    medicine(const medicine& med) {
        id = med.id;
        name = med.name;
        age_min = med.age_min;
        age_max = med.age_max;
        symptoms = med.symptoms;
    }

    medicine& operator=(const medicine& med)
    {
        id = med.id;
        name = med.name;
        age_min = med.age_min;
        age_max = med.age_max;
        symptoms = med.symptoms;
        return *this;
    }

    friend bool operator<(const medicine& med1, const medicine& med2) {
        return med1.name < med2.name;
    }
    friend bool operator>(const medicine& med1, const medicine& med2) {
        return med1.name > med2.name;
    }
    friend ostream& operator<< (ostream& stream, const medicine& med) {
        stream << "Medicine name - " << med.name << endl;
        return stream;
    }

    string convert();

    /// Metoda odpowiedzialna za zwracanie ID leku, czyli jego unikalnego nuemru
    ///
    /// @returns id - zwraca zmienną typu int, w któej przechowywane jest ID leku
    int get_id();

    /// Metoda odpowiedzialna za zwracanie nazwy leku
    ///
    /// @returns name - zwraca zmienną typu string, w któej przechowywana jest nazwa leku
    string get_name();

    /// Metoda odpowiedzialna za zwracanie minimalnego wieku osoby, która może zażyć lek
    ///
    /// @returns age_min - zwraca zmienną typu int, w któej przechowywany jest minimalny wiek
    int get_age_min();

    /// Metoda odpowiedzialna za zwracanie maksymalnego wieku osoby, która może zażyć lek
    ///
    /// @returns age_min - zwraca zmienną typu int, w któej przechowywany jest maksymalny wiek
    int get_max_age();

    /// Metoda odpowiedzialna za zwracanie listy symptomów, na które działa dany lek
    ///
    /// @returns symptoms - zwraca zmienną typu linked_list<symptom>, w któej przechowywana jest lista symptomów do danego leku
    linked_list<symptom> get_symptoms();

};
#endif //MAIN_CPP_MEDICINE_H
