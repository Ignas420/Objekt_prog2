#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
const int CMax = 10;
double VID[CMax] ={0};

struct Mokinys{
  string vardas;
  string pavarde;
  int ND[CMax];
  int egzaminas;
};

void Vidurkis(Mokinys A[], int n, int m);

int main(){
    int n, m;
    Mokinys A[CMax], B[CMax];
    cout << "Mokiniu skaicius: ";
    cin >> m;
    cout<<endl;
    cout << "Namu darbu skaicius: ";
    cin >> n;
    cout << endl;
    cout << "Iveskite varda, pavarde, pazymius uz namu darbus bei egzamino rezultata: ";
    for(int i=0; i<m; i++){
        cin >> A[i].vardas >> A[i].pavarde;
        for(int j=0; j<n; j++){
            cin >> A[i].ND[j];
            B[i].ND[j]=A[i].ND[j];
        }
        cin >> A[i].egzaminas;
        B[i].ND[n] = A[i].egzaminas; 
    }
    Vidurkis(A, n, m);
    cout<<endl;
    cout << "Pavardė" << setfill(' ') << setw(10) << "Vardas" << setfill(' ') << setw(35) << "Galutinis (Vid.) / Galutinis(Med.)"<<endl;
    cout << "------------------------------------------"<<endl;

    double MED[CMax];

    for(int i=0; i<m; i++){
        sort(B[i].ND, B[i].ND + (n+1));
        for(int j= 0; j<=n; j++)
            cout << B[i].ND[j] << " ";
        cout<<endl;
        if((n+1)%2==0)
            MED[i] = (double) (B[i].ND[(n+1)/2 - 1] + B[i].ND[(n+1)/2]) / 2.0;
        else
            MED[i] = B[i].ND[(n+1)/2];
    }
    
    for(int i = 0; i<m; i++){
        cout << A[i].vardas << setw(10) << A[i].pavarde << setw(10) << fixed << setprecision(2) << VID[i] << " " << MED[i] << endl;
    }
    return 0;
}
void Vidurkis(Mokinys A[], int n, int m){
    double suma = 0;
    for(int i=0; i<m; i++){
        for(int j = 0; j<n; j++)
            suma += A[i].ND[j];
        suma += A[i].egzaminas;
        VID[i] = suma / (n+1);
        suma = 0;
    }
}