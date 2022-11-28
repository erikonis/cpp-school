#include <iostream>
#include <fstream>

using namespace std;

const char uzd[] = "UZD1.txt";
const char uzdrez[] = "UZD1rez.txt";



struct zmones {
    string vp;  ///vardas ir pavarde
    int p;      /// paru skaicius
    double k;   ///paros kaina
    int d1;     /// metai
    int d2;     /// menesiai
    int d3;     /// dienos
    double ksuma;
    string V;
};

struct data {
    int metai, men, diena;
};


int main()
{
    ifstream fr(uzd);
    ofstream fw(uzdrez);

    zmones A[20];
    data B[20];
    char x[20];             /// charas (kaip int), kuris gali tureti 20 simboliu.
    int n;                  /// gyventoju skaicius
    double suma = 0;
    fr >> n;   ///debug status successful

        fr.ignore();

        for (int i = 0; i < n; i++) {
            fr.get(x, 20);      /// is failo readingo gaunam pirmus 20 simboliu ir priskiriam juos x (charui, kuris gali turet 20 simboliu)
            A[i].vp = x;    /// prilyginu varda pavarde jau turimiem simboliam (20)

        fr >> A[i].d1 >> A[i].d2 >> A[i].d3 >> A[i].p >>A[i].k;
        fr.ignore();        /// debug successful

        }


        for (int i=0; i < n; i++) {

            A[i].ksuma = A[i].k * A[i].p; ///Skaiciuojam kaina uz nakvynes kiekvienam klientui

            B[i].metai = A[i].d1;
            B[i].men = A[i].d2;
            B[i].diena = A[i].d3;
            suma += A[i].ksuma;

            for (int j=0; j < A[i].p; j++) {

                if (B[i].diena <= 30) {
                    B[i].diena ++;
                }
                else if (B[i].diena > 30) {
                    B[i].diena -= 30;
                    B[i].men ++;
                }
                if (B[i].men > 12) {
                    B[i].men -= 12;
                    B[i].metai ++;
                }
            } ///debug successful
                    }


                    fw << "Pavarde, vardas     Atvyko      Isvyko       Sumokejo" << endl;
            fw << "-----------------------------------------------------" << endl;
                for (int i=0; i<n; i++) {
                    fw << A[i].vp << A[i].d1 << " " << A[i].d2 << " " << A[i].d3 << "  "
               << B[i].metai << " " << B[i].men << " " << B[i].diena << "  " << A[i].ksuma << endl;
                }
                fw << "-----------------------------------------------------" << endl;
                fw << "Viesbucio pajamos: " << suma;

    return 0;
}
