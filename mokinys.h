#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <stdexcept>
#include <list>
#include <deque>
#include <cassert>
#include <utility>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv2[] = "naujas_failas.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

//const char CDfv[] = "kursiokai.txt";
const char CDfv0[] = "studentai10000.txt";
const char CDfv1[] = "studentai100000.txt";
const char CDfv2[] = "studentai1000000.txt";


class Mokinys {
private:
    string vardas;
    string pavarde;
    vector<int> ND;
    int egzaminas;
    double VID;
    double MED;

public:
    // Constructor
    Mokinys(string vard="", string pav="", vector<int> nd={}, int e = 0, double vid = 0, double med = 0)
        : vardas(vard), pavarde(pav), ND(nd), egzaminas(e), VID(vid), MED(med) {}

    //Destructor
    ~Mokinys(){}

    //Copy constructor
    Mokinys(const Mokinys &other) : vardas(other.vardas), pavarde(other.pavarde), ND(other.ND), egzaminas(other.egzaminas), VID(other.VID), MED(other.MED){}

    //Move contructor
    Mokinys(Mokinys&& other) noexcept
        : vardas(move(other.vardas)), pavarde(move(other.pavarde)),
          ND(move(other.ND)), egzaminas(exchange(other.egzaminas, 0)),
          VID(exchange(other.VID, 0)), MED(exchange(other.MED, 0)) {}

    // Copy Assignment Operator
    Mokinys& operator=(const Mokinys &other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            ND = other.ND;
            egzaminas = other.egzaminas;
            VID = other.VID;
            MED = other.MED;
        }
        return *this;
    }

    // Move Assignment Operator
    Mokinys& operator=(Mokinys&& other) noexcept {
        if (this != &other) {
            vardas = move(other.vardas);
            pavarde = move(other.pavarde);
            ND = move(other.ND);
            egzaminas = exchange(other.egzaminas, 0);
            VID = exchange(other.VID, 0);
            MED = exchange(other.MED, 0);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& fr, const Mokinys& temp1) {
        fr << "Vardas: " << temp1.vardas << endl;
        fr << "Pavarde: " << temp1.pavarde << endl;
        fr << "Namu darbai: ";
        for (int pazymys : temp1.ND) {
            fr << pazymys << " ";
        }
        cout << endl;
        fr << "Egzamino pazymys: " << temp1.egzaminas << endl;
        fr << "Median: " << temp1.MED << endl;
        fr << "Average: " << temp1.VID << endl;
        return fr;
    }

    friend istream& operator>>(istream& fd, Mokinys& temp1) {
        cout << "Iveskite varda: ";
        fd >> temp1.vardas;
        cout << "Iveskite pavarde: ";
        fd >> temp1.pavarde;
        cout << "Iveskite namu darbus: ";
        int pazymys;
        temp1.ND.clear();
        while(fd >> pazymys && pazymys != 0){
            temp1.ND.push_back(pazymys);
        }
        cout << "Enter exam score: ";
        fd >> temp1.egzaminas;
        cout << "Enter median score: ";
        fd >> temp1.MED;
        cout << "Enter average score: ";
        fd >> temp1.VID;
        return fd;
    }

    // Getter functions
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getND() const { return ND; }
    int getEgzaminas() const { return egzaminas; }
    double getVID() const { return VID; }
    double getMED() const { return MED; }

    // Setter functions
    void setVardas(const string &name) { vardas = name; }
    void setPavarde(const string &surname) { pavarde = surname; }
    void addND(int nd) { ND.push_back(nd); }
    void clearND() { ND.clear(); }
    void setEgzaminas(int exam) { egzaminas = exam; }
    void setVID(double vid) { VID = vid; }
    void setMED(double med) { MED = med; }

    // Utility functions
    void Vidurkis(vector<Mokinys> & A);
    void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
    void Isvedimas2(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
    static bool PagalVidurki(const Mokinys &a, const Mokinys &b);
    static bool PagalMediana(const Mokinys &a, const Mokinys &b);
    static bool PagalVarda(const Mokinys &a, const Mokinys &b);
    static bool PagalPavarde(const Mokinys &a, const Mokinys &b);
    void Skaitymas(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<int> &IrasuSk, string failas, vector<Mokinys> &A, int &temp, char strategija);
    void StudentuRusiavimas(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<Mokinys> &A, vector<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas2(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<Mokinys> &A, vector<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas3(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<Mokinys> &A, vector<int> &IrasuSk, string failas, int &temp);
    void Rikiavimas(vector<Mokinys>& Mokslinciai, vector<Mokinys>& Nuskriaustieji, vector<int>& IrasuSk);
};

#endif