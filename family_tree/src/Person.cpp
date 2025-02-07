#include "Person.hpp"
#include <iostream>

Person::Person()
    : id(0), prenom(""), nom(""), couleurYeux(""), dateNaissance()
{
}

Person::Person(int id,
               string prenom,
               string nom,
               string couleurYeux,
               int jour,
               int mois,
               int annee)
    : id(id), prenom(prenom), nom(nom), couleurYeux(couleurYeux)
{

    dateNaissance.tm_mday = jour;
    dateNaissance.tm_mon = mois - 1;      // tm_mon is 0-11
    dateNaissance.tm_year = annee - 1900; // tm_year
    calculateAge();
}

Person::Person(int id,
               string prenom,
               string nom,
               string couleurYeux,
               tm dateNaissance)
    : id(id), prenom(prenom), nom(nom), couleurYeux(couleurYeux), dateNaissance(dateNaissance)
{
    calculateAge();
}

Person::~Person()
{
}

int Person::getID() const
{
    return id;
}

string Person::getPrenom() const
{
    return prenom;
}

string Person::getNom() const
{
    return nom;
}

int Person::getAge() const
{
    return age;
}
string Person::getCouleurYeux() const
{
    return couleurYeux;
}

tm Person::getDateNaissance() const
{
    return dateNaissance;
}

void Person::setID(int id)
{
    this->id = id;
}

void Person::setPrenom(string prenom)
{
    this->prenom = prenom;
}

void Person::setNom(string nom)
{
    this->nom = nom;
}

void Person::setCouleurYeux(string couleurYeux)
{
    this->couleurYeux = couleurYeux;
}

void Person::setDateNaissance(tm dateNaissance)
{
    this->dateNaissance = dateNaissance;
}

bool Person::operator==(const Person &p) const
{
    return id == p.id && prenom == p.prenom && nom == p.nom && couleurYeux == p.couleurYeux &&
           dateNaissance.tm_mday == p.dateNaissance.tm_mday && dateNaissance.tm_mon == p.dateNaissance.tm_mon &&
           dateNaissance.tm_year == p.dateNaissance.tm_year;
}

bool Person::operator<(const Person &p) const
{
    if (nom != p.nom)
        return nom < p.nom;
    if (prenom != p.prenom)
        return prenom < p.prenom;
    if (dateNaissance.tm_year != p.dateNaissance.tm_year)
        return dateNaissance.tm_year < p.dateNaissance.tm_year;
    if (dateNaissance.tm_mon != p.dateNaissance.tm_mon)
        return dateNaissance.tm_mon < p.dateNaissance.tm_mon;
    return dateNaissance.tm_mday < p.dateNaissance.tm_mday;
}

ostream &operator<<(ostream &os, const Person &p)
{
    os << "Person(ID: " << p.id << ", Prenom: " << p.prenom << ", Nom: " << p.nom
       << ", CouleurYeux: " << p.couleurYeux << ", DateNaissance: "
       << (p.dateNaissance.tm_mday) << "/" << (p.dateNaissance.tm_mon + 1) << "/" << (p.dateNaissance.tm_year + 1900)
       << ", Age: " << p.age << ")";
    return os;
}