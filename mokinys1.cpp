#include "mokinys1.h"
#include "funkcijos1.h"

bool Patikrinimas(string kint)
{
    const int ilgis = kint.length();
    char *temp_array = new char[ilgis + 1];
    strcpy(temp_array, kint.c_str());
    for (int i = 0; i < ilgis; i++)
    {
        if (!isalpha(temp_array[i]))
            return false;
    }
    delete[] temp_array;
    return true;
}

void Mokinys :: Vidurkis(list<Mokinys> &A)
{
    for (auto &mok : A)
    {
        double suma = 0;
        for (int pazymys : mok.ND)
        {
            suma += pazymys;
        }
        suma += mok.egzaminas;
        double vidurkis = suma / (mok.ND.size() + 1);
        mok.VID = vidurkis;
    }
}

bool Mokinys ::  PagalVidurki(const Mokinys &a, const Mokinys &b)
{
    return a.VID < b.VID;
}

bool Mokinys ::  PagalMediana(const Mokinys &a, const Mokinys &b)
{
    return a.MED < b.MED;
}

bool Mokinys ::  PagalVarda(const Mokinys &a, const Mokinys &b)
{
    return a.vardas < b.vardas;
}

bool Mokinys ::  PagalPavarde(const Mokinys &a, const Mokinys &b)
{
    return a.pavarde < b.pavarde;
}

double visasLaikas;

void GeneruotiFailus(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<int> &IrasuSk, list<Mokinys> &A)
{
    srand(time(NULL));
    visasLaikas = 0.0;

    int temp_index = 0;
    for (auto irasai : IrasuSk)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        cout << "~FAILAS " + to_string(temp_index) + "~" << endl;
        cout << "Generuojama..." << endl;
        string filename = "new_file" + to_string(temp_index) + ".txt";
        ofstream fr(filename);

        if (!fr)
            throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");

        int temp = rand() % 10 + 1;

        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
        for (int i = 0; i < temp; i++)
            fr << setw(10) << left << "ND";
        fr << setw(10) << left << "Egz." << endl;

        for (int j = 0; j < irasai; j++)
        {
            fr << setw(20) << left << ("Vardas" + to_string(j)) << setw(20) << left << ("Pavarde" + to_string(j));
            for (int k = 0; k < temp; k++)
                fr << setw(10) << left << rand() % 10 + 1;
            fr << setw(10) << left << rand() % 10 + 1 << endl;
        }

        fr.close();
        temp_index++;
    }
}

void Mokinys ::  Skaitymas(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<int> &IrasuSk, string failas, list<Mokinys> &A, int &temp, char strategija)
{
    visasLaikas = 0.0;
    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;

    string eil;
    ifstream fd(failas);
    if (!fd)
        throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");
    getline(fd, eil);
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    while (getline(fd, eil))
    {
        istringstream iss(eil);
        Mokinys temp;
        iss >> temp.vardas >> temp.pavarde;
        int pazymiai;
        while (iss >> pazymiai)
            temp.ND.push_back(pazymiai);

        if (!temp.ND.empty())
        {
            temp.egzaminas = temp.ND.back();
            temp.ND.pop_back();
        }

        temp.ND.sort();
        double mediana;

        if (!temp.ND.empty())
        {
            auto it = temp.ND.begin();
            advance(it, temp.ND.size() / 2);
            mediana = *it;
            if (temp.ND.size() % 2 == 0)
            {
                it--;
                mediana = (*it + mediana) / 2.0;
            }
        }
        temp.MED = mediana;
        A.push_back(temp);
    }
    fd.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Nuskaitymo laikas: " << diff.count() << "s\n";
    visasLaikas += diff.count();
    Vidurkis(A);
    if (strategija == '1')
        StudentuRusiavimas(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);
    if (strategija == '2')
        StudentuRusiavimas2(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);
    if (strategija == '3')
        StudentuRusiavimas3(Nuskriaustieji, Mokslinciai, A, IrasuSk, failas, temp);

    cout << endl;
}

void Mokinys ::  StudentuRusiavimas(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";
    int kint;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    A.sort(PagalVidurki);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas didejimo tvarka uztruko: " << diff.count() << "s\n";

    visasLaikas += diff.count();

    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;

    for (auto &mok : A)
    {
        if (mok.VID > 5.0)
            Nuskriaustieji.push_back(mok);
        else
            Mokslinciai.push_back(mok);
    }

    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
    cout << "Studentu suskirstymas uztruko: " << diff1.count() << "s\n";
    visasLaikas += diff1.count();

    cout << "Visa programa " + to_string(temp) + " uztruko: " << visasLaikas << "s\n";

    Isvedimas2(Mokslinciai, Mokslinciai.size(), filename);
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}
void Mokinys ::  StudentuRusiavimas2(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";
    int kint;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    A.sort(PagalVidurki);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas didejimo tvarka uztruko: " << diff.count() << "s\n";

    visasLaikas += diff.count();

    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;

    for (auto i = prev(A.end()); i != A.begin(); i--)
    {
        if (i->VID > 5.0)
        {
            Nuskriaustieji.push_back(*i);
            i = A.erase(i);
        }
    }
    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
    cout << "Studentu suskirstymas uztruko: " << diff1.count() << "s\n";
    visasLaikas += diff1.count();

    cout << "Visa programa " + to_string(temp) + " uztruko: " << visasLaikas << "s\n";

    Isvedimas2(A, A.size(), filename);
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}
void Mokinys ::  StudentuRusiavimas3(list<Mokinys> &Nuskriaustieji, list<Mokinys> &Mokslinciai, list<Mokinys> &A, list<int> &IrasuSk, string failas, int &temp)
{
    string filename = "nuskriaustieji" + to_string(temp) + ".txt";
    string filename1 = "mokslinciai." + to_string(temp) + ".txt";

    auto start = chrono::high_resolution_clock::now();

    A.sort(PagalVidurki);

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Studentu rusiavimas didejimo tvarka uztruko: " << diff.count() << "s\n";

    auto start1 = chrono::high_resolution_clock::now();

    auto nuskriaustieji_end = partition(A.begin(), A.end(), [](const Mokinys &mok)
                                        { return mok.VID > 5.0; });

    copy(A.begin(), nuskriaustieji_end, back_inserter(Nuskriaustieji));
    copy(nuskriaustieji_end, A.end(), back_inserter(Mokslinciai));

    chrono::duration<double> diff1 = chrono::high_resolution_clock::now() - start1;
    cout << "Studentu suskirstymas uztruko: " << diff1.count() << "s\n";

    cout << "Visa programa " + to_string(temp) + " uztruko: " << diff.count() + diff1.count() << "s\n";

    Isvedimas2(Mokslinciai, Mokslinciai.size(), filename);
    Isvedimas2(Nuskriaustieji, Nuskriaustieji.size(), filename1);
}
void Mokinys ::  Isvedimas(const list<Mokinys> &A, int MOK_kiekis, string isvedimas)
{
    char kint;
    cout << "Rezultatus matyti norite ekrane ar faile?(e/f): ";
    cin >> kint;
    if (kint == 'e')
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        cout << setfill('-') << setw(80) << " " << endl;
        cout << setfill(' ');

        for (const auto &mok : A)
        {
            cout << setw(20) << left << mok.vardas << setw(20) << left << mok.pavarde << right << fixed << setprecision(2) << mok.VID << setw(18) << right << mok.MED;
            cout << endl;
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas ekrane uztruko: " << diff.count() << "s\n";
    }
    else if (kint == 'f')
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        ofstream fr(isvedimas);
        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        fr << setfill('-') << setw(80) << " " << endl;
        fr << setfill(' ');

        for (const auto &mok : A)
        {
            fr << setw(20) << left << mok.vardas << setw(20) << left << mok.pavarde << right << fixed << setprecision(2) << mok.VID << setw(18) << right << mok.MED;
            fr << endl;
        }
        fr.close();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n";
    }
    else
        throw runtime_error("Netinkama ivestis!");
}

void Mokinys ::  Isvedimas2(const list<Mokinys> &A, int MOK_kiekis, string isvedimas)
{
    /*   auto start = std::chrono::high_resolution_clock::now();
      auto st = start; */
    ofstream fr(isvedimas);
    fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
    fr << setfill('-') << setw(80) << " " << endl;
    fr << setfill(' ');

    for (const auto &mok : A)
    {
        fr << setw(20) << left << mok.vardas << setw(20) << left << mok.pavarde << right << fixed << setprecision(2) << mok.VID << setw(18) << right << mok.MED;
        fr << endl;
    }
    fr.close();
    /*   std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
      cout << "Studentu isvedimas i failus uztruko: " << diff.count() << "s\n"; */
}

void Mokinys ::  Rikiavimas(list<Mokinys> &Mokslinciai, list<Mokinys> &Nuskriaustieji, list<int> &IrasuSk)
{
    char kint;
    cout << "Pagal ka rikiuoti: varda, pavarde, vidurki, mediana?(v, p, V, m)" << endl;
    cin >> kint;
    if (kint == 'V')
    {
        Mokslinciai.sort(PagalVidurki);
        Nuskriaustieji.sort(PagalVidurki);
    }
    else if (kint == 'm')
    {
        Mokslinciai.sort(PagalMediana);
        Nuskriaustieji.sort(PagalMediana);
    }
    else if (kint == 'v')
    {
        Mokslinciai.sort(PagalVarda);
        Nuskriaustieji.sort(PagalVarda);
    }
    else if (kint == 'p')
    {
        Mokslinciai.sort(PagalPavarde);
        Nuskriaustieji.sort(PagalPavarde);
    }
    else
        throw runtime_error("Netinkama ivestis!");
}
void testConstructor()
{
    list<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    if (mok.getVardas() == "Vardenis")
        cout << "Vardas tinkamas!" << endl;
    else
        cout << "Vardas netinkamas!" << endl;
    if (mok.getPavarde() == "Pavardenis")
        cout << "Pavarde tinkama!" << endl;
    else
        cout << "Pavarde netinkama!" << endl;
    if (mok.getND() == temp)
        cout << "Namu darbai tinkami!" << endl;
    else
        cout << "Namu darbai netinkami!" << endl;
    if (mok.getEgzaminas() == 9)
        cout << "Egzaminas tinkamas!" << endl;
    else
        cout << "Egzaminas netinkamas!" << endl;
    if (mok.getVID() == 8)
        cout << "Vidurkis tinkamas!" << endl;
    else
        cout << "Vidurkis netinkamas!" << endl;
    if (mok.getMED() == 7)
        cout << "Mediana tinkama!" << endl;
    else
        cout << "Mediana netinkama!" << endl;
}
void testCopyConstructor()
{
    list<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1 = mok;
    if (mok1.getVardas() == "Vardenis")
        cout << "Vardas tinkamas!" << endl;
    else
        cout << "Vardas netinkamas!" << endl;
    if (mok1.getPavarde() == "Pavardenis")
        cout << "Pavarde tinkama!" << endl;
    else
        cout << "Pavarde netinkama!" << endl;
    if (mok1.getND() == temp)
        cout << "Namu darbai tinkami!" << endl;
    else
        cout << "Namu darbai netinkami!" << endl;
    if (mok1.getEgzaminas() == 9)
        cout << "Egzaminas tinkamas!"<< endl;
    else
        cout << "Egzaminas netinkamas!" << endl;
    if (mok1.getVID() == 8)
        cout << "Vidurkis tinkamas!" << endl;
    else
        cout << "Vidurkis netinkamas!" << endl;
    if (mok1.getMED() == 7)
        cout << "Mediana tinkama!" << endl;
    else
        cout << "Mediana netinkama!" << endl;
}
void testMoveConstructor()
{
    list<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1 = move(mok);
    if (mok1.getVardas() == "Vardenis")
        cout << "Vardas tinkamas!" << endl;
    else
        cout << "Vardas netinkamas!" << endl;
    if (mok1.getPavarde() == "Pavardenis")
        cout << "Pavarde tinkama!" << endl;
    else
        cout << "Pavarde netinkama!" << endl;
    if (mok1.getND() == temp)
        cout << "Namu darbai tinkami!" << endl;
    else
        cout << "Namu darbai netinkami!" << endl;
    if (mok1.getEgzaminas() == 9)
        cout << "Egzaminas tinkamas!" << endl;
    else
        cout << "Egzaminas netinkamas!" << endl;
    if (mok1.getVID() == 8)
        cout << "Vidurkis tinkamas!" << endl;
    else
        cout << "Vidurkis netinkamas!" << endl;
    if (mok1.getMED() == 7)
        cout << "Mediana tinkama!" << endl;
    else
        cout << "Mediana netinkama!" << endl;
}
void testCopyAssignment()
{
    list<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1;
    mok1 = mok;
    if (mok1.getVardas() == "Vardenis")
        cout << "Vardas tinkamas!" << endl;
    else
        cout << "Vardas netinkamas!" << endl;
    if (mok1.getPavarde() == "Pavardenis")
        cout << "Pavarde tinkama!" << endl;
    else
        cout << "Pavarde netinkama!" << endl;
    if (mok1.getND() == temp)
        cout << "Namu darbai tinkami!" << endl;
    else
        cout << "Namu darbai netinkami!" << endl;
    if (mok1.getEgzaminas() == 9)
        cout << "Egzaminas tinkamas!" << endl;
    else
        cout << "Egzaminas netinkamas!" << endl;
    if (mok1.getVID() == 8)
        cout << "Vidurkis tinkamas!" << endl;
    else
        cout << "Vidurkis netinkamas!" << endl;
    if (mok1.getMED() == 7)
        cout << "Mediana tinkama!" << endl;
    else
        cout << "Mediana netinkama!" << endl;
}
void testMoveAssignment()
{
    list<int> temp{1, 2, 3, 4};
    Mokinys mok("Vardenis", "Pavardenis", temp, 9, 8, 7);
    Mokinys mok1;
    mok1 = move(mok);
    if (mok1.getVardas() == "Vardenis")
        cout << "Vardas tinkamas!" << endl;
    else
        cout << "Vardas netinkamas!" << endl;
    if (mok1.getPavarde() == "Pavardenis")
        cout << "Pavarde tinkama!" << endl;
    else
        cout << "Pavarde netinkama!" << endl;
    if (mok1.getND() == temp)
        cout << "Namu darbai tinkami!" << endl;
    else
        cout << "Namu darbai netinkami!" << endl;
    if (mok1.getEgzaminas() == 9)
        cout << "Egzaminas tinkamas!" << endl;
    else
        cout << "Egzaminas netinkamas!" << endl;
    if (mok1.getVID() == 8)
        cout << "Vidurkis tinkamas!" << endl;
    else
        cout << "Vidurkis netinkamas!" << endl;
    if (mok1.getMED() == 7)
        cout << "Mediana tinkama!" << endl;
    else
        cout << "Mediana netinkama!" << endl;
}
