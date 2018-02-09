/** @file Individu.hh
    @brief Especificació de la clase Individu
*/

#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#ifndef NO_DIAGRAM
#include <utility>
#include <vector>
#include <string>
using namespace std;
#endif
#include "Especie.hh"
#include "Arbre.hh"
#include "ParCrom.hh"

/** @class Individu
    @brief Representa un individu

    Un individu té un nom, un sexe (definit per un caràcter, que pot ser 'X' o 'Y'). Un parell de cromosomes sexuals
    i un vector que conté Parells de Cromosomes. Un individu també té (si estan definits) el nom del pare i mare.
*/
class Individu {

private:
  string nom;
  char sexe; // 'X' o 'Y'
  ParCrom par_sexual;
  vector<ParCrom> cromosomes;

public:

  /** @brief Creadora per defecte
      s'executa automàticament al declarar un individu
      \pre cert
      \post El resultat es un Individu sense informació
  */
  Individu();

  // Modificadors

  /** @brief Llegeix la informació d'un individu
      \pre A l'entrada estandard hi ha l'informació de l'individu
      \post S'omple el paràmetre implícit amb l'informació llegida
  */
  void llegir(const Especie& e);

  /** @brief Posa el nom a l'individu
      \pre Als parametres hi ha el nom del individu
      \post Es posa nom a l'individu
  */
  void posar_nom(const string nou_nom);

  /** @brief Reprodueix un individu
      \pre Als parametres hi ha els pares i l'espècie
      \post S'omple el paràmetre implícit
  */
  void reproduir(const Especie& e, const Individu& mare, const Individu& pare);

  // Escriptura

  /** @brief S'escriu pel canal de sortida l'individu
      \pre Hi ha l'espècie als parametres
      \post Pel canal de sortida s'escriu el genotip de l'individu
  */
  void escriure(const Especie& e) const;

  /** @brief Retorna el nom de l'individu
      \pre cert
      \post Retorna el nom de l'individu
  */
  string consultar_nom() const;

  /** @brief Retorna el sexe de l'individu
      \pre cert
      \post Retorna el sexe de l'individu
  */
  char consultar_sexe() const;

};
#endif
