#ifndef ARBREGEN_HH
#define ARBREGEN_HH

#include "Arbre.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif

/** @brief Llegeix un arbre genealògic
    \pre A l'entrada estandard hi ha l'informació d'un arbre genealògic, als parametres hi
    ha un arbre buit i la marca
    \post S'omple el paràmetre Arbre amb l'informació llegida
*/
void llegir_arbre_gen(Arbre<string>& a, string marca);

/** @brief Escriu un arbre genealògic
    \pre cert
    \post Escriu pel canal de sortida un arbre genealògic
*/
void escriure_arbre_gen(Arbre<string>& a);

/** @brief Compara dos arbres i completa amb una marca
    \pre Als parametres hi han dos arbres i un boolea es_parcial
    \post Si l'arbre parcial és parcial, es_parcial = true i les parts de
    complet que no apareixen a parcial es marquen, altrament es_parcial = false

*/
void compararar_arbre_gen(Arbre<string>& complet, Arbre<string>& parcial, bool& es_parcial);

/** @brief Funció per marcar un arbre
    \pre Als parametres tenim un arbre a marcar i la marca que hi volem posar
    \post Totes les arrels de l'arbre quedaran marcades tal que arrel = marca + arrel + marca
*/
void renombrar(Arbre<string>& arbre, const string marca);

#endif
