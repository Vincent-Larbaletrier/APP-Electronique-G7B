%{
// ---------------- DEBUT EN TETE --------------------------------------//
// NOM :                    analyseFFT()                           
//                                                                      //
// AUTEURS : G7B                                                        //
//                                                                      //
// VERSION :    1.1         Pacome Le Bris              janvier 2020    //
// 
   opère une transformation de fourier sur les differents 
   signaux pour determiner leur fréquence.               

// HISTORIQUE : Aucun                                                   //
//                                                                      //
// ENTREES : 
signalSinusoidal : Signal Sinusoidal correspondant à la note 
                                de musique jouée 

signalUtilisateur : signal correspondant au signal "recu"
                    (simulation du signal émis par l'utilisateur)				                          
//	 	                                                                       												 //
// SORTIES :

   frequencefftSin : fréquence mesurée par fft du SignalSinusoidal
 
   frequencefftUti : fréquence mesurée par fft du SignalUtilisateur
//		                                                                                                                                             //
// MODIFIEES :                                                          //
//                                                                      //
// LOCALES : 
                                                           
   Y,P1,P2
//	
//                                                                      //
// FONCTIONS APPELEES :   
                                           
//                                                                      //
// ALGO - REFERENCES :                                                  //
//                                                                      //
// ---------------- FIN EN TETE ----------------------------------------//
%}


function [frequencefftSin,frequencefftUti] = analyseFFT(signalSinusoidalF,signalUtilisateurF)

%paramètres : fréquence d'échantillonage 16 KHz durée 2s
Fs =16000;
T=1/Fs;
L = 32000;
t = (0: L-1) * T;

%calcul de la transformée de fourier du SignalSinusoidal
Y = fft(signalSinusoidalF);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;

%figure(4);
%plot(f,P1); 

%determination du maximum et de la fréquence (abscisse du maximum de la fft)
[m, i] = max(P1);
frequencefftSin = i/2;


%-------------------------------------------

%paramètres : fréquence d'échantillonage 16 KHz durée 2s
Fs =16000;
T=1/Fs;
L = 32000;
t = (0: L-1) * T;

%calcul de la transformée de fourier du SignalUtilisateur
Y = fft(signalUtilisateurF);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;

%figure(5);
%plot(f,P1); 

%determination du maximum et de la fréquence (abscisse du maximum de la fft)
[m, i] = max(P1);
frequencefftUti = i/2;

disp(['La frequence du signal emis mesuree est : ' num2str(frequencefftSin) 'Hz']);
disp(['La frequence du signal recu mesuree est : ' num2str(frequencefftUti) 'Hz']);

end



