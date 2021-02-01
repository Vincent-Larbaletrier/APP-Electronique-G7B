/* Temps de réaction à un signal lumineux */

void temps_de_reaction_lumiere() 
{
  /* Delai aléatoire */
  delay((rand() % delay_max) + delay_min);

  /* Sauvegarde de l'horodatage en ms à l'allumage de la led */
  unsigned long t = millis();

  /* Taille du texte affiché sur l'écran oled */
  char AffichageReactionLumiere[100];

  /* On allume la led et on attend que le patient appuis sur le bouton */
  digitalWrite(LED_PIN, eclairement);    // Led allumée
  while (digitalRead(SELECT_BUTTON)); // Attente de l'appui sur le bouton
  digitalWrite(LED_PIN, LOW);     // Led éteinte
  byte reaction = millis() - t;

  /* Affichage du résultat */
  Serial.print("Temps de réaction : ");
  Serial.print(reaction); // affiche à l'écran la différence entre le temps écouler entre le début du programme et maintenant et le temps écouler entre le début du programme et l'allumage de la led
  Serial.print("ms");

  /* Interprétation des résultats */
  if (reaction < 200) {
    Serial.println("   -> temps de réaction inférieur à la moyenne");
  }
  else if (200 <= reaction <= 250) {
    Serial.println("   -> temps de réaction dans la moyenne");
  }
  else if (reaction > 250) {
    Serial.println("   -> temps de réaction supérieur à la moyenne");
  }

  /* Affichage des résultats sur l'écran*/
  sprintf(AffichageReactionLumiere, "Temps de reaction : %d ms", reaction);
  Fill(0);
  DisplayString(0, 0, "Resultats du test : ");
  DisplayString(0, 3, AffichageReactionLumiere);

  /* Interprétation des résultats */
  if (reaction < 200) {
    DisplayString(0, 5, "Temps de reaction inferieur a la moyenne");
  }
  else if (200 <= reaction <= 250) {
    DisplayString(0, 5, "Temps de reaction dans la moyenne");
  }
  else if (reaction > 250) {
    DisplayString(0, 5, "Temps de reaction superieur a la moyenne");
  }
}
