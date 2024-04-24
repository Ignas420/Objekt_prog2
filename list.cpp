#include "mokinys1.h"
#include "funkcijos1.h"

int main() {
    try {
        int n, m;
        list<int> IrasuSk = {1000, 10000, 100000, 1000000, 10000000};
        list<Mokinys> A;
        list<Mokinys> Mokslinciai;
        list<Mokinys> Nuskriaustieji;
        char input, input2, input3, input4;
        Mokinys temp1;

        cout << "Ar norite istestuoti konstruktorius ir assignment'us?(jei taip, irasykite 't'): " << endl;
        cin >> input4;
        if (input4 == 't')
        {
            int num;
            cout << "Ka norite testuoti?" << endl;
            cout << "testConstructor - 1" << endl;
            cout << "testCopyConstructor - 2" << endl;
            cout << "testMoveConstructor - 3" << endl;
            cout << "testCopyAssignment - 4" << endl;
            cout << "testMoveAssignment - 5" << endl;
            cin >> num;
            if (cin.fail())
                throw runtime_error("Netinkama ivestis!");
            switch (num)
            {
            case 1:
                testConstructor();
                break;
            case 2:
                testCopyConstructor();
                break;
            case 3:
                testMoveConstructor();
                break;
            case 4:
                testCopyAssignment();
                break;
            case 5:
                testMoveAssignment();
                break;
            }
        }
        else
            throw runtime_error("Netinkama ivestis!");

        if (input == 'i') {
            cout << "Norite ivesti ranka ar generuoti skaicius?(i/g) " << endl;
            cin >> input2;

            if (input2 == 'i') {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;

                if (cin.fail()) {
                    throw runtime_error("Kiekis turi buti skaicius!");
                }

                cout << "Iveskite vardus ir pavardes: " << endl;

                for (int i = 0; i < m; ++i) {
                    Mokinys temp;
                    string vardas, pavarde;
                    cin >> vardas >> pavarde;
                    temp.setVardas(vardas);
                    temp.setPavarde(pavarde);

                    if (!Patikrinimas(vardas) || !Patikrinimas(pavarde)) {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                    }

                    A.push_back(temp);
                }

                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;

                for (auto& it : A) {
                    cout << "Irasykite namu darbu pazymius: " << endl;

                    for (int j = 0; j < n; ++j) {
                        double pazymys = 0.0;
                        cin >> pazymys;

                        it.addND(pazymys);

                        if (cin.fail() || pazymys < 1 || pazymys > 10) {
                            throw runtime_error("Namu darbai turi buti skaicius nuo 1 iki 10!");
                        }
                    }

                    cout << "Irasykite egzamino rezultata: " << endl;
                    int egzaminas;
                    cin >> egzaminas;
                    it.setEgzaminas(egzaminas);

                    if (cin.fail() || egzaminas < 1 || egzaminas > 10) {
                        throw runtime_error("Egzamino rezultatas turi buti skaicius nuo 1 iki 10!");
                    }

                    temp1.Vidurkis(A);

                    list<int> temp = it.getND();
                    temp.push_back(it.getEgzaminas());
                    temp.sort();

                    double median = *next(temp.begin(), temp.size() / 2);

                    if (temp.size() % 2 == 0) {
                        median = (*next(temp.begin(), temp.size() / 2 - 1) + *next(temp.begin(), temp.size() / 2)) / 2.0;
                    }

                    it.setMED(median);
                }
                temp1.Isvedimas(A, A.size(), CRfv);
            } else if (input2 == 'g') {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;
                if (cin.fail()) {
                    throw runtime_error("Kiekis turi buti skaicius!");
                }

                cout << "Iveskite vardus ir pavardes: " << endl;
                int kint = m;
                Mokinys temp;
                while (m != 0) {
                    string vardas, pavarde;
                    cin >> vardas >> pavarde;
                    temp1.setVardas(vardas);
                    temp1.setPavarde(pavarde);
                    if (!Patikrinimas(vardas) || !Patikrinimas(pavarde)) {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                    }
                    A.push_back(temp);
                    m--;
                }

                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;
                kint = n;
                cout << "Generuojami pazymiai..." << endl;

                for (auto& student : A) {
                    for (int j = 0; j < n; j++) {
                        int pazymys = (rand() % 10) + 1;
                        student.getND().push_back(pazymys);
                        if (cin.fail()) {
                            throw runtime_error("Namu darbai turi buti skaicius!");
                        }
                        if (pazymys < 1 || pazymys > 10) {
                            throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        }
                    }

                    int egzaminas = (rand() % 10) + 1;
                    student.setEgzaminas(egzaminas);
                    if (cin.fail()) {
                        throw runtime_error("Pazymys turi buti skaicius!");
                    }
                    if (egzaminas < 1 || egzaminas > 10) {
                        throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                    }
                    temp1.Vidurkis(A);
                    student.getND().sort();
                    list<int> temp = student.getND();
                    temp.push_back(student.getEgzaminas());
                    temp.sort();
                    double median = 0.0;
                    auto it = next(temp.begin(), temp.size() / 2);
                    if (temp.size() % 2 == 0) {
                        auto it2 = prev(it);
                        median = (*it + *it2) / 2.0;
                    } else {
                        median = *it;
                    }
                    student.setMED(median);
                }
                temp1.Isvedimas(A, A.size(), CRfv);
            }
        } else if (input == 's') {
            string failas;
            int temp;

            cout << "Iveskite 't'(taip) jei norite generuoti failus: " << endl;
            cin >> input3;

            if (input3 == 't') {
                GeneruotiFailus(Nuskriaustieji, Mokslinciai, IrasuSk, A);
            }
                int kint5;
                string filename;
                char kint6, kint7;

                cout << "Norite skaityti naujus ar senus failus?(n/s): " << endl;
                cin >> kint6;
                if(kint6 != 'n' && kint6 != 's')
                    throw runtime_error("Netinkama ivestis!");

                cout << "Iveskite failu skaiciu: "<<endl;
                cin >> kint5;
                if(cin.fail())
                    throw runtime_error("Netinkama ivestis!");
                
                cout << "Kuria strategija norite rusiuoti?(1/2/3): " <<endl;
                cin >> kint7;
                if(kint7 != '1' && kint7 != '2' && kint7 != '3')
                    throw runtime_error("Netinkama ivestis!");

                for (int i = 0; i < kint5; ++i) {
                    if(kint6 == 'n')
                        filename = "new_file" + to_string(i) + ".txt";
                    else
                        filename = "file" + to_string(i) + ".txt";
                    temp1.Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i, kint7);
                }
            

            temp1.Vidurkis(A);
        } else {
            throw runtime_error("Netinkama ivestis!");
        }

        return 0;
    } catch (exception &e) {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }
}
