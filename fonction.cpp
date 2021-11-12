/*
  ---------------------------------------------------------------------------
  Fichier     : fonction.cpp

  Auteur(s)   : Alexandre Delétraz et Tomas Pavoni
  Date        : 12.11.2021
  But         :

  Remarque(s) : à compléter

  Compilateur : gcc version 8.2.0
  ---------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

unsigned long int getInt() {

   using namespace std;
      // ------------------------------------------
      // saisie une valeur entre MIN et MAX
      // ------------------------------------------
      const               string MSG_ERROR = "/!\\ erreur de saisie ..."s;
      const unsigned long MIN = 0,
                          MAX = ULONG_MAX;
      unsigned  long      value;
      bool                error;

      do {
         // message et saisie
         cout << "saisie [" << MIN << " - " << MAX << "] : ";
         cin >> value;

         // saisie et vérification en même temps
         // erreur = not(cin >> saisie) or saisie < MIN or saisie > MAX;

         // vérification
         error = cin.fail() or value < MIN;
         if (error) {
            cout << MSG_ERROR << endl;
            cin.clear();
         }
         // vider buffer
         cin.ignore(numeric_limits<streamsize>::max(), '\n');

      } while(error);

      return value;
   }


