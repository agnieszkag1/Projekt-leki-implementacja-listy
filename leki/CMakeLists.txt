cmake_minimum_required(VERSION 3.20)
project(leki)

set(CMAKE_CXX_STANDARD 23)

add_executable(leki main.cpp funkcje_pomocnicze.cpp funkcje_pomocnicze.h medicine.cpp medicine.h symptom.cpp symptom.h linked_list.cpp linked_list.h konsola.cpp konsola.h klasa_testowa.cpp klasa_testowa.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Medicines.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Symptoms.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/wejscie.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})