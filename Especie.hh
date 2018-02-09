/** @file Especie.hh
    @brief Especificació de la clase Especie
*/

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/** @class Especie
    @brief Representa una espècie

    Conté informació d'una espècie
*/
class Especie {

private:

  int N;
  vector<int> li;
  int lx;
  int ly;

public:

  /** @brief Creadora per defecte
      s'executa automàticament al declarar una Espècie
      \pre cert
      \post El resultat es una Espècie sense informació
  */
  Especie();

  // Modificadors

  /** @brief Llegeix la informació d'una espècie
      \pre A l'entrada estandard hi ha l'informació basica de l'espècie
      \post S'omple el paràmetre implícit amb l'informació llegida
  */
  void llegir_informacio_especie();

  // Consultors

  /** @brief Retorna la mida d'un cromosoma sexual
      \pre Hi ha 'X' o 'Y' als parametres
      \post Es retorna la mida de 'X' o 'Y'
  */
  int mida_cromosoma_sexual(const char c) const;

  /** @brief Retorna la mida d'un cromosoma
      \pre Hi ha la posició del cromosoma i
      \post Es retorna la mida del cromosoma i
  */
  int mida_cromosoma(const int i) const;

  /** @brief Retorna el nombre de cromosomes
      \pre cert
      \post Es retorna el nombre de parells de cromosomes no sexuals
  */
  int consultar_N() const;

};
#endif
