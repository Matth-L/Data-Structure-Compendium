#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>
#include <memory>
#include <ctime>

using namespace std;

class Person
{
private:
    // basic attributes
    int id;
    string prenom;
    string nom;
    string couleurYeux;
    tm dateNaissance;
    int age;

    void calculateAge()
    {
        time_t now = time(0);
        tm *currentTime = localtime(&now);
        int currentYear = currentTime->tm_year + 1900;
        int currentMonth = currentTime->tm_mon + 1;
        int currentDay = currentTime->tm_mday;

        int birthYear = dateNaissance.tm_year + 1900;
        int birthMonth = dateNaissance.tm_mon + 1;
        int birthDay = dateNaissance.tm_mday;

        age = currentYear - birthYear;
        if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
        {
            age--;
        }
    }

public:
    Person();

    Person(int id,
           string prenom,
           string nom,
           string couleurYeux,
           int jour,
           int mois,
           int annevaluee);

    Person(int id,
           string prenom,
           string nom,
           string couleurYeux,
           tm dateNaissance);
    ~Person();

    // getter
    int getID() const;
    string getPrenom() const;
    string getNom() const;
    string getCouleurYeux() const;
    int getAge() const;
    tm getDateNaissance() const;

    // setter
    void setID(int id);
    void setPrenom(string prenom);
    void setNom(string nom);
    void setCouleurYeux(string couleurYeux);
    void setDateNaissance(tm dateNaissance);

    // operator
    bool operator==(const Person &p) const;
    bool operator<(const Person &p) const;

    // affichage
    friend ostream &operator<<(ostream &os, const Person &p);
}

;

#endif // PERSON_HPP
