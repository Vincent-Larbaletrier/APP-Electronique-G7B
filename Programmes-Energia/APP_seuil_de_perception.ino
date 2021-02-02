/* Seuil de perception */

void seuil_perception() 
{
  delay(1000);
  
  /* Taille du texte affiché sur l'écran oled */
  char AffichageSeuilMin[100];
  char AffichageSeuilMax[100];

  /* Détection des seuils */
  while(digitalRead(SELECT_BUTTON)) {
    for (int i = 400; i >= 20; i--) { // précision de 1 Hz
      tone(casque, i);
      frequence_seuil_min = i;
    }  
  }
  noTone(casque);
  
  delay(3000);
  
  while(digitalRead(SELECT_BUTTON)) {
    for (int j = 10000; j <= 20000; j += 10) { // précision de 10 Hz
      tone(casque, j);
      frequence_seuil_max = j;
    }  
  }
  noTone(casque);

  /* Affichage moniteur */
  Serial.print("Le seuil de perception auditif minimum est de ");
  Serial.print(frequence_seuil_min);
  Serial.println(" Hz ");

  Serial.print("Le seuil de perception auditif maximum est de ");
  Serial.print(frequence_seuil_max);
  Serial.println(" Hz ");

  /* Affichage écran */
  int x = 64;
  sprintf(AffichageSeuilMin, " %d Hz ", frequence_seuil_min);
  sprintf(AffichageSeuilMax, " %d Hz ", frequence_seuil_max);
  Fill(0);
  DisplayString(0, 0, "Resultats du test : ");
  DisplayString(0, 2, "Le seuil de perception minimum est de : ");
  DisplayString(x, 3, AffichageSeuilMin);
  DisplayString(0, 5, "Le seuil de perception maximum est de : ");
  DisplayString(x, 6, AffichageSeuilMax);
  

}
