/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) : Tomas Pavoni et Alexandre Delétraz
Date creation : 10.11.2021
Description : <à compléter>
Remarque(s) : <à compléter>
Compilateur : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include "fonction.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {

   const string INT_MSG         = "veuillez enter une valeur superieur à "s;
   const string CONJUNCTION_MSG = " et "s;
   const string END_OF_MSG      = "] : "s;
   const string MSG_ERROR       = "/!\\ erreur de saisie"s;
   const string TRY_AGAIN_MSG   = "Voulez-vous recommencer ?"s;
   const char MIN_CHAR          = 'a';
   const char MAX_CHAR          = 'z';


   // Début du programme
   cout << "Bonjour, ce programme est fait pour tester votre dexterite" << endl
        << "avec un clavier d'ordinateur."                              << endl
        << "Vous allez avoir le choix du nombre de caracteres que vous" << endl
        << "aurez a rentrer. A la fin de votre exercice, le programme"  << endl
        << "vous indiquera le temps total que vous avez mis pour finir" << endl
        << "l'exercice, ainsi que le temps moyen pour chaque caractere" << endl;

   // Boucle pour recommencer la partie
   bool doAgain;
   do {
      // Saisie du nombre de caractères à afficher
      long int nbrChar = getInt(0, LONG_MAX, INT_MSG ,
                                "",
                                "",MSG_ERROR);
      // Démarrage du chrono
      timeElapse();

      unsigned long int countCorrect = 0;
      for (long int i = 1; i <= nbrChar; i++) {
         // Affichage du caractère généré aléatoirement
         char charGenerated = charGenerator(intGenerator1_26());
         cout << charGenerated;
         // Saisie d'un char
         char charIn = getC(MIN_CHAR, MAX_CHAR);
         // Comparaison
         bool isCorrect = charGenerated == charIn;
         countCorrect += isCorrect;
      }
      // Arrêt du chrono

      // Affichage
      double time = timeElapse();
      double averageTime = time / nbrChar;
      cout << time << averageTime << countCorrect << nbrChar;
      // Recommencer ?

      doAgain = tryAgain(TRY_AGAIN_MSG, "",
                         "" , MSG_ERROR);
   } while(doAgain);

   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer


   return EXIT_SUCCESS;
}
