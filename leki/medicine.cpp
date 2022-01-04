//
// Created by Agnieszka on 04.01.2022.
//

#include "medicine.h"

string medicine::convert() {
    string output;
    output += to_string(id);
    output += '\t';
    output += name;
    output += '\t';
    output += to_string(age_min);
    output += '\t';
    output += to_string(age_max);
    output += '\t';
    for (int i = 0; i < symptoms.count(); i++) {
        output += to_string(symptoms.get(i).get_id());
        if (i < symptoms.count() - 1) {
            output += ',';
        }
    }
    return output;
}

/// Metoda odpowiedzialna za zwracanie ID leku, czyli jego unikalnego nuemru
///
/// @returns id - zwraca zmienną typu int, w któej przechowywane jest ID leku
int medicine::get_id() {
    return id;
}

/// Metoda odpowiedzialna za zwracanie nazwy leku
///
/// @returns name - zwraca zmienną typu string, w któej przechowywana jest nazwa leku
string medicine::get_name() {
    return name;
}

/// Metoda odpowiedzialna za zwracanie minimalnego wieku osoby, która może zażyć lek
///
/// @returns age_min - zwraca zmienną typu int, w któej przechowywany jest minimalny wiek
int medicine::get_age_min() {
    return age_min;
}

/// Metoda odpowiedzialna za zwracanie maksymalnego wieku osoby, która może zażyć lek
///
/// @returns age_min - zwraca zmienną typu int, w któej przechowywany jest maksymalny wiek
int medicine::get_max_age() {
    return age_max;
}


/// Metoda odpowiedzialna za zwracanie listy symptomów, na które działa dany lek
///
/// @returns symptoms - zwraca zmienną typu linked_list<symptom>, w któej przechowywana jest lista symptomów do danego leku
linked_list<symptom> medicine::get_symptoms() {
    return symptoms;
}