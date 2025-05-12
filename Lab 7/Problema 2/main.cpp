#include <iostream>
using namespace std;

template <typename T>
class Nod {
public:
    T valoare;
    Nod* parinte;
    Nod* primulCopil;
    Nod* frateDreapta;

    Nod(const T& val, Nod* p = nullptr)
        : valoare(val), parinte(p), primulCopil(nullptr), frateDreapta(nullptr) {
    }
};

template <typename T>
class Arbore {
private:
    Nod<T>* radacina;

public:
    Arbore() : radacina(nullptr) {}

    Nod<T>* adauga_nod(Nod<T>* parinte, const T& valoare) {
        Nod<T>* nodNou = new Nod<T>(valoare, parinte);

        if (parinte == nullptr) {
            radacina = nodNou;
        }
        else {
            if (parinte->primulCopil == nullptr) {
                parinte->primulCopil = nodNou;
            }
            else {
                Nod<T>* frate = parinte->primulCopil;
                while (frate->frateDreapta != nullptr) {
                    frate = frate->frateDreapta;
                }
                frate->frateDreapta = nodNou;
            }
        }

        return nodNou;
    }

    Nod<T>* obtine_nod(Nod<T>* nod) {
        if (nod == nullptr) return radacina;
        return nod;
    }

    void sterge_nod(Nod<T>* nod) {
        if (!nod) return;

        Nod<T>* copil = nod->primulCopil;
        while (copil) {
            Nod<T>* urmator = copil->frateDreapta;
            sterge_nod(copil);
            copil = urmator;
        }

        if (nod->parinte) {
            Nod<T>*& cap = nod->parinte->primulCopil;
            if (cap == nod) {
                cap = nod->frateDreapta;
            }
            else {
                Nod<T>* anterior = cap;
                while (anterior && anterior->frateDreapta != nod) {
                    anterior = anterior->frateDreapta;
                }
                if (anterior) {
                    anterior->frateDreapta = nod->frateDreapta;
                }
            }
        }
        else if (nod == radacina) {
            radacina = nullptr;
        }

        delete nod;
    }

    Nod<T>* cauta(Nod<T>* nod, bool (*compara)(const T&)) {
        if (nod == nullptr) nod = radacina;
        if (nod == nullptr) return nullptr;

        if (compara(nod->valoare)) return nod;

        Nod<T>* copil = nod->primulCopil;
        while (copil) {
            Nod<T>* gasit = cauta(copil, compara);
            if (gasit) return gasit;
            copil = copil->frateDreapta;
        }

        return nullptr;
    }

    void insereaza(Nod<T>* parinte, int pozitie, const T& valoare) {
        if (!parinte) return;

        Nod<T>* nodNou = new Nod<T>(valoare, parinte);

        if (pozitie == 0 || parinte->primulCopil == nullptr) {
            nodNou->frateDreapta = parinte->primulCopil;
            parinte->primulCopil = nodNou;
        }
        else {
            Nod<T>* curent = parinte->primulCopil;
            int index = 0;
            while (curent->frateDreapta != nullptr && index < pozitie - 1) {
                curent = curent->frateDreapta;
                index++;
            }
            nodNou->frateDreapta = curent->frateDreapta;
            curent->frateDreapta = nodNou;
        }
    }

    void sorteaza(Nod<T>* nod, bool (*compara)(const T&, const T&) = nullptr) {
        if (!nod || !nod->primulCopil) return;

        bool schimbat;
        do {
            schimbat = false;
            Nod<T>* anterior = nullptr;
            Nod<T>* curent = nod->primulCopil;
            Nod<T>* urmator = curent->frateDreapta;

            while (urmator) {
                bool trebuieSchimbat = false;
                if (compara != nullptr) {
                    trebuieSchimbat = compara(urmator->valoare, curent->valoare);
                }
                else {
                    trebuieSchimbat = urmator->valoare < curent->valoare;
                }

                if (trebuieSchimbat) {
                    schimbat = true;
                    curent->frateDreapta = urmator->frateDreapta;
                    urmator->frateDreapta = curent;

                    if (anterior != nullptr) {
                        anterior->frateDreapta = urmator;
                    }
                    else {
                        nod->primulCopil = urmator;
                    }

                    anterior = urmator;
                    urmator = curent->frateDreapta;
                }
                else {
                    anterior = curent;
                    curent = urmator;
                    urmator = urmator->frateDreapta;
                }
            }
        } while (schimbat);
    }

    int numara(Nod<T>* nod) {
        if (nod == nullptr) nod = radacina;
        if (!nod) return 0;

        int total = 0;
        Nod<T>* copil = nod->primulCopil;
        while (copil) {
            total += 1 + numara(copil);
            copil = copil->frateDreapta;
        }

        return total;
    }

    Nod<T>* obtine_radacina() {
        return radacina;
    }

    ~Arbore() {
        sterge_nod(radacina);
    }
};
bool esteCinci(const int& val) {
    return val == 5;
}

bool maiMic(const int& a, const int& b) {
    return a < b;
}

int main() {
    Arbore<int> arbore;

    Nod<int>* nodRadacina = arbore.adauga_nod(nullptr, 10);
    Nod<int>* copil1 = arbore.adauga_nod(nodRadacina, 30);
    Nod<int>* copil2 = arbore.adauga_nod(nodRadacina, 5);
    Nod<int>* copil3 = arbore.adauga_nod(nodRadacina, 20);

    cout << "Inainte de sortare:" << endl;
    Nod<int>* copil = nodRadacina->primulCopil;
    while (copil) {
        cout << copil->valoare << " ";
        copil = copil->frateDreapta;
    }
    cout << endl;

    arbore.sorteaza(nodRadacina, maiMic);

    cout << "Dupa sortare:" << endl;
    copil = nodRadacina->primulCopil;
    while (copil) {
        cout << copil->valoare << " ";
        copil = copil->frateDreapta;
    }
    cout << endl;

    Nod<int>* gasit = arbore.cauta(nullptr, esteCinci);
    if (gasit) {
        cout << "Am gasit nodul cu valoarea 5" << endl;
    }

    cout << "Total copii (cu tot cu descendenti): " << arbore.numara(nullptr) << endl;

    return 0;
}
