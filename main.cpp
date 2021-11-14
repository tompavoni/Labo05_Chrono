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
#include <cstdlib>
#include <iostream>
#include <limits>
#include <ctime>

#include "fonction.h"

using namespace std;

int main() {

   // Début du programme
   cout << "Ce programme vous permet de tester votre dactylographie. Pour " << endl
        << "ceci vous devrez tout d'abord saisir le nombre de caractères "  << endl
        << "que vous voulez afficher. Ensuite une lettre sera générée "     << endl
        << "aléatoirement et vous devrez la copier le plus vite possible. " << endl
        << "Lorsque vous avez atteint la quantité de caratères définie, "   << endl
        << "le temps total et le temps moyen par caractère vous seront "    << endl
        << "affichés. Pour finir vous aurez la possibilité de recommenecer "<< endl
        << "ou non." << endl;

   //------------------------------------------------------------
   // Boucle pour recommencer la partie
   bool doAgain = 0;
   do {
      // Saisie du nombre de caractères à afficher
      const unsigned MIN   = 0;
      const unsigned MAX   = 9999;
      unsigned int nbrChar = getInt(MIN,MAX);

      // Démarrage du chrono
      time_t startChrono = time(NULL);

      // Affichage et comparaison des caractères
      unsigned countCorrect = 0;
      for (unsigned i = 1; i <= nbrChar; i++) {

         // Affichage du caractère généré aléatoirement
         char charGenerated = charGenerator(intGenerator1_26);
         cout << "Lettre : " << charGenerated << " : ";

         // Saisie du caractère entré par l'utilisateur
         char charIn = getC();

         // Comparaison
         bool isCorrect = (charGenerated == charIn);
         countCorrect  += isCorrect;
      }

      // Arrêt du chrono
      time_t endChrono = time(NULL);

      // Affichage réponses correcetes
      cout << endl << "Nombre de réponses correctes : " << countCorrect << endl;

      // Calculs et Affichage des temps
      time_t totalTime = endChrono - startChrono;
      cout << "Temps écoulé : " << totalTime << " sec " << endl;
      double averageTime = totalTime / nbrChar;
      cout << "==> " << averageTime << " sec par lettre" << endl;

      // Recommencer ?
      cout << endl << "Voulez-vous recommencer [Y/n] : ";
      doAgain = tryAgain();
   } while(doAgain);

   //------------------------------------------------------------
   // Fin du programme
   cout << "\npresser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider le buffer
   return EXIT_SUCCESS;
}
