#include <iostream>
#include <string>
#include "linked_list.cpp"
#include "klasa_testowa.h"
#include "konsola.h"
#include "symptom.h"


using namespace std;


int main(int arg, char *argv[]) {

  string  input_med="Medicines.txt" , imput_symp="Symptoms.txt";

    cout << "Witaj w programie do wyszukiwania lekow!"<<endl<<endl;

    read_from_console(arg, argv, input_med, imput_symp);
    system("cls");

    string cont ="TAK";
    while (cont=="TAK"){
        konsola::start(input_med,imput_symp);
        cout<<endl<<"Czy chcesz jeszcze raz podac objawy i wiek? (Jesli tak wpisz - TAK, w przeciwnym wypadku wpisz cokolwiek innego)"<<endl;
        cin>> cont;
        system("cls");
    };
system("cls");

 cout<<endl<<"------------------ DO POKAZANIA FUNKCJONALNOSCI DLA INT ------------------"<<endl;
    cout<<"--------------------DODAWANIE ELEMENTOW ----------------------"<<endl;
    linked_list<int> lista_test;
    lista_test.add(2);
    lista_test.add(6);
    lista_test.add(8);
    lista_test.add(10);
    lista_test.add(56);
    lista_test.add(109);
    for(int i=0; i<lista_test.count();i++){
        cout<<lista_test.get(i);
        cout<<endl;
    }
    lista_test.remove(5);
    cout<<"------------------PO USUNIECIU ELEMENTU POD INDEKSEM 5------------------------"<<endl;
    for(int i=0; i<lista_test.count();i++){
        cout<<lista_test.get(i);
        cout<<endl;
    }

    lista_test.sort_asc();
    cout<<endl<<"------------------POSORTOWANE ROSNACO------------------------"<<endl;
    for(int i=0; i<lista_test.count();i++){
        cout<<lista_test.get(i);
        cout<<endl;
    }

    lista_test.sort_desc();
    cout<<endl<<"-------------------POSORTOWANE MALEJACO-----------------------"<<endl;
    for(int i=0; i<lista_test.count();i++){
        cout<<lista_test.get(i);
        cout<<endl;
    }
    cout<<endl<<"-------------------ZAPIS DO PLIKU BINARNEGO-----------------------"<<endl;
    lista_test.save_to_bin_file("a.bin");
    linked_list<int> lista_test2;

    cout<<endl<<"----------------ODCZYT Z PLIKU BINARNEGO DO NOWEJ LISTY--------------------------"<<endl;
    lista_test2.read_bin_file("a.bin");
    for(int i=0; i<lista_test2.count();i++){
        cout<<lista_test2.get(i);
        cout<<endl;
    }
    cout<<endl<<"------------------ DO POKAZANIA FUNKCJONALNOSCI DLA KLASY TESTOWEJ  ------------------"<<endl;
    cout<<endl<<"---------------------DODAWANIE ELEMENTOW---------------------"<<endl;
    test TEST;
    linked_list<test> lista_test3;
    lista_test3.add(TEST);
    lista_test3.add(TEST);
    lista_test3.add(TEST);
    lista_test3.add(test(9,"Kwiatek"));
    lista_test3.add(test(0,"Coś"));
    for(int i=0; i<lista_test3.count();i++){
        cout<<lista_test3.get(i).to_string();
        cout<<endl;
    }
    cout<<endl<<"------------------SORTOWANIE ROSNACO PO A------------------------"<<endl;
    lista_test3.sort_asc();
    for(int i=0; i<lista_test3.count();i++){
        cout<<lista_test3.get(i).to_string();
        cout<<endl;
    }
    cout<<endl<<"---------------ZAPIS DO PLIKU BINARNEGO I ODCZYT DO NOWEJ LISTY---------------------------"<<endl;
    lista_test3.save_to_bin_file("b.bin");
    linked_list<test> lista_test4;
    lista_test4.read_bin_file("b.bin");
    for(int i=0; i<lista_test4.count();i++){
       cout<<lista_test4.get(i).to_string();
        cout<<endl;
    }
    system("pause");
    return 0;
}
