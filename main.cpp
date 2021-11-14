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

   const string INT_MSG         = "veuillez enter une valeur entre "s;
   const string CONJUNCTION_MSG = " et "s;
   //const string CHAR_MSG        = " votre lettre "s;
   const string MSG_ERROR       = "/!\\ erreur de saisie"s;
   const string TRY_AGAIN_MSG   = "Voulez-vous recommencer ?"s;
   const char MIN_CHAR          = 'a';
   const char MAX_CHAR          = 'z';
   const int MIN                = 0;
   const int MAX                = 9999;


   // Début du programme
   cout << "Ce programme vous permet de tester votre dactylographie. Pour"  << endl
        << "ceci vous devrez tout d'abord saisir le nombre de caracteres"   << endl
        << "que vous voulez afficher. Ensuite une lettre sera generee"      << endl
        << "aleatoirement et vous devrez la copier le plus vite possible."  << endl
        << "Lorsque vous avez atteint la quantite de caratères definie,"    << endl
        << "le temps total et le temps moyen par caractere vous seront"     << endl
        << "affiches. Pour finir vous aurez la possibilite de recommenecer" << endl
        << "ou non."                                                        << endl;

   // Boucle pour recommencer la partie
   bool doAgain;
   do {
      // Saisie du nombre de caractères à afficher
      unsigned nbrChar = unsigned(getInt(MIN, MAX, INT_MSG , CONJUNCTION_MSG,
                                         MSG_ERROR));

      // Démarrage du chrono
      time_t startChrono = time(NULL); // timeElapse();

      // Affichage et comparaison des caractères
      unsigned countCorrect = 0;
      for (unsigned i = 1; i <= nbrChar; i++) {

         // Affichage du caractère généré aléatoirement
         char charGenerated = charGenerator(intGenerator1_26());
         cout << "Lettre : " << charGenerated << " : ";

         // Saisie du caractère entré par l'utilisateur
         char charIn = getC(MIN_CHAR, MAX_CHAR);

         // Comparaison
         bool isCorrect = (charGenerated == charIn);
         countCorrect  += isCorrect;
      }

      // Arrêt du chrono
      time_t endChrono = time(NULL); // double time = timeElapse();

      // Affichage réponses correcetes
      cout << endl << "Nombre de réponses correctes : " << countCorrect << endl;

      // Calculs et Affichage des temps
      time_t totalTime = endChrono - startChrono;
      cout << "Temps écoulé : " << totalTime << " sec " << endl;
      double averageTime = double(totalTime) / nbrChar;
      cout << "==> " << averageTime << " sec par lettre" << endl;


      // Recommencer ?
      cout << endl << "Voulez-vous recommencer [o/n] : ";
      doAgain = tryAgain(TRY_AGAIN_MSG, "",
                         "" , MSG_ERROR);
   } while(doAgain);

   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}