%{
// ---------------- DEBUT EN TETE --------------------------------------//
// NOM :                    Probleme 4 signal                           //
//                                                                      //
// AUTEURS : G7B                                                        //
//                                                                      //
// VERSION :    1.1         Pacome Le Bris              janvier 2020    //
//                   
// HISTORIQUE : Aucun                                                   //
//                                                                      //
// ENTREES :  				                          
//	 	                                                                       //												 //
// SORTIES :                                                            //
//		                                                                       //                                                                      //
// MODIFIEES :                                                          //
//                                                                      //
// LOCALES :                                                            //
//	
//                                                                      //
// FONCTIONS APPELEES : 
   
   generationsignal() : génére un signal sonore sinusoïdal puis carré 
   correspondant à une note de musique de la gamme à tempérament égal, dans
   les octaves 2 à 6. 

   generationSignalRecu() : simule la réception d’un signal sonore 
   sinusoïdal bruité et d’amplitude variable, dont la durée est d’au 
   moins 2 secondes et dont le début est aussi aléatoire 
   Il s’agit du signal reproduit par l’utilisateur.

   analyseFFT(): opère une transformation de fourier sur les differents 
   signaux pour determiner leur fréquence.
 
   
                                           
//                                                                      //
// ALGO - REFERENCES :                                                  //
//                                                                      //
// ---------------- FIN EN TETE ----------------------------------------//
%}

[signalSinusoidal,signalCarre,freqAleatoire] = generationsignal();

[signalUtilisateur] = generationSignalRecu(freqAleatoire);

[signalSinusoidalF,signalUtilisateurF] = filtres(signalSinusoidal,signalUtilisateur);

[frequencefftSin,frequencefftUti] = analyseFFT(signalSinusoidalF,signalUtilisateurF);

[frequencescore] = freqscore(frequencefftSin,frequencefftUti);






