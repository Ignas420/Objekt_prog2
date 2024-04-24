#include "mokinys2.h"
#include "funkcijos2.h"

auto start1 = std::chrono::high_resolution_clock::now();

int main()
{
    try
    {
        int n, m, kint;
        deque<int> IrasuSk = {1000, 10000, 100000, 1000000, 10000000};
        deque<Mokinys> A;
        deque<Mokinys> Mokslinciai;
        deque<Mokinys> Nuskriaustieji;
        string eil;
        char input, input2, input3, input4;

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
        
        cout << "Norite ivesti ar skaityti is failo?(i/s) " << endl;
        cin >> input;
        if (input == 'i')
        {
            cout << "Norite ivesti ranka ar generuoti skaicius?(i/g) " << endl;
            cin >> input2;
            if (input2 == 'i')
            {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;
                if (cin.fail())
                {
                    throw runtime_error("Kiekis turi buti skaicius!");
                    return 1;
                }
                cout << "Iveskite vardus ir pavardes: " << endl;
                kint = m;
                Mokinys temp;
                while (m != 0)
                {
                    string vardas, pavarde;
                    cin >> vardas >> pavarde;
                    temp.setVardas(vardas);
                    temp.setPavarde(pavarde);
                    if (!Patikrinimas(vardas) || !Patikrinimas(pavarde))
                    {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                        return 1;
                    }
                    A.push_back(temp);
                    m--;
                }
                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;
                kint = n;

                for (int i = 0; i < A.size(); i++)
                {
                    cout << "Irasykite namu darbu pazymius: " << endl;
                    for (int j = 0; j < n; j++)
                    {
                        int pazymys;
                        cin >> pazymys;
                        A[i].addND(pazymys);
                        if (cin.fail())
                        {
                            throw runtime_error("Namu darbai turi buti skaicius!");
                            return 1;
                        }
                        if (pazymys < 1 || pazymys > 10)
                        {
                            throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                            return 1;
                        }
                    }
                    cout << "Irasykite egzamino rezultata: " << endl;
                    int egzaminas;
                    cin >> egzaminas;
                    A[i].setEgzaminas(egzaminas);
                    if (cin.fail())
                    {
                        throw runtime_error("Pazymys turi buti skaicius!");
                        return 1;
                    }
                    if (egzaminas < 1 || egzaminas > 10)
                    {
                        throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        return 1;
                    }
                    temp.Vidurkis(A);

                    sort(A[i].getND().begin(), A[i].getND().end());

                    deque<int> temp = A[i].getND();
                    temp.push_back(A[i].getEgzaminas());
                    sort(temp.begin(), temp.end());
                    double median = temp[temp.size() / 2];
                    if (temp.size() % 2 == 0)
                        median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
                    A[i].setMED(median);
                }
            }
            else if (input2 == 'g')
            {
                cout << "Irasykite kiek yra mokiniu: ";
                cin >> m;
                if (cin.fail())
                {
                    throw runtime_error("Kiekis turi buti skaicius!");
                    return 1;
                }
                cout << "Iveskite vardus ir pavardes: " << endl;
                kint = m;
                Mokinys temp;
                while (m != 0)
                {
                    string vardas, pavarde;
                    cin >> vardas >> pavarde;
                    temp.setVardas(vardas);
                    temp.setPavarde(pavarde);
                    if (!Patikrinimas(vardas) || !Patikrinimas(pavarde))
                    {
                        throw runtime_error("Ivestas netinkamas vardas arba pavarde!");
                        return 1;
                    }
                    A.push_back(temp);
                    m--;
                }
                cout << "Irasykite namu darbu kieki: " << endl;
                cin >> n;
                kint = n;
                cout << "Generuojami pazymiai..." << endl;
                for (int i = 0; i < A.size(); i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        int pazymys;
                        pazymys = (rand() % 10) + 1;
                        A[i].getND().push_back(pazymys);
                        if (cin.fail())
                        {
                            throw runtime_error("Namu darbai turi buti skaicius!");
                            return 1;
                        }
                        if (pazymys < 1 || pazymys > 10)
                        {
                            throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                            return 1;
                        }
                    }
                    int egzaminas = (rand() % 10) + 1;
                    A[i].setEgzaminas(egzaminas);
                    if (cin.fail())
                    {
                        throw runtime_error("Pazymys turi buti skaicius!");
                        return 1;
                    }
                    if (egzaminas < 1 || egzaminas > 10)
                    {
                        throw runtime_error("Pazymys turi buti desimtbaleje sistemoje!");
                        return 1;
                    }
                    temp.Vidurkis(A);

                    sort(A[i].getND().begin(), A[i].getND().end());

                    deque<int> temp = A[i].getND();
                    temp.push_back(A[i].getEgzaminas());
                    sort(temp.begin(), temp.end());
                    double median = temp[temp.size() / 2];
                    if (temp.size() % 2 == 0)
                        median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
                    A[i].setMED(median);
                }
            }
            else
            {
                throw runtime_error("Netinkama ivestis!");
                return 1;
            }
        }
        // SKAITYMAS
        else if (input == 's')
        {
            Mokinys temp;
            auto start1 = std::chrono::high_resolution_clock::now();
            auto st1 = start1;
            string failas;

            cout << "Iveskite 't'(taip) jei norite generuoti failus: " << endl;
            cin >> input3;
            if (input3 == 't')
                GeneruotiFailus(Nuskriaustieji, Mokslinciai, IrasuSk, A);
                
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
                
                for(int i=0; i<kint5; i++){
                    if(kint6 == 'n')
                        filename = "new_file" + to_string(i) + ".txt";
                    else
                        filename = "file" + to_string(i) + ".txt";
                    temp.Skaitymas(Nuskriaustieji, Mokslinciai, IrasuSk, filename, A, i, kint7);
                }
            temp.Vidurkis(A);
        }
        else
        {
            throw runtime_error("Netinkama ivestis!");
            return 1;
        }
        return 0;
    }
    catch (exception &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 0;
    }
}
