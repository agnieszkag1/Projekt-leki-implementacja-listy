//
// Created by Agnieszka on 04.01.2022.
//

#include "linked_list.h"

#ifndef MAIN_CPP_LINKED_LIST_CPP
#define MAIN_CPP_LINKED_LIST_CPP
template<class T>
void linked_list<T>::save_to_bin_file(const string& file_name){
    ofstream stream;
    shared_ptr<Node> tmp= head;
    stream.open(file_name, ios::binary);

    for(int i=0;i<count();i++){
        stream << tmp->data<<endl;
        tmp=tmp->next;
    }
    stream.close();
}

template<class T>
void linked_list<T>::read_bin_file (const string& file_name){

    ifstream stream;
    stream.open(file_name, ios::binary);
    T temp_object;

    while(stream>>temp_object)
    {
        (*this).add(temp_object);
    }
    stream.close();
}

/// Metoda odpowiedzialna za dodawanie elementu do listy
///
/// Metoda dodaje element na koniec listy
/// @param element - zmienna typu T, którą dodajemy do listy
template<class T>
void linked_list<T>::add(T element) {
    std::shared_ptr<Node> newNode(new Node);
    newNode->data = element;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        tail->next = newNode;
        tail = tail->next;
    }
}

/// Metoda odpowiedzialna za zwracanie elementu z listy
///
/// Metoda zwraca element o zadanym indeksie
/// @param index - zmienna typu int, poprzez którą podajemy który element z listy chcemy uzyskać
/// @returns  current->data - zwraca dane zawarte pod danym indeksem
template<class T>
T linked_list<T>::get(int index) {
    if (head == NULL) {
        throw std::exception("List is empty");
    }
    std::shared_ptr<Node> current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return (current->data);
        }
        count++;
        current = current->next;
    }
    throw exception("Index out of bounds");
}

/// Metoda odpowiedzialna za usuwanie zadanego elementu z listy
///
/// Metoda usuwa element o zadanym indeksie z listy
/// @param index - zmienna typu int, przez którą podajemy index z pod którego chcemy usunąć element
template<class T>
void linked_list<T>::remove(int index) {
    if (head == NULL) {
        throw std::exception("List is empty");
    }
    std::shared_ptr<Node> current = head;
    std::shared_ptr<Node> previous = NULL;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            if (previous != NULL) {
                previous->next = current->next;
            }
            else {
                head = current->next;
            }
            return;
        }
        count++;
        previous = current;
        current = current->next;
    }
    throw std::exception("Index out of bounds");
}

/// Metoda odpowiedzialna za sortowanie rosnąco elementów listy (bubble sort)
template<class T>
void linked_list<T>::sort_asc() {
    if (head == NULL || count() == 1) {
        return;
    }

    for (int i = 0; i < count(); i++) {
        shared_ptr<Node> currentA = head;
        shared_ptr<Node> currentB = currentA->next;
        for (int j = 0; j < count() - 1; j++) {
            if (currentA->data > currentB->data) {
                T temp = currentA->data;
                currentA->data = currentB->data;
                currentB->data = temp;

            }
            currentA = currentB;
            currentB = currentA->next;
        }
    }
}

/// Metoda odpowiedzialna za sortowanie malejąco elementów listy (bubble sort)
template<class T>
void linked_list<T>::sort_desc() {
    if (head == NULL || count() == 1) {
        return;
    }

    for (int i = 0; i < count(); i++) {
        std::shared_ptr<Node> currentA = head;
        std::shared_ptr<Node> currentB = currentA->next;
        for (int j = 0; j < count() - 1; j++) {
            if (currentA->data < currentB->data) {
                T temp = currentA->data;
                currentA->data = currentB->data;
                currentB->data = temp;

            }
            currentA = currentB;
            currentB = currentA->next;
        }
    }
}

/// Metoda odpowiedzialna za zwracanie liczby elementów na liście
///
/// @returns count - zwraca zmienną typu int, w któej przechowywana jest liczba elementó listy
template<class T>
int linked_list<T>::count() {
    shared_ptr<Node> current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

#endif
