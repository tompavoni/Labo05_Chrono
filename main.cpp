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

using namespace std;

int main() {

   // Début du programme
   cout << "" << endl;
   // Boucle pour recommencer la partie
   bool doAgain;
   do {
      // Saisie du nombre de caractères à afficher
      unsigned long int nbrChar = getInt();
      // Démarrage du chrono
      temps;

      unsigned long int countCorrect = 0;
      for (unsigned long int i = 1; i <= nbrChar; i++) {
         // Affichage du caractère généré aléatoirement
         char charGenerated = charGenerator(intGenerator1_26);
         cout << charGenerated;
         // Saisie d'un char
         char charIn = getChar();
         // Comparaison
         bool isCorrect = charGenerated == charIn ? true : false;
         countCorrect += isCorrect;
      }
      // Arrêt du chrono
      tempsfini;
      // Affichage
      double temps;
      double tempsMoyen;
      cout << temps,tempsMoyen,countCorrect,nbrChar;
      // Recommencer ?
      cout << "" << endl;
      doAgain = tryAgain();
   } while(doAgain);

   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
