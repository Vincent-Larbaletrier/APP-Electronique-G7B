% // ---------------- DEBUT EN TETE --------------------------------------//
%    NOM :    Problème 2 :  
% //                                                                      //
%    AUTEURS : Pacome Léna Anaëlle Vincent Baptiste Yassir                                                    
% //                                                                      //
%    VERSION :    2.0 le 06/12/20                                                     
% //                  Création en Matlab                                  //
% // ENTREE :         auncune                                             //            
%    SORTIES :        filename
%                      bpm
%
%   MODIFIEES :        bpm                                                  
% //                                                                      //
%    LOCALES :         0                                                   
% //                                                                      //
% //                                                                      //
%    FONCTIONS APPELEES :
%    fonctionidfichier permet de choisir le fichier
%    
%                                                                      
%    APPUYEZ DEUX FOIS SUR RUN                                          
% //                                                                      //
% // ---------------- FIN EN TETE ----------------------------------------//

[filename1,y] = fonctionidfichier()

[y2] = fonctionautocorrelation(y);

[locs] = fonctionmaximums(y2);

[ bpm ] = fonctionbmpv2(locs);

