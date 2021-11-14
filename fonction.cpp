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

int getInt(const int MIN, const int MAX, const string& USAGE_MSG,
           const string& CONJUNCTION_MSG, const string& ERROR_MSG) {

   // ------------------------------------------
   //    saisie une valeur entre MIN et MAX
   // ------------------------------------------
   long value;
   bool error;

   do {
      // message et saisie
      cout << USAGE_MSG << MIN << CONJUNCTION_MSG
           << MAX << " : ";
      cin  >> value;

      // vérification
      error = cin.fail() or value < MIN;
      if (error) {
         cout << ERROR_MSG << endl;
         cin.clear();
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return value;
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

char charGenerator(int rand1_26){
   char c = char('a' + rand1_26);

   return c;

}


char getC(const char MIN_CHAR, const char MAX_CHAR){

   // --------------------------------------------------
   // saisie une valeur entre MIN_CHAR et MAX_CHAR
   // --------------------------------------------------

   char userChar;
   bool error;

   do {
      // saisie
      cin >> userChar;

      // vérification
      error = cin.fail() or userChar < MIN_CHAR or userChar > MAX_CHAR;
      if (error) {

         cin.clear();
      }
      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return userChar;
}

bool tryAgain(const string& USAGE_MSG, const string& CONJUNCTION_MSG,
              const string& END_OF_MSG, const string& ERROR_MSG){
   char userChar;
   bool error;
   bool output;

   do {
      // message et saisie
      cout << USAGE_MSG << CONJUNCTION_MSG << END_OF_MSG << endl;
      cin  >> userChar;
      userChar = (char)tolower(userChar);


      // vérification
      error = cin.fail() or userChar !='n' or userChar != 'o';
      if (error) {
         cout << ERROR_MSG << endl;
         cin.clear();
      }
      output = userChar == 'n' ? 0 : userChar == 'o' ? 1 : 0;

      // vider buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

   } while(error);

   return output;
}

//***********************************************************************************
// nom         timeElapse
// but         Fonction qui permet compter le temps passé.
// param       Aucun
// return      Un entier
// exception   n/a
//***********************************************************************************
double timeElapse(){
   clock_t start = 0;
   clock_t end;
   static int startOrEnd = 1;
   float userTime = 0;

   if (startOrEnd % 2 != 0) {
      start = clock();
      ++startOrEnd;
   }
   else {
      end = clock();
      float realTime = (float)(end - start) / CLOCKS_PER_SEC;
      userTime = realTime;
      ++startOrEnd;
   }

   return userTime;
}