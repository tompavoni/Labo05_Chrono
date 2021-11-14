//
// Created by tomas on 10.11.2021.
//
#include <cstdlib>
#include <iostream>
#include <string>

#ifndef LABO05_CHRONO_FONCTION_H
#define LABO05_CHRONO_FONCTION_H

using namespace std;
const           string MSG_ERROR = "/!\\ erreur de saisie ..."s;

//***********************************************************************************
// nom         getInt
// but         fonction de saisie d'un entier (long int) non signé pour contrôlé
//             la saisie.
// param       Reçoit en paramètre les valeur MAX et MIN.
// return      valeur saisie dans la fonction
// exception   n/a
//***********************************************************************************
unsigned int getInt(const unsigned MIN, const unsigned MAX);

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
// nom         intGenerator
// but         Fonction qui génère un entier aléatoire.
// param       Aucun
// return      Un entier
// exception   n/a
//***********************************************************************************
int intGenerator1_26();

//***********************************************************************************
// nom         getC
// but         Fonction de saisie de caratère qui contrôle la saisie.
// param       Reçoit les valeur de MIN_CHAR et MAX_CHAR
// return      Un char
// exception   n/a
//***********************************************************************************
char getC(const char MIN_CHAR, const char MAX_CHAR);


//***********************************************************************************
// nom         tryAgain
// but         Fonction qui permet de retourner un booléen.
// param       Aucun
// return      Un booléen
// exception   n/a
//***********************************************************************************
bool tryAgain();

#endif //LABO05_CHRONO_FONCTION_H