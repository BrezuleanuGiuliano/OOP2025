#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

enum class TipMaterie { Obligatorie, Facultativa, Optionala };

// Clasa abstracta Materie
class Materie {
protected:
    string nume;
    int credite;
    TipMaterie tip;
public:
    Materie(string nume, int credite, TipMaterie tip): nume(nume), credite(credite), tip(tip) {}

    virtual string getNume() const = 0;
    virtual int getCredite() const = 0;
    virtual TipMaterie getTip() const = 0;
    virtual ~Materie() = default;
};

// Clase derivate pentru fiecare materie
class Matematica : public Materie {
public:
    Matematica() : Materie("Matematica", 5, TipMaterie::Obligatorie) {}
    string getNume() const override { return nume; }
    int getCredite() const override { return credite; }
    TipMaterie getTip() const override { return tip; }
};

class Romana : public Materie {
public:
    Romana() : Materie("Romana", 4, TipMaterie::Obligatorie) {}
    string getNume() const override { return nume; }
    int getCredite() const override { return credite; }
    TipMaterie getTip() const override { return tip; }
};

class Engleza : public Materie {
public:
    Engleza() : Materie("Engleza", 3, TipMaterie::Facultativa) {}
    string getNume() const override { return nume; }
    int getCredite() const override { return credite; }
    TipMaterie getTip() const override { return tip; }
};

class Informatica : public Materie {
public:
    Informatica() : Materie("Informatica", 6, TipMaterie::Obligatorie) {}
    string getNume() const override { return nume; }
    int getCredite() const override { return credite; }
    TipMaterie getTip() const override { return tip; }
};

class Optional1 : public Materie {
public:
    Optional1() : Materie("Optional1", 2, TipMaterie::Optionala) {}
    string getNume() const override { return nume; }
    int getCredite() const override { return credite; }
    TipMaterie getTip() const override { return tip; }
};

class Optional2 : public Materie {
public:
    Optional2() : Materie("Optional2", 2, TipMaterie::Optionala) {}
    string getNume() const override { return nume; }
    int getCredite() const override { return credite; }
    TipMaterie getTip() const override { return tip; }
};

// Clasa Student
class Student {
    string nume;
    int nrMatricol;
    string program; // RO sau EN
    map<string, float> note;// nume materie -> nota
public:
   
    Student(string nume, int nrMatricol, string program)
        : nume(nume), nrMatricol(nrMatricol), program(program) {
    }

    void adaugaNota(string materie, float nota) {
        note[materie] = nota;
    }

    float calculeazaMedie() const {
        if (note.empty()) return 0.0;
        float suma = 0;
        for (auto& it : note) {
            suma += it.second;
        }
        return suma / note.size();
    }

    string getNume() const { return nume; }
    int getNrMatricol() const { return nrMatricol; }
    string getProgram() const { return program; }
    const map<string, float>& getNote() const { return note; }
    float GetNota(const char* materie)
    {
        return note[materie];
    }
};

// Clasa abstracta Catalog
class Catalog {
protected:
    vector<Student> studenti;
public:
    virtual void adaugaStudent(const Student& s) = 0;
    virtual vector<Student> getStudenti() const = 0;
    virtual void afiseazaRanking() const = 0;
    virtual ~Catalog() = default;
};

// Clasa concreta CatalogRO
class CatalogRO : public Catalog {
public:
    void adaugaStudent(const Student& s) override {
        if (s.getProgram() == "RO")
            studenti.push_back(s);
    }

    vector<Student> getStudenti() const override {
        return studenti;
    }

    void afiseazaRanking() const override {
        vector<Student> cp = studenti;
        // Functie lambda pentru sortare
        sort(cp.begin(), cp.end(), [](const Student& a, const Student& b) {

            
            map<string, float> notele_a = a.getNote();
            map<string, float> notele_b = b.getNote();

            float media1 = (notele_a["Matematica"] + notele_a["Romana"]) / 2;
            float media2 = (notele_b["Matematica"] + notele_b["Romana"]) / 2;
            return media1 > media2;
            });
        for (const auto& s : cp) {
            cout << s.getNume() << " - media rom cu mat "  << endl;
        }
    }
};

// Clasa concreta CatalogEN
class CatalogEN : public Catalog {
public:
    void adaugaStudent(const Student& s) override {
        if (s.getProgram() == "EN")
            studenti.push_back(s);
    }

    vector<Student> getStudenti() const override {
        return studenti;
    }

    void afiseazaRanking() const override {
        vector<Student> cp = studenti;
        sort(cp.begin(), cp.end(), [](const Student& a, const Student& b) {
            return a.calculeazaMedie() > b.calculeazaMedie();
            });

        for (const auto& s : cp) {
            cout << s.getNume() << " - media: " << s.calculeazaMedie() << endl;
        }
    }
};
int main() {
    CatalogRO catalogRO;
    CatalogEN catalogEN;

    Student s1("Ana Popescu", 101, "RO");
    s1.adaugaNota("Matematica", 9);
    s1.adaugaNota("Romana", 8);
    s1.adaugaNota("Informatica", 10);

    Student s2("John Smith", 201, "RO");
    s2.adaugaNota("Matematica", 7);
    s2.adaugaNota("Romana", 9);
    s2.adaugaNota("Informatica", 8);
    //cout << s2.GetNota("Matematica") << endl;

    catalogRO.adaugaStudent(s1);
    catalogRO.adaugaStudent(s2);

    cout << "Catalog RO Ranking:\n";
    catalogRO.afiseazaRanking();

    cout << "\nCatalog EN Ranking:\n";
    catalogEN.afiseazaRanking();

    return 0;
}



