/*
  ---------------------------------------------------------------------------
  Fichier     : fonction.cpp

  Auteur(s)   : Alexandre Delétraz et Tomas Pavoni
  Date        : 12.11.2021
  But         : Créer une librairie de fonctions utiles à réaliser un testeur de
                dactylographie.

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


int getIntAndVerify(const int MIN, const int MAX, const string& USAGE_MSG,
                    const string& ERROR_MSG) {

   int value;
   bool error;

   do {
      // message et saisie
      cout << USAGE_MSG << "[" << MIN << "-" << MAX << "] : ";
      cin  >> value;

      // vérification
      error = cin.fail() or value < MIN or value > MAX;
      if (error) {
         cout << ERROR_MSG << endl;
         cin.clear();
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return value;
}


char letterGenerator(){

   const int NBR_LETTER = 26;                // Nombre de lettre dans l'alphabet

   static bool first = true;
   if (first) {
      srand((unsigned)time(NULL));
      first = false;
   }
   int rand0_25 = rand() % NBR_LETTER;       // valeur [0-25]
   char c       = char('a' + rand0_25);

   return c;
}


char getC(){

   char userChar;
   bool error;

   do {
      // saisie
      cin >> userChar;

      // vérification
      error = cin.fail();
      if (error) {
         cin.clear();
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return userChar;
}


bool tryAgain(const string USAGE_MSG, const string& ERROR_MSG){

   char userChar;
   bool output;
   bool error = false;
   do {
      // saisie
      cout << endl << USAGE_MSG;
      cin  >> userChar;
      userChar = (char)tolower(userChar);

      // vérification
      error = cin.fail();
      if (error) {
         cout << ERROR_MSG << endl;
         cin.clear();
      }
      else if (userChar == 'n'){
         output = false;
      }
      else if (userChar == 'o'){
         output = true;
      }
      else{
         cout << ERROR_MSG << endl;
         error = true;
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return output;
}