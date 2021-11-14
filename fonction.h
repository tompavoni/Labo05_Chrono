//
// Created by tomas on 10.11.2021.
//
#include <cstdlib>
#include <iostream>
#include <string>

#ifndef LABO05_CHRONO_FONCTION_H
#define LABO05_CHRONO_FONCTION_H

using namespace std;


//***********************************************************************************
// nom         getInt
// but         fonction de saisie d'un entier (long int) non signé pour contrôlé
//             la saisie.
// param       Reçoit en paramètre les valeur MAX et MIN ainsi que des string pour
//             l'utilisateur.
// return      valeur saisie dans la fonction
// exception   n/a
//***********************************************************************************
int getInt(const int MIN, const int MAX, const string& USAGE_MSG = "",
           const string& CONJUNCTION_MSG = "", const string& ERROR_MSG = "");


//***********************************************************************************
// nom         intGenerator
// but         Fonction qui génère un entier aléatoire.
// param       Aucun
// return      Un entier
// exception   n/a
//***********************************************************************************
int intGenerator1_26();


//***********************************************************************************
// nom         charGenerator
// but         Fonction qui génère un caractère aléatoire.
// param       Une valeur numérique générée aléatoirement par la fonction
//             intGenerator.
// return      Un caractère
// exception   n/a
//***********************************************************************************
char charGenerator(int rand1_26);


//***********************************************************************************
// nom         getC
// but         Fonction de saisie de caratère qui contrôle la saisie.
// param       Reçoit les valeur de MIN_CHAR et MAX_CHAR et des string pour
//             l'utilisateur.
// return      Un char
// exception   n/a
//***********************************************************************************
char getC(const char MIN_CHAR, const char MAX_CHAR);


//***********************************************************************************
// nom         tryAgain
// but         Fonction qui permet de retourner un booléen.
// param       Des string qui serviront de message pour l'utilisateur
// return      Un booléen
// exception   n/a
//***********************************************************************************
bool tryAgain(const string& USAGE_MSG = "", const string& CONJUNCTION_MSG = "",
              const string& END_OF_MSG = "", const string& ERROR_MSG = "");


//***********************************************************************************
// nom         timeElapse
// but         Fonction qui permet compter le temps passé.
// param       Aucun
// return      Un entier
// exception   n/a
//***********************************************************************************
double timeElapse();

#endif //LABO05_CHRONO_FONCTION_H
