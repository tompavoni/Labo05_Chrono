/*
  ---------------------------------------------------------------------------
  Fichier     : fonction.h

  Auteur(s)   : Alexandre Delétraz et Tomas Pavoni
  Date        : 12.11.2021
  But         : Déclarer les fonctions utilisées dans le fichier "fonction.cpp"

  Remarque(s) : à compléter

  Compilateur : gcc version 8.2.0
  ---------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <string>

#ifndef LABO05_CHRONO_FONCTION_H
#define LABO05_CHRONO_FONCTION_H

using namespace std;

//***********************************************************************************
// nom         getIntAndVerify
// but         - Saisir un entier
//             - Vérifier s'il est compris entre MIN et MAX
//
// param       - MIN       : borne inférieure
//             - MAX       : borne supérieure
//             - USAGE_MSG : message de saise
//             - ERROR_MSG : message d'erreur
//
// return      - L'entier saisi
// exception   n/a
//***********************************************************************************
int getIntAndVerify(const int MIN, const int MAX, const string& USAGE_MSG = "",
                    const string& ERROR_MSG = "");

//***********************************************************************************
// nom         letterGenerator
// but         - Générer une lettre aléatoire
//
// param       - Aucun
//
// return      - Une lettre aléatoire
// exception   n/a
//***********************************************************************************
char letterGenerator();

//***********************************************************************************
// nom         getC
// but         - Saisir un caractère
//
// param       - Aucun
//
// return      - Le caractère saisi
// exception   n/a
//***********************************************************************************
char getC();

//***********************************************************************************
// nom         tryAgain
// but         - Demander si l'utilisateur souhaite recommencer
//
// param       - USAGE_MSG : message de saisie
//             - ERROR_MSG : message d'erreur
//
// return      - Un booléen : 1 pour recommencer et 0 pour arrêter
// exception   n/a
//***********************************************************************************
bool tryAgain(const string USAGE_MSG = "", const string& ERROR_MSG = "");


#endif //LABO05_CHRONO_FONCTION_H
