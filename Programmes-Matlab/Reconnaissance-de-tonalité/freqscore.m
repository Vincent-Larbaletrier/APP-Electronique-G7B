%{
---------------- DEBUT EN TETE --------------------------------------//
// NOM :                    analyseFFT()                           
//                                                                      //
// AUTEURS : G7B                                                        //
//                                                                      //
// VERSION :    1.1         Pacome Le Bris              janvier 2020    //
// 
   Calcule le pourcentage de ressemblance entre les fréquences des signaux 
               signalSinusoidal et SignalUtilisateur

// HISTORIQUE : Aucun                                                   //
//                                                                      //
// ENTREES : 

frequencefftSin : fréquence calculée par fft de signalSinusoidal

frequencefftUti	: fréquence calculée par fft de signalUtilisateur
			                          
//	 	                                                                       												 //
// SORTIES :

   frequencescore : pourcentage de similitude des fréquences entre 
                     signalSinusoidal et signalUtilisateur
//		                                                                                                                                             //
// MODIFIEES :                                                          //
//                                                                      //
// LOCALES : 
                                                           
//	
//                                                                      //
// FONCTIONS APPELEES :   
                                           
//                                                                      //
// ALGO - REFERENCES :                                                  //
//                                                                      //
// ---------------- FIN EN TETE ----------------------------------------//
%}

function [frequencescore] = freqscore(frequencefftSin,frequencefftUti)

frequencescore = (min(frequencefftSin, frequencefftUti)/max(frequencefftSin, frequencefftUti))*100;
disp(['le score de reproduction est de ' num2str(frequencescore) '%']);
end



