/** @file ParCrom.hh
    @brief Especificació de la clase Parell de Cromosomes
*/

#ifndef PARCROM_HH
#define PARCROM_HH

#include "Especie.hh"
#ifndef NO_DIAGRAM
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#endif

/** @class ParCrom
    @brief Representa un Parell de Cromosomes

    Conté dos cromosomes
*/
class ParCrom {

private:
  pair<vector<int>, vector<int> > parell;

public:

  /** @brief Creadora per defecte
      s'executa automàticament al declarar un Parell de Cromosomes
      \pre cert
      \post El resultat es un Parell de Cromosomes sense cromosomes
  */
  ParCrom();

  // Modificadors

  /** @brief Llegeix l'informació de dos cromosomes
      \pre A l'entrada estandard hi ha l'informació de dos cromosomes
      \post S'omple el paràmetre implícit amb l'informació llegida
  */
  void llegir(const int li);

  /** @brief Llegeix l'informació de dos cromosomes sexuals
      \pre A l'entrada estandard hi ha l'informació de dos cromosomes
      \post S'omple el paràmetre implícit amb l'informació llegida
  */
  void llegir_sexual(const int l1, const int l2);

  /** @brief Reprodueix dos cromosomes
      \pre Hi ha la longitud, els dos cromosomes dels pares i la k als parametres
      \post S'omple el cromosoma implícit
  */
  void reproduir(const int li, const int k, vector<int> mare, vector<int> pare);

  // Escriptura

  /** @brief S'escriu pel canal de sortida el primer cromosoma
      \pre cert
      \post Pel canal de sortida s'escriuen els gens del primer cromosoma
  */
  void escriure_primer(const int li) const;

  /** @brief S'escriu pel canal de sortida el segon cromosoma
      \pre cert
      \post Pel canal de sortida s'escriuen els gens del segon cromosoma
  */
  void escriure_segon(const int li) const;

  // Consultors

  /** @brief Es retorna el primer cromosoma
      \pre cert
      \post Es retorna el primer cromosoma
  */
  vector<int> primer() const;

  /** @brief Es retorna el segon cromosoma
      \pre cert
      \post Es retorna el segon cromosoma
  */
  vector<int> segon() const;

};
#endif
