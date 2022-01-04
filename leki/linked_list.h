//
// Created by Agnieszka on 04.01.2022.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#ifndef MAIN_CPP_LINKED_LIST_H
#define MAIN_CPP_LINKED_LIST_H
/// Szablon klasy - lista jednokierunkowa
template<class T>
class linked_list {

    /// Struktura, która ilustuje pojedyńczy element listy
    struct Node
    {
        T data; /*!< Dane, które będzie przechowywał dany element listy typu "T" */
        shared_ptr<Node> next; /*!< Inteligentny wskaźnik na kolejny element */
    };

    shared_ptr<Node> head; /*!< Inteligentny wskaźnik na pierwszy element listy, czyli "głowę" */
    shared_ptr<Node> tail;  /*!< Inteligentny wskaźnik na ostatni element listy, czyli "ogon" */

public:
    ~linked_list()= default;

    linked_list() {
        head = NULL;
        tail = NULL;
    }

    linked_list(const linked_list& linked_list) {
        head = linked_list.head;
        tail = linked_list.tail;
    }

    linked_list& operator=(const linked_list& linked_list) {
        head = linked_list.head;
        tail = linked_list.tail;
        return *this;
    }

    void save_to_bin_file(const string& file_name);

    void read_bin_file (const string& file_name);


    /// Metoda odpowiedzialna za dodawanie elementu do listy
    ///
    /// Metoda dodaje element na koniec listy
    /// @param element - zmienna typu T, którą dodajemy do listy
    void add(T element);

    /// Metoda odpowiedzialna za zwracanie elementu z listy
    ///
    /// Metoda zwraca element o zadanym indeksie
    /// @param index - zmienna typu int, poprzez którą podajemy który element z listy chcemy uzyskać
    /// @returns  current->data - zwraca dane zawarte pod danym indeksem
    T get(int index);

    /// Metoda odpowiedzialna za usuwanie zadanego elementu z listy
    ///
    /// Metoda usuwa element o zadanym indeksie z listy
    /// @param index - zmienna typu int, przez którą podajemy index z pod którego chcemy usunąć element
    void remove(int index);

    /// Metoda odpowiedzialna za sortowanie rosnąco elementów listy (bubble sort)
    void sort_asc();

    /// Metoda odpowiedzialna za sortowanie malejąco elementów listy (bubble sort)
    void sort_desc();

    /// Metoda odpowiedzialna za zwracanie liczby elementów na liście
    ///
    /// @returns count - zwraca zmienną typu int, w któej przechowywana jest liczba elementó listy
    int count();
};
#endif //MAIN_CPP_LINKED_LIST_H
