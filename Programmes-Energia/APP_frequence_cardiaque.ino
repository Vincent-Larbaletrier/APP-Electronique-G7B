/* Fréquence cardiaque */

void frequence_cardiaque() 
{

  /* Taille du texte affiché sur l'écran oled */
  char AffichageFrequenceCardiaque[100];
  
  /* Initialisation de la sauvegarde de l'horodatage en ms */
  unsigned long tempsDetection; 

  /* Lecture de la valeur envoyé par le capteur*/
  valeurActuelle = analogRead(cardiac_sensor);

  /* Détermination de la fréquence cardiaque */
  if (valeurActuelle > valeurSeuil) {  
    if (valeurPrecedente <= valeurSeuil) {  
      tempsDetection = millis(); // sauvegarde de l'horodatage en ms
      if (tempsDetection > (tempsPrecedent + 400)){
        int bpm = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent);
        if ((bpm > 40) && (bpm < 140)) { // correspondance au cahier des charges 
          /* Affichage moniteur */
          Serial.print("La fréquence cardiaque est de : ");
          Serial.print(bpm);
          Serial.println(" bpm ");

          /* Affichage écran */
          if (compteur2 == 0) {
            Fill(0);
            compteur2 = 1;
          } 
          int x = 64;
          sprintf(AffichageFrequenceCardiaque, " %d ", bpm);
          DisplayString(0, 0, "Resultats du test : ");
          DisplayString(0, 3, "Fréquence cardiaque (en bpm) : ");
          clearLine(4, 0);
          DisplayString(x, 4, AffichageFrequenceCardiaque);    
          tempsPrecedent = tempsDetection;
        }
      }
    }
    valeurPrecedente = valeurActuelle;
  }
}
  
