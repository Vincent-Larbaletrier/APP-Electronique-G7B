%{
// ---------------- DEBUT EN TETE --------------------------------------//
// NOM :                    generationsignal()                           //
//                                                                      //
// AUTEURS : G7B                                                        //
//                                                                      //
// VERSION :    1.1         Pacome Le Bris              janvier 2020    //
// 
   génère un signal sonore sinusoïdal puis carré 
   correspondant à une note de musique de la gamme à tempérament égal,
   dans les octaves 2 à 6.               

// HISTORIQUE : Aucun                                                   //
//                                                                      //
// ENTREES :  				                          
//	 	                                                                       												 //
// SORTIES :

   signalSinusoidal : Signal Sinusoidal correspondant à la note de musique 
                      jouée
   freqAleatoire : frequence du signal sinusoidal et du signal carre 
                   générés
   signalCarre : Signal carré
//		                                                                                                                                             //
// MODIFIEES :                                                          //
//                                                                      //
// LOCALES : 
                                                           
   freq,frecOctave,nouvfreq
//	
//                                                                      //
// FONCTIONS APPELEES :   
                                           
//                                                                      //
// ALGO - REFERENCES :                                                  //
//                                                                      //
// ---------------- FIN EN TETE ----------------------------------------//
%}




function [signalSinusoidal,signalCarre,freqAleatoire] = generationsignal()

%calcul des fréquences des notes de musique des octaves 2 à 6 
freq = 130.81;
freqOctave = [freq];

for i = 1 : +1 : 59
    nouvfreq = freq*(2^(1/12));
    freqOctave(end+1) = nouvfreq;
    freq = nouvfreq;
end


%choix Aléatoire d'une fréquence entre les octaves 2 à 6 
nb= randi(60,1);
freqAleatoire = freqOctave(nb);


%géneration signal sinusoidal
fe= 16000;
N= 32000;
t= (1:N)/fe;


signalSinusoidal = sin(2*pi*freqAleatoire*t);
disp(['La frequence du signal genere est : ' num2str(freqAleatoire) 'Hz']);
%figure(1);
%plot (t,signalSinusoidal);


% Generation du signal carré
signalCarre = square((2*pi*freqAleatoire)*t);
%figure(2);
%plot(t,signalCarre);

end


