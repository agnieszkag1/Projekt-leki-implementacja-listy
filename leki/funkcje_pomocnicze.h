//
// Created by Agnieszka on 04.01.2022.
//
#ifndef MAIN_CPP_FUNKCJE_POMOCNICZE_H
#define MAIN_CPP_FUNKCJE_POMOCNICZE_H
using namespace std;
#include <iostream>
#include <string>
#include "linked_list.cpp"
#include "medicine.h"
#include "klasa_testowa.h"
#include "konsola.h"
#include "symptom.h"



string get_element(string line, int position, char delimiter);

bool read_from_console(int arg, char *argv[], string &input_file_name_med, string &input_file_name_symp);

int get_elements_count(string line, char delimiter);

symptom create_symptom_from_line(string line);

linked_list<symptom> get_symptoms_from_file(string file_name);

linked_list<medicine> get_medicines_with_symptoms_from_files(string &symptom_file_name, string &medicine_file_name);
#endif //MAIN_CPP_FUNKCJE_POMOCNICZE_H
