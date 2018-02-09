/** @file Poblacio.hh
    @brief Especificació de la clase Poblacio
*/

#ifndef POBLACIO_HH
#define POBLACIO_HH

#include "Especie.hh"
#include "Arbre.hh"
#include "Individu.hh"
#include "ArbreGen.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

/** @class Poblacio
    @brief Representa una població de persona

    La classe té un conjunt de persones.
*/
class Poblacio {

private:

  struct Persona {
    Individu ind;
    string pare = "$";
    string mare = "$";
  };

  map<string, Persona> habitants;

  /** @brief Determina si un individu és antecessor d'un altre
      \pre Als paràmetres hi han dos noms, ant que és la persona que comparem
      en tot moment i nom, que es va actualitzant a cada crida de la recursiva
      per comparar si es antecessor o no.
      \post El resultat es true si ant es antecessor de nom o false altrament
  */
  bool antecessors(const string nom, const string& ant) const;

  /** @brief Es mira si les persones són germanes
      \pre Hi han dues persones als paràmetres
      \post Es retorna true si les persones són germanes, altrament, false
  */
  bool son_germans(const Persona& p1, const Persona& p2) const;

  /** @brief Es mira si les persones tene diferent sexe
      \pre Hi han dues persones als paràmetres
      \post Es retorna true si les persones tenen diferent sexe, altrament, false
  */
  bool diff_sexe(const Persona& p1, const Persona& p2) const;

public:

  /** @brief Creadora per Poblacio
      s'executa automàticament al declarar una població
      \pre cert
      \post El resultat es una població sense Individus
  */
  Poblacio();

  // Modificadors

  /** @brief Afegeix un nou individu a la població
      \pre A l'entrada estandard hi ha l'informació d'un individu
      \post S'afegeix a la població l'individu que s'ha llegit
  */
  void afegir_individu(const Individu& ind);

  /** @brief S'intenta reproduir amb dos individus
      \pre Hi han els noms del pare i la mare i del posible fill als paràmetres, també l'espècie
      \post Si el pare i la mare es poden reproduir, s'afegeix el fill a la població
  */
  void reproduir(const Especie& e, const string mare, const string pare, const string fill);

  // Consultors

  /** @brief Es mira si existeix un individu
      \pre Hi ha el nom de l'individu als parametres
      \post Si es troba l'individu es retorna true, altrament false
  */
  bool esta_individu(const string nom) const;

  /** @brief Es retorna una persona si es troba
      \pre El nom com a paràmetre, un boolea anomenat trobat i una persona buida
      \post Si es troba la persona trobat = true i s'omple pers amb la persona trobada,
      altrament trobat = false
  */
  void buscar_persona(const string nom, bool& trobat, Persona& pers) const;

  /** @brief Es retorna un individu si es troba
      \pre El nom com a paràmetre, un boolea anomenat trobat i un individu buit
      \post Si es troba l'individu trobat = true i s'omple ind amb l'individu trobat,
      altrament trobat = false
  */
  void buscar_individu(const string nom, bool& trobat, Individu& ind) const;

  // Escriptura

  /** @brief S'escriu pel canal de sortida la població ordenada alfabèticament
      \pre cert
      \post Pel canal de sortida s'escriu el nom, sexe i el nom del pare i mare de cada individu a la població
  */
  void escriure() const;

  /** @brief S'escriu pel canal de sortida l'arbre de l'individu
      \pre Hi ha el nom de l'individu als parametres
      \post Pel canal de sortida s'escriu l'arbre genealògic de l'individu
  */
  void escriure_arbre(const string nom) const;

  /** @brief Es genera un arbre a partir del nom
      \pre Hi ha el nom del subarbre a generar i un arbre com a paràmetre per referència
      \post L'arbre arb pasa a ser un arbre complet de 'nom'
  */
  void generar_arbre_i(const string nom, Arbre<string>& arb) const;

};
#endif
