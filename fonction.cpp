/*
  ---------------------------------------------------------------------------
  Fichier     : fonction.cpp

  Auteur(s)   : Alexandre Delétraz et Tomas Pavoni
  Date        : 12.11.2021
  But         : Avoir une librairie de fonction.

  Remarque(s) : à compléter

  Compilateur : gcc version 8.2.0
  ---------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
#include "fonction.h"

long int getInt(const long MIN, const long MAX) {

      // ------------------------------------------
      //    saisie une valeur entre MIN et MAX
      // ------------------------------------------
      long value;
      bool error;

      do {
         // message et saisie
         cout << "Veuillez entrer une valeur entre [" << MIN << " et "
              << MAX << "] : ";
         cin  >> value;

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

char charGenerator(int rand1_26){
   char c = char('a' + rand1_26);

   return c;

}

int intGenerator1_26(){

   static bool first = true;
   if (first) {
      srand((unsigned)time(NULL));
      first = false;
   }
   int rand1_26 = rand() % 26;              // valeur [1-26]

   return rand1_26;
}

char getC(const char MIN_CHAR, const char MAX_CHAR){

   // --------------------------------------------------
   // saisie une valeur entre MIN_CHAR et MAX_CHAR
   // --------------------------------------------------

   char userChar = 0;
   bool error;

   do {
      // message et saisie
      cout << "Saisisez le caractère" << endl;

      // vérification
      error = cin.fail() or userChar < MIN_CHAR or userChar > MAX_CHAR;
      if (error) {
         cout << MSG_ERROR << endl;
         cin.clear();
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return userChar;
}

bool tryAgain(){
   char userChar;
   bool error;

   do {
      // message et saisie
      cin >> userChar;

      // vérification
      error = cin.fail() or userChar !='n' or userChar != 'o';
      if (error) {
         cout << MSG_ERROR << endl;
         cin.clear();
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return userChar;
}