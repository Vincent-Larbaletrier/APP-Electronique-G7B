% // ---------------- DEBUT EN TETE --------------------------------------//
%    NOM :    Problème 2 :  
% //                                                                      //
%    AUTEURS : Pacome Léna Anaëlle Vincent Baptiste Yassir                                                    
% //                                                                      //
%    VERSION :    2.0 le 06/12/20                                                     
% //                  Création en Matlab                                  //
% // ENTREE :         y2       tableau                                    //            
%    SORTIES :        locs      liste
%                     

%                      
%
%   MODIFIEES :                                                          
% //                                                                      //
%    LOCALES :         x       liste
%                      TF      liste
%                      pks     liste
% //                                                                      //
% //                                                                      //
%    FONCTIONS APPELEES :
%    isolocalmax            trouve et les maximums
%    findpeaks              recupere les valeurs et indexs de chaque max 
%                                                                      
%    ALGO - REFERENCES :                                           
% //                                                                      //
% // ---------------- FIN EN TETE ----------------------------------------//

function [locs] = fonctionmaximums(y2);

x = 1:length(y2);
TF = islocalmax(y2,'MinSeparation',250,'SamplePoints',x);
plot(x,y2,x(TF),y2(TF),'r*')

[pks,locs] = findpeaks(y2,'MinPeakDistance',250);
end


