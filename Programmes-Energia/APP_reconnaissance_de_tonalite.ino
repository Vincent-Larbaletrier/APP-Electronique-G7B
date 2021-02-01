/* Reconnaissance de tonalité */

void reconnaissance_de_tonalite() 
{
  delay(2000);

  /* Taille du texte affiché sur l'écran oled */
  char AffichageTonalite[100];
  
  /* Sauvegarde de l'horodatage en ms */
  unsigned long time = millis();
  do{
    int tension = analogRead(micro);
    if (tension == 4095 && tensionprecedente != 4095){
      nbsat += 1;
    }
    tension = tensionprecedente;
 
    delay(1);
  } while (time < 1000);
  float resultat = nbsat * 1.2;

  /* Affichage moniteur */
  Serial.println(resultat);

  /* Affichage écran */
  sprintf(AffichageTonalite, " %d ", resultat);
  Fill(0);
  DisplayString(0, 0, "Resultats du test : ");
  DisplayString(0, 3, AffichageTonalite);
}
