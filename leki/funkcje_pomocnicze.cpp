#include <iostream>
#include <fstream>
#include <string>
#include "funkcje_pomocnicze.h"
using namespace std;

/// Metoda, która zwraca podany elemet ze stringa
///
/// @param  line - linia tekstu
/// @param  position - pozycja w lini
/// @param  delimiter - znak rozdzielający
/// @returns output_string
string get_element(string line, int position, char delimiter) {
    string output_string;
    int count = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == delimiter)
        {
            count++;
            continue;
        }
        if (count == position) {
            output_string += line[i];
        }
        else if (count > position) {
            break;
        }
    }
    return output_string;
}


bool read_from_console(int arg, char *argv[], string &input_file_name_med, string &input_file_name_symp) {
    bool check_i = false;
    bool check_s = false;

    for (int i = 0; i < arg; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'm': {
                    if (check_i == false) {

                        cout << "Nazwa Pliku MED: " << argv[i + 1] << endl;
                        input_file_name_med = argv[i + 1];
                        check_i = true;
                    }
                    break;
                }

                case 's': {
                    if (check_s == false) {
                        cout << "Nazwa Pliku SYMP: " << argv[i + 1] << endl;
                        input_file_name_symp = argv[i + 1];
                        check_s = true;
                    }

                    break;
                }
                default:
                    cout << "BŁĄD ODCZYTU" << endl;
                    return false;
                    break;
            }
            i++;
        }

    }

    return   check_i && check_s;
}

/// Metoda odpowiedzialna za
///
/// @param  line - linia tekstu
/// @param  delimiter - znak rozdzielający
/// @returns  (count + 1)
int get_elements_count(string line, char delimiter) {
    int count = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == delimiter)
        {
            count++;
        }
    }
    return count + 1;
}

/// Metoda odpowiedzialna za tworzenie obiektu typu symptom na podstawie otrzymanej linii tekstu
///
/// @param  line - zmienna typu string, w której podajemy linię tekstu
/// @returns  symptom - zwraca obiekt klasy symptom
symptom create_symptom_from_line(string line) {
    string id = get_element(line, 0, '\t');
    string name = get_element(line, 1, '\t');
    symptom symptom(stoi(id), name);
    return symptom;
}

/// Metoda odpowiedzialna za
///
/// @param  file_name - zmienna typu string, w której podajemy nazwę pliku tekstowego
/// @returns  lista - zwraca listę typu linked_list<symptom>, w któej znajdują się symptomy
linked_list<symptom> get_symptoms_from_file(string file_name) {
    linked_list<symptom> list;
    ifstream stream(file_name);
    string line;

    if (!stream.good()) {
        std::cout << "PLIK NIE ZOSTAL OTWARTY POPRAWNIE";
        exit(0);
    }

    while (getline(stream, line)) {
        try {
            list.add(create_symptom_from_line(line));
        }
        catch(invalid_argument){cout<<"NIE UDAŁO SIE WCZYTAC SYMPTOMU";}
    }
    return list;
}

/// Metoda odpowiedzialna za
///
/// @param  symptom_file_name - zmienna typu string, w której podajemy nazwę pliku tekstowego dla listy symptomów
/// @param medicine_file_name - zmienna typu string, w której podajemy nazwę pliku tekstowego dla listy leków
/// @returns  medicines - zwraca listę typu linked_list<medicine>, w któej znajdują się leki
linked_list<medicine> get_medicines_with_symptoms_from_files(string &symptom_file_name, string &medicine_file_name) {
    linked_list<symptom> symptoms = get_symptoms_from_file(symptom_file_name);
    linked_list<medicine> medicines;
    ifstream stream(medicine_file_name);
    string line;

    if (!stream.good()) {
        cout << "PLIK NIE ZOSTAL OTWARTY POPRAWNIE";
        exit(0);
    }

    while (getline(stream, line)) {
        linked_list<int> symptom_ids;
        int id;
        int min_age;
        int max_age;
        string name;
        try {
            id = stoi(get_element(line, 0, '\t'));
            name = get_element(line, 1, '\t');
            min_age = stoi(get_element(line, 2, '\t'));
            max_age = stoi(get_element(line, 3, '\t'));
            string symptom_ids_line = get_element(line, 4, '\t');
            for (int i = 0; i < get_elements_count(symptom_ids_line, ','); i++) {
                int id = stoi(get_element(symptom_ids_line, i, ','));
                symptom_ids.add(id);
            }
        }

        catch(invalid_argument){cout<<"NIE UDALO SIE WCZYTAC LEKU"; continue;}
        linked_list<symptom> medicine_symptoms;

        for (int i = 0; i < symptoms.count(); i++)
        {
            for (int j = 0; j < symptom_ids.count(); j++)
            {
                symptom temp_symptom = symptoms.get(i);
                if (temp_symptom.get_id() == symptom_ids.get(j)) {
                    medicine_symptoms.add(temp_symptom);
                }
            }
        }
        medicine medicine(id, name, min_age, max_age, medicine_symptoms);
        medicines.add(medicine);
    }
    return medicines;
}
