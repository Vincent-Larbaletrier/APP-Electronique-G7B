%{
// ---------------- DEBUT EN TETE --------------------------------------//
// NOM :                    generationSignalRecutest()                           //
//                                                                      //
// AUTEURS : G7B                                                        //
//                                                                      //
// VERSION :    1.1         Pacome Le Bris              janvier 2020    //
// 
   simule la réception d’un signal sonore 
   sinusoïdal bruité et d’amplitude variable, dont la durée est d’au 
   moins 2 secondes et dont le début est aussi aléatoire 
   Il s’agit du signal reproduit par l’utilisateur.               

// HISTORIQUE : Aucun                                                   //
//                                                                      //
// ENTREES : 
            
    freqAléatoire : fréquence de la note de musique jouée
    (Signal Sinusoidal)
//	 	                                                                       												 //
// SORTIES :

   signalUtilisateur : signal correspondant au signal "recu"
                      (simulation du signal émis par l'utilisateur)
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




function[signalUtilisateur] = generationSignalRecutest(freqAleatoire)

freqAleatoire = 318;
%generation signal recu

fe= 16000;
N= 32000;
t= (1:N)/fe;

% Simulation aléatoire de la variation fréquentielle du signal "recu"
freq10m=round(freqAleatoire/(2^(1/12)));
freq10p=round(freqAleatoire*(2^(1/12)));
pourcentageVar=randi([-10,10],1);

frequenceEmise= randi([freq10m, freq10p],1);
freqUtilisateur= freqAleatoire + 0.01*pourcentageVar*frequenceEmise;

%Simulation d'un bruit blanc gaussien sur le signal "recu"
sigma= 0.15;
moy = 0;
bruit = moy + sigma*randn(1,N);

%Amplitude aléatoire (1 à 5)
amplitude = randi([1,5],1);

%decalage temporel pour début aleatoire
decalage = (randi([1,1000],1))/1000;


%génération du signal "recu"
signalUtilisateur = amplitude*sin(2*pi*freqUtilisateur*(t+decalage))+bruit;
figure(3);
plot(t,signalUtilisateur);

%disp(freqAleatoire);
disp(['freq signal recu (réelle)' num2str(freqUtilisateur) 'Hz']);

end





