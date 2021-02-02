% // ---------------- DEBUT EN TETE --------------------------------------//
%    NOM :    Problème 2 :  
% //                                                                      //
%    AUTEURS : Pacome Léna Anaëlle Vincent Baptiste Yassir                                                    
% //                                                                      //
%    VERSION :    2.0 le 06/12/20                                                     
% //                  Création en Matlab                                  //
% // ENTREE :         filenumber    str                                   //            
%    SORTIES :        filename1     str
%                      
%
%   MODIFIEES :                                                         
% //                                                                      //
%    LOCALES :         filenumber                                                   
% //                                                                      //
% //                                                                      //
%    FONCTIONS APPELEES :
%    Open_dat permet d'ouvrir le fichier
%                                                                      
%    ALGO - REFERENCES : 


%
% //                                                                      //
% // ---------------- FIN EN TETE ----------------------------------------//
function [filename1, y] = fonctionidfichier();
filenumber = input('entrez le numéro du fichier entreles guillemets : '' \n');

filename1 = (filenumber+".dat");
filename1

[y,Fe] = Open_dat(filename1);
plot(y)

