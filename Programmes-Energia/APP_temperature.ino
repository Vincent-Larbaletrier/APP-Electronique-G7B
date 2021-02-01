/* Température */

void temperature() 
{
  /* Taille du texte affiché sur l'écran oled */
  char AffichageTemperature[100];

  /* Calculs */
  int valeur_temp = analogRead(temperature_sensor); // relève la valeur mesurer par le capteur
  float temp = valeur_temp * (39.04/1000); // conversion en °C

  /* Affichage moniteur */
  Serial.print("La température est de : ");
  Serial.print(temp);
  Serial.println(" °C");

  /* Affichage écran */
  int x = 64;
  sprintf(AffichageTemperature, " %d ", temp);
  if (compteur2 == 0) {
    Fill(0);
    compteur2 = 1;
  } 
  DisplayString(0, 0, "Resultats du test : ");
  DisplayString(0, 3, "Temperature (en °C) : ");
  clearLine(4, 0);
  DisplayString(x, 4, AffichageTemperature);
  delay(100); 
}
