#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string nom;
    string prenom;
    int age;
    double taille;

public:
    Person() : nom("DefaultNom"), prenom("DefaultPrenom"), age(18), taille(170) {} // Default constructor
    Person(string n, string p, int a, double t) : nom(n), prenom(p), age(a), taille(t) {} // Initialization constructor
    Person(const Person &personx) : nom(personx.nom), prenom(personx.prenom), age(personx.age), taille(personx.taille) {} // Copy constructor

    string getNom() const { return nom; }
    void setNom(const string newNom){ nom = newNom; }

    string getPrenom() const { return prenom; }
    void setPrenom(const string newPrenom){ prenom = newPrenom; }

    int getAge() const { return age; }
    void setAge(const int newAge){ age = newAge; }

    double getTaille() const { return taille; }
    void setTaille(const double newTaille){ taille = newTaille; }

    void AffichePersone(){
        cout << "Nom : " << nom << " Prenom : " << prenom << " Age : " << age << " Taille : " << taille << endl;
    }

    void AjoutTaille(double X){ taille += X; }

    void AjoutAge(int Y){ age += Y; }
};

class Etudiant : public Person {
private:
    double matricule;
    double note;
public:
    Etudiant(string n, string p, int a, double t, double m, double no) : Person(n, p, a, t), matricule(m), note(no) {}

    void AfficherEtud(){
        Person::AffichePersone();
        cout << "Matricule : " << matricule << " Note : " << note << endl;
    }

    bool valideornot(){
        if(note >= 10){
            //cout << Person::getNom() << " a valide" << endl;
            cout << nom << " a valide" << endl;
            return true;
        } else {
            //cout << Person::getNom() << " sa9t" << endl;
            cout << nom << " sa9t" << endl;
            return false;
        }
    }
};

int main() {
    Person person1;//default
    person1.AffichePersone();

    Person person2("John", "Doe", 25, 180); //d'initialisation
    person2.AffichePersone();

    Person person3(person2);//copie
    person3.AffichePersone();
    person3.setNom("Alice");
    person3.AffichePersone();

    Etudiant etudiant1("Ahmed", "Brahimi", 20, 175, 123456, 15);
    etudiant1.AfficherEtud();
    etudiant1.valideornot();

    return 0;
}
