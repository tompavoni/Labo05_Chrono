/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Tomas Pavoni et Alexandre Delétraz
Date creation  : 10.11.2021
Description    : Ce programme vous permet de tester votre dactylographie. Pour
                 ceci vous devrez tout d'abord saisir le nombre de caractères que
                 vous voulez afficher. Ensuite une lettre sera générée
                 aléatoirement et vous devrez la copier le plus vite possible.
                 Lorsque vous avez atteint la quantité de caratères définie,
                 le temps total et le temps moyen par caractère vous seront affichés.
                 Pour finir vous aurez la possibilité de recommenecer ou non.

Remarque(s)    : - Ce programme affiche uniquement des lettres minuscules [a-z]
                 - Le chrono démarre une fois le nombre de caractères saisi.

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include "fonction.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {

   const string ERROR_MSG       = "/!\\ erreur de saisie"s;
   const string TRY_AGAIN_MSG   = "Voulez-vous recommencer [o/n] : "s;
   const string RESULT_MSG      = "Nombre de réponses correctes : "s;
   const string GET_MSG         = "veuillez enter une valeur entre "s;
   const string LETTER          = "Lettre : "s;
   const string TIME_SPENT      = "Temps ecoule : "s;
   const string UNIT_OF_TIME    = " sec"s;
   const string RATIO           = " sec par lettre"s;
   const int MIN                = 0;
   const int MAX                = 9999;


   //Message de début
   cout << "Ce programme vous permet de tester votre dactylographie. Pour"  << endl
        << "ceci vous devrez tout d'abord saisir le nombre de caracteres"   << endl
        << "que vous voulez afficher. Ensuite une lettre sera generee"      << endl
        << "aleatoirement et vous devrez la copier le plus vite possible."  << endl
        << "Lorsque vous avez atteint la quantite de carateres definie,"    << endl
        << "le temps total et le temps moyen par caractere vous seront"     << endl
        << "affiches. Pour finir vous aurez la possibilite de recommenecer" << endl
        << "ou non."                                                        << endl;

   // Boucle pour recommencer la partie
   bool doAgain;
   do {
      // Saisie du nombre de caractères à afficher
      unsigned nbrChar = unsigned(getIntAndVerify(MIN, MAX, GET_MSG, ERROR_MSG));

      // Démarrage du chrono
      time_t startChrono = time(NULL);

      // Affichage et comparaison des caractères
      unsigned countCorrect = 0;
      for (unsigned i = 1; i <= nbrChar; i++) {

         // Affichage du caractère généré aléatoirement
         char charGenerated = letterGenerator();
         cout << LETTER << charGenerated << " : ";

         // Saisie du caractère entré par l'utilisateur
         char charIn = getC();

         // Comparaison
         bool isCorrect = (charGenerated == charIn);
         countCorrect  += isCorrect;
      }

      // Arrêt du chrono
      time_t endChrono = time(NULL);

      // Affichage réponses correcetes
      cout << endl << RESULT_MSG << countCorrect << endl;

      // Calculs et Affichage des temps
      time_t totalTime = endChrono - startChrono;
      cout << TIME_SPENT << totalTime << UNIT_OF_TIME << endl;

      double averageTime = double(totalTime) / nbrChar;
      cout << "==> " << averageTime << RATIO << endl;

      // Recommencer ?
      doAgain = tryAgain(TRY_AGAIN_MSG, ERROR_MSG);

   } while(doAgain);

   // Fin du programme
   cout << endl << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}