#include <iostream>
#include "Dictionnaire.hpp"

int main()
{
    Dictionnaire* dic = new Dictionnaire();

    dic->AddWord("abas");
    dic->AddWord("arbre");
    dic->AddWord("bas");
    dic->PrintDico();

    return 0;   
};