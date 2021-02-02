% // ---------------- DEBUT EN TETE --------------------------------------//
%    NOM :    Problème 2 :  
% //                                                                      //
%    AUTEURS : Pacome Léna Anaëlle Vincent Baptiste Yassir                                                    
% //                                                                      //
%    VERSION :    2.0 le 06/12/20                                                     
% //                  Création en Matlab                                  //
% // ENTREE :         y       tableau                                             //            
%    SORTIES :        y2      tableau
%                      
%
%   MODIFIEES :                                                          
% //                                                                      //
%    LOCALES :         0                                                   
% //                                                                      //
% //                                                                      //
%    FONCTIONS APPELEES :
%    autocorr            calcul autocorrelation
%                                                                      
%    ALGO - REFERENCES : Moodle, fichier Open_dat                                          
% //                                                                      //
% // ---------------- FIN EN TETE ----------------------------------------//

function [y2] = fonctionautocorrelation(y);

y2 = autocorr(y,'NumLags',length(y)-1);
plot(y2)
end