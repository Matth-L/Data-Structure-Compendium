#include <iostream>
#include "Dictionnaire.hpp"
using namespace std;
int main()
{
    Dictionnaire dict;
    dict.AddWord("chat");

    dict.AddWord("chien");
    dict.AddWord("souris");
    dict.PrintDico();
    dict.affichDict();  // Devrait afficher "chat", "souris", "chien"
    
    dict.DeleteWord("chat");
    dict.affichDict();  // Devrait afficher "souris", "chien"
    
    bool foundChat = dict.SearchWord("chat");  // Devrait retourner false
    cout << "foundChat = " << foundChat << endl;
    bool foundSouris = dict.SearchWord("souris");  // Devrait retourner true
    cout << "foundSouris = " << foundSouris << endl;
    
    dict.AddWord("chat");
    dict.affichDict();  // Devrait afficher "chat", "souris", "chien"

    return 0;   
};