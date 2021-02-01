/* Programme principale */

#include <stdlib.h> // on importe les fonctions srand() et rand() qui nous permettent de générer des nombres aléatoirement
#include "APP_logo.h"

/* Déclaration des variables */
int pvalues = 0; // valeurs du potentiomètre
int buttonState = 0; // état du bouton
int curseur = 3; // position curseur ">"
int page = 1; // page par défaut
int compteur = 0; // compteur pour actualiser l'écran
int compteur2 = 0; // second compteur pour actualiser l'écran
const int frequence = 440; // fréquence du son envoyé dans le casque (440 Hz ou 1760 Hz pour correspondre aux critères du cahier des charges)
const int eclairement = 73; // éclairage lumineux de la led
/*  valeur comprise entre 0 et 255 et qui correspond à la valeur en lux imposée par le cahier des charges
    On suppose ici que la valeur 255 correspond à un éclairage lumineux de 2100 lux
    Comme on utilise la led ROUGE, on veux un éclairage lumineux de 600 lux
*/

/* L'écran est organisé en 8 banques de 128 octets. Les 3 options seront donc affichées sur les lignes 4, 6 et 8.
Le MENU est incrémenté de 2 en 2 (il y a 3 menus) et les SOUS MENUS sont incrémentés de 2 en 2 (2 sous menus pour chaque menu + option retour) */

/* Déclaration du bouton de sélection et du système de navigation */
int SELECT_BUTTON = PA_4; // bouton de sélection
const int potentiometre = 29; // potentiomètre

/* Déclaration des broches pour le capteur de température */
const int temperature_sensor = PD_1; // capteur de temperature

/* Déclaration des broches pour la fréquence cardiaque */
int valeurPrecedente = 0; 
long tempsPrecedent = 0;
int valeurActuelle;
int valeurSeuil = 3200; // initialisation de la valeur seuil à 3200
const int cardiac_sensor = A0; // capteur de fréquence cardiaque

/* Déclaration des broches pour la reconnaissance de tonalité */
int nbsat = 0;
int tensionprecedente = 0;
const int micro = PD_0; // micro

/* Déclaration des variables pour le seuil de perception */
int frequence_seuil_min;
int frequence_seuil_max;

/* Déclaration des broches pour temps de réaction */
const byte LED_PIN = RED_LED;  // led
const byte casque = PB_2;  // casque

/* Initialisation d'un délai minimum et maximum */
const unsigned long delay_min = 3000; // delai minimum = 3sec
const unsigned long delay_max = 7000; // delai maximum = 7sec

void setup() {
  /* Initialisation */
  Serial.begin(9600);
  /* Ecran oled */
  InitI2C();
  InitScreen();
  Fill(0);
  Display(logo);
  /* PIN */
  pinMode(SELECT_BUTTON, INPUT); // initialisation du bouton
  pinMode(LED_PIN, OUTPUT); // initialisation led
  digitalWrite(LED_PIN, LOW);

  /* Initialisation du générateur de nombres aléatoire */
  srand(analogRead(A0)); 

  delay(5000);
  //Fill(0);
}
void loop() {

/* Affichage du MENU */
  if (page == 1) {  
    if (compteur == 0) {
      Fill(0);
      compteur = 1;
    } 
    DisplayString(0,0,"MENU de selection");
    DisplayString(10,3,"1. Troubles auditifs"); // Quantifier troubles auditifs
    DisplayString(10,5,"2. Niveau de stress"); // Mesure du niveau de stress
    DisplayString(10,7,"3. Reflexes"); // Mesure des réflexes
    DisplayString(3,curseur,">");
    deplacementcurseur();
  }

  OK();

/* Affichage du SOUS MENU 1. */
  if (page == 11) {
    if (compteur == 0) {
      Fill(0);
      compteur = 1;
    }
    DisplayString(0,0,"1. Troubles auditifs");
    DisplayString(10,3,"1.1. Reconnaissance tonalite"); // Reconnaissance de tonalité
    DisplayString(10,5,"1.2. Seuil perception"); // Fréquence seuil de perception
    DisplayString(10,7,"retour");
    DisplayString(3,curseur,">");
    deplacementcurseur();
  }

/* Affichage du SOUS MENU 2. */
  if (page == 12) {
    if (compteur == 0) {
      Fill(0);
      compteur = 1;
    }
    DisplayString(0,0,"2. Niveau de stress");
    DisplayString(10,3,"2.1. Temperature peau"); // Température de la peau
    DisplayString(10,5,"2.2. Frequence cardiaque"); // Fréquence cardiaque
    DisplayString(10,7,"retour");
    DisplayString(3,curseur,">");
    deplacementcurseur();
  }

/* Affichage du SOUS MENU 3. */
  if (page == 13) {
    if (compteur == 0) {
      Fill(0);
      compteur = 1;
    }  
    DisplayString(0,0,"3. Reflexes");
    DisplayString(10,3,"3.1. Reaction lumiere"); // Temps de réaction à un signal lumineux
    DisplayString(10,5,"3.2. Reaction son"); // Temps de réaction à un signal sonore
    DisplayString(10,7,"retour");
    DisplayString(3,curseur,">");
    deplacementcurseur();
  }

  OK();

}

/* Fonction de déplacement du curseur */ 
void deplacementcurseur()
{
  int curseurbis = curseur;
  pvalues = analogRead(potentiometre); // valeurs comprises entre 0 et 4095
  if (pvalues <= 1000) {
    curseur = 3;
  }
  else if (2000 <= pvalues) {
    curseur = 7;
  }
  else {
    curseur = 5;
  }
  if (curseurbis != curseur) {
    clearLine(curseurbis, 0);
    clearLine(curseur, 0);
  }
}

/* Fonction de sélection */
void OK() 
{
  buttonState = digitalRead(SELECT_BUTTON); // état haut ou état bas
  unsigned long duree_programme = millis();
  if (page == 1) {
    if (buttonState == 1 && curseur == 3) {
      /* Ouvre le SOUS MENU 1. */
      page = 11;
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 5) {
      /* Ouvre le SOUS MENU 2. */
      page = 12;
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 7) {
      /* Ouvre le SOUS MENU 3. */
      page = 13;
      compteur = 0;
      compteur2 = 0;
    }
  }
  else if (page == 11) {
    if (buttonState == 1 && curseur == 3) {
      decompte();
/* Lance le programme reconnaissance de tonalité */
      reconnaissance_de_tonalite();
      delay(20000); // délai après la fin de l'exécution programme
      page = 1; // on revient au MENU
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 5) {
      decompte();
/* Lance le programme fréquence seuil de perception */
      seuil_perception();
      delay(20000); // délai après la fin de l'exécution programme
      page = 1; // on revient au MENU
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 7) {
/* Retour au MENU */
      page = 1;
      compteur = 0;
      compteur2 = 0;
    }    
  }
  else if (page == 12) {
    if (buttonState == 1 && curseur == 3) {
      decompte();
/* Lance le programme température de la peau */
      while(digitalRead(SELECT_BUTTON) == HIGH) {
      /* Arrête le programme lorsque l'on appuis sur le bouton */
          temperature();
      }
      delay(20000); // délai après la fin de l'exécution programme
      page = 1; // on revient au MENU
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 5) {
      decompte();
/* Lance le programme fréquence cardiaque */
      while(digitalRead(SELECT_BUTTON) == HIGH) {
      /* Arrête le programme lorsque l'on appuis sur le bouton */
          frequence_cardiaque();
      }
      delay(20000); // délai après la fin de l'exécution programme
      page = 1; // on revient au MENU
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 7) {
/* Retour au MENU */
      page = 1;
      compteur = 0;
      compteur2 = 0;
    }    
  }
  else if (page == 13) {
    if (buttonState == 1 && curseur == 3) {
      decompte();
/* Lance le programme temps de réaction à un signal lumineux */
      temps_de_reaction_lumiere();
      delay(20000); // délai après la fin de l'exécution programme
      page = 1; // on revient au MENU
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 5) {
      decompte();
/* Lance le programme temps de réaction à un signal sonore */
      temps_de_reaction_son();
      delay(20000); // délai après la fin de l'exécution programme
      page = 1; // on revient au MENU
      compteur = 0;
      compteur2 = 0;
    }
    else if (buttonState == 1 && curseur == 7) {
/* Retour au MENU */
      page = 1;
      compteur = 0;
      compteur2 = 0;
    }    
  }
}

void decompte()
{
      Fill(0);
      DisplayString(0, 1, "Le programme commence dans : ");
      DisplayString(60, 4, "3");
      delay(1000);
      clearLine(4, 0);
      DisplayString(60, 4, "2");
      delay(1000);
      clearLine(4, 0);
      DisplayString(60, 4, "1");
      delay(1000);
      clearLine(4, 0);
      DisplayString(60, 4, "En cours...");
}
