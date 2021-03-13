#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

class Complex {
private:
    double real;
    double imaginar;
public:
    Complex();

    Complex(Complex &);

    Complex(double, double);

    ~Complex();

    void set_real(double);

    void set_imaginar(double);

    double get_real();

    double get_imaginar();

    void citire(istream &in);

    friend istream &operator>>(istream &in, Complex &z);

    void afisare(ostream &out) const;

    friend ostream &operator<<(ostream &out, const Complex &z);

    void citireFisier(ifstream &in);

    friend ifstream &operator>>(ifstream &in, Complex &z);

    double modul();

    void egal(Complex z);

    Complex &operator=(Complex &z);

    friend Complex &operator+(Complex &z1, Complex &z2);

    friend Complex &operator*(Complex &z1, Complex &z2);

    friend Complex &operator/(Complex &z1, Complex &z2);

    friend class VectorComplex;
};

Complex::Complex() {
    this->real = 0;
    this->imaginar = 0;
}

Complex::Complex(Complex &z) {
    this->imaginar = z.imaginar;
    this->real = z.real;
}

Complex::Complex(double real, double imaginar) {
    this->real = real;
    this->imaginar = imaginar;
}

Complex::~Complex() {
    this->real = 0;
    this->imaginar = 0;
}

void Complex::set_imaginar(double imaginar) {
    this->imaginar = imaginar;
}

void Complex::set_real(double real) {
    this->real = real;
}

double Complex::get_imaginar() {
    return this->imaginar;
}

double Complex::get_real() {
    return this->real;
}

void Complex::citire(istream &in) {
    cout << "Cititi partea reala: ";
    in >> real;
    cout << "Cititi partea imaginara: ";
    in >> imaginar;
}

istream &operator>>(istream &in, Complex &z) {
    z.citire(in);
    return in;
}

void Complex::afisare(ostream &out) const {
    if (imaginar == 0) out << real;
    else if (imaginar < 0) out << real << imaginar << "*i ";
    else out << real << "+" << imaginar << "*i ";
}

ostream &operator<<(ostream &out, const Complex &z) {
    z.afisare(out);
    return out;
}

void Complex::citireFisier(ifstream &in) {
    in >> real;
    in >> imaginar;
}

ifstream &operator>>(ifstream &in, Complex &z) {
    z.citireFisier(in);
    return in;
}

double Complex::modul() {
    return sqrt(real * real + imaginar * imaginar);
}

void Complex::egal(Complex z) {
    real = z.real;
    imaginar = z.imaginar;
}

Complex &Complex::operator=(Complex &z) {
    real = z.real;
    imaginar = z.imaginar;
    return *this; // intotdeauna returneaza *this din op =
}

inline Complex &operator+(Complex &z1, Complex &z2) {
    Complex *z = new Complex;
    z->real = z1.real + z2.real;
    z->imaginar = z1.imaginar + z2.imaginar;
    return *z;
}

inline Complex &operator*(Complex &z1, Complex &z2) {
    Complex *z = new Complex;
    z->real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z->imaginar = z1.real * z2.imaginar + z2.real * z1.imaginar;
    return *z;
}

Complex &operator/(Complex &z1, Complex &z2) {
    Complex *z = new Complex;
    z->real = (z1.real * z2.real + z1.imaginar * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    z->imaginar = (z2.real * z1.imaginar - z1.real * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    return *z;
}

class VectorComplex {
private:
    int arraySize;
    Complex *complex;
public:
    VectorComplex(Complex z, int arraySize);

    VectorComplex();

    VectorComplex(VectorComplex &);

    ~VectorComplex();

    int getArraySize();

    void setArraySize(int arraysize);

    Complex *getComplex();

    void setComplex(Complex *complex);

    void citireAfisareVectorComplex();

    void citireVectorComplex();

    void afisareVectorComplex();

    void vecComplexModule(double vecModule[]);

    vector<double> vecComplexModule();

    void sortByModuls();

    void swap(Complex &c1, Complex &c2);

    Complex suma();
};

VectorComplex::VectorComplex(Complex z, int arraySize) {
    this->arraySize = arraySize;
    complex = new Complex[arraySize];
    for (int i = 0; i < this->arraySize; i++) {
        complex[i].real = z.real;
        complex[i].imaginar = z.imaginar;
    }
}

VectorComplex::VectorComplex() {
    this->arraySize = 0;
    complex = NULL;
}

VectorComplex::VectorComplex(VectorComplex &z) {
    arraySize = z.arraySize;
    complex = new Complex[arraySize];
    for (int i = 0; i < arraySize; i++)
        complex[i] = z.complex[i];
}

VectorComplex::~VectorComplex() {
    this->arraySize = 0;
    delete[] complex;
}

int VectorComplex::getArraySize() {
    return arraySize;
}

Complex *VectorComplex::getComplex() {
    return complex;
}

void VectorComplex::setComplex(Complex *complex) {
    this->complex = complex;
}

void VectorComplex::setArraySize(int arraysize) {
    this->arraySize = arraysize;
}

void VectorComplex::citireAfisareVectorComplex() {
    citireVectorComplex();
    afisareVectorComplex();
}

void VectorComplex::citireVectorComplex() {
    int arraySize;
    cout << "Introduceti numarul componentelor: ";
    cin >> arraySize;
    this->arraySize = arraySize;
    complex = new Complex[arraySize];
    for (int i = 0; i < arraySize; i++)
        cin >> complex[i];
}

void VectorComplex::afisareVectorComplex() {
    for (int i = 0; i < arraySize; i++)
        cout << "Elemntul de pe pozitia " <<
             i << " este: " << complex[i] << endl;
}

void VectorComplex::vecComplexModule(double vecModule[]) {
    for (int i = 0; i < arraySize; i++)
        vecModule[i] = complex[i].modul();
}

vector<double> VectorComplex::vecComplexModule() {
    vector<double> vecModule(arraySize);
    for (int i = 0; i < arraySize; i++)
        vecModule[i] = complex[i].modul();
    return vecModule;
}

void VectorComplex::swap(Complex &c1, Complex &c2) {
    Complex aux;
    aux.imaginar = c1.imaginar;
    aux.real = c1.real;

    c1.imaginar = c2.imaginar;
    c1.real = c2.real;

    c2.imaginar = aux.imaginar;
    c2.real = aux.real;
}

void VectorComplex::sortByModuls() {
    vector<double> vec = vecComplexModule();
    for (int i = 0; i < arraySize - 1; i++)
        for (int j = i + 1; j < arraySize; j++) {
            if (vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
                VectorComplex::swap(complex[i], complex[j]);
            }
        }
}

Complex VectorComplex::suma() {
    Complex sum;
    for (int i = 0; i < arraySize; i++)
        sum = sum + complex[i];
    return sum;
}

void menu_output() {
    cout << "\n Chelaru Paul 134 - Proiect - Nume proiect Clasa ”Vector_Complex” : \n";
    cout << "\n\t MENIU:";
    cout << "\n===========================================\n";
    cout << "\n";
    cout << "1. Initializarea cu un numar dat pe toate"
            " componentele (primeste ca parametru numarul"
            " respectiv si numarul componentelor).";
    cout << "\n";
    cout << "2. Determinarea vectorului modulelor.";
    cout << "\n";
    cout << "3. Sortarea crescatoare dupa module a vectorului.";
    cout << "\n";
    cout << "4. Calculul  sumei  tuturor  elementelor  vectorului "
            "(utilizeaza operatorul + din clasa de numere complexe).";
    cout << "\n";
    cout << "5. Compierea vectorului in alt vector (folosind constructorul"
            " de copiere).";
    cout << "\n";
    cout << "6. Modificarea unui element din vector (folosind setter si getter).";
    cout << "\n";
    cout << "0. Iesire.";
    cout << "\n";
}

void menu() {
    int option;///optiunea aleasa din meniu
    option = 0;

    do {
        menu_output();

        cout << "\nIntroduceti numarul actiunii: ";
        cin >> option;

        if (option == 1) {
            int arraySize;
            cout << "Introduceti numarul componentelor: ";
            cin >> arraySize;
            cout << endl;
            cout << "Introduceti numarul complex." << endl;
            Complex complex;
            cin >> complex;
            VectorComplex vectorComplex(complex, arraySize);
            vectorComplex.afisareVectorComplex();
        }
        if (option == 2) {
            VectorComplex vectorComplex;
            vectorComplex.citireAfisareVectorComplex();
            vector<double> vecModule = vectorComplex.vecComplexModule();
            cout << "Vectorul modulelor este: " << endl;
            for (int i = 0; i < vecModule.size(); i++) {
                cout << "Modulul elemntului de pe pozitia " <<
                     i << " este: " << vecModule[i] << endl;
            }
        }
        if (option == 3) {
            VectorComplex vectorComplex;
            vectorComplex.citireAfisareVectorComplex();
            vectorComplex.sortByModuls();
            cout << "Vectorul sortat dupa modulele elementelor este:" << endl;
            vectorComplex.afisareVectorComplex();
        }
        if (option == 4) {
            VectorComplex vectorComplex;
            cout << endl;
            vectorComplex.citireAfisareVectorComplex();
            cout << "Suma elementelor din vector este: " << vectorComplex.suma();
        }
        if (option == 5){
            VectorComplex vectorComplex1;
            vectorComplex1.citireAfisareVectorComplex();
            VectorComplex vectorComplex2(vectorComplex1);
            cout << "Vectorul copiat este: " << endl;
            vectorComplex2.afisareVectorComplex();
        }
        if (option == 6){
            VectorComplex vectorComplex;
            cout << "Creare vector." << endl;
            vectorComplex.citireAfisareVectorComplex();
            cout << "Introduceti pozitia elementului ( mai mica strict decat " <<
            vectorComplex.getArraySize() << ") care sa fie modificat." << endl;
            int poz;
            cout << "Pozitia: ";
            cin >> poz;
            cout << "Introduceti numarul cu care sa fie modificat"
                    " elementul de pe pozitia " << poz << endl;
            Complex complex;
            cin >> complex;
            vectorComplex.getComplex()[poz].set_real(complex.get_real());
            vectorComplex.getComplex()[poz].set_imaginar(complex.get_imaginar());
            cout << "Vectorul modificat este: " << endl;
            vectorComplex.afisareVectorComplex();
        }
        if (option == 0) {
            cout << "\nEXIT!\n";
        }
        if (option < 0 || option > 6) {
            cout << "\nSelectie invalida\n";
        }
        cout << "\n";
    } while (option != 0);
}

int main() {
    menu();
    return 0;
}
