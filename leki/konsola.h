//
// Created by Agnieszka on 04.01.2022.
//
#include <iostream>
#include <string>
#include "funkcje_pomocnicze.h"
#include "klasa_testowa.h"
#include "symptom.h"
#include "medicine.h"
#ifndef MAIN_CPP_KONSOLA_H
#define MAIN_CPP_KONSOLA_H
class konsola{
public:

/// Metoda statyczna wywołująca kluczowe funkcje programu
    static void start(string input_med, string input_symp);
};
#endif //MAIN_CPP_KONSOLA_H
