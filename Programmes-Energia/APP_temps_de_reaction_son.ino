/* Temps de réaction à un signal sonore */

void temps_de_reaction_son() {
  
  /* Delai aléatoire */
  delay((rand() % delay_max) + delay_min);
   
  /* Sauvegarde du timestamp en ms au moment où le son est envoyé dans le casque */
  unsigned long t = millis();

    /* Taille du texte affiché sur l'écran oled */
  char AffichageReactionSon[100];
   
  /* On envoie un son et on attend que le patient appuis sur le bouton */
  tone(casque, frequence);   // Envoi du son de la frequence choisie
  while(digitalRead(SELECT_BUTTON)); // Attente de l'appui sur le bouton
  noTone(casque);     // On cesse d'envoyer le son
  int reaction = millis() - t;
    
  /* Affichage du résultat */
  Serial.print("Temps de réaction : ");
  Serial.print(reaction); // affiche à l'écran la différence entre le temps écouler entre le début du programme et maintenant et le temps écouler entre le début du programme et l'envoi du son
  Serial.print("ms");

  /* Interprétation des résultats */
  if (reaction < 160) {
    Serial.println("   -> temps de réaction inférieur à la moyenne");
  }
  else if (160 <= reaction <= 210) {
    Serial.println("   -> temps de réaction dans la moyenne");
  }
  else if (reaction > 210) {
    Serial.println("   -> temps de réaction supérieur à la moyenne");
  }

  /* Affichage des résultats sur l'écran*/
  sprintf(AffichageReactionSon, "Temps de reaction : %d ms", reaction);
  Fill(0);
  DisplayString(0, 0, "Resultats du test : ");
  DisplayString(0, 3, AffichageReactionSon);

  /* Interprétation des résultats */
  if (reaction < 160) {
    DisplayString(0, 5, "Temps de reaction inferieur a la moyenne");
  }
  else if (160 <= reaction <= 210) {
    DisplayString(0, 5, "Temps de reaction dans la moyenne");
  }
  else if (reaction > 210) {
    DisplayString(0, 5, "Temps de reaction superieur a la moyenne");
  }
}
