//
// Created by Agnieszka on 04.01.2022.
//

#include "konsola.h"


void konsola::start(string input_med, string input_symp){
    linked_list<medicine> medicines = get_medicines_with_symptoms_from_files(input_symp, input_med);
    int user_age = 0;
    string user_symptoms;
    cout<<endl<<endl;
    cout << "Aby wyszukac lek najpierw wpisz swoj wiek (bez spacji, tylko cyfry np. 20), "
            "następnie wymien swoje objawy (wymieniaj je przedzielajac srednikiem, kazdy objaw rozpczynaj od wielkiej litery, "
            "nie uzywaj polskich znakow, dwuczlonowe wyrazy zapisuj za pomoca podkreslenia np. Katar;Kaszel;Bol_glowy"<<endl<<endl;
    cout << "Podaj swoj wiek: ";
    cin >> user_age;
    cout << endl;

    cout << "Podaj swoje objawy: ";
    cin >> user_symptoms;
    cout << endl;

    linked_list<string> user_symptom_list;

    for (int i = 0; i < get_elements_count(user_symptoms, ';'); i++)
    {
        user_symptom_list.add(get_element(user_symptoms, i, ';'));
    }

    linked_list<medicine> found_medicines;

    for (int i = 0; i < user_symptom_list.count(); i++)
    {
        string temp_user_symptom = user_symptom_list.get(i);
        for (int j = 0; j < medicines.count(); j++)
        {
            medicine temp_medicine = medicines.get(j);
            for (int k = 0; k < temp_medicine.get_symptoms().count(); k++)
            {
                symptom temp_medicine_symptom = temp_medicine.get_symptoms().get(k);
                if (temp_user_symptom == temp_medicine_symptom.get_name() &&
                    temp_medicine.get_age_min() <= user_age &&
                    temp_medicine.get_max_age() >= user_age) {

                    bool has_duplicate = false;
                    for (int l = 0; l < found_medicines.count(); l++)
                    {
                        medicine possible_duplicate = found_medicines.get(l);
                        if (possible_duplicate.get_id() == temp_medicine.get_id()) {
                            has_duplicate = true;
                            break;
                        }
                    }

                    if (!has_duplicate) {
                        found_medicines.add(temp_medicine);
                    }

                    break;
                }
            }
        }
    }

    cout << "Found medicines" << endl;
    cout<<"-----------------------------------"<<endl;

    for (int i = 0; i < found_medicines.count(); i++)
    {
        cout << found_medicines.get(i) <<endl;
        cout<<"Symptoms match: "<<endl;
        for (int j=0; j<found_medicines.get(i).get_symptoms().count(); j++){

            for(int k=0; k<user_symptom_list.count();k++){
                if(found_medicines.get(i).get_symptoms().get(j).get_name()==user_symptom_list.get(k)){
                    cout<<" "<<user_symptom_list.get(k)<<endl;
                }
            }
        }

        cout<<"-----------------------------------"<<endl;
    }

}