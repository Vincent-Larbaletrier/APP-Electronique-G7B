% // ---------------- DEBUT EN TETE --------------------------------------//
%    NOM :    Problème 2 :  
% //                                                                      //
%    AUTEURS : Pacome Léna Anaëlle Vincent Baptiste Yassir                                                    
% //                                                                      //
%    VERSION :    2.0 le 06/12/20                                                     
% //                  Création en Matlab                                  //
% // ENTREE :         fichienr Open_dat                                                       
%    SORTIES :        filename
%                     
%
%   MODIFIEES :                                                          
% //                                                                      //
%    LOCALES :                                                            
% //                                                                      //
% //                                                                      //
%    FONCTIONS APPELEES :
%
%                                                                      
%    ALGO - REFERENCES : Moodle, fichier Open_dat                                          
% //                                                                      //
% // ---------------- FIN EN TETE ----------------------------------------//


% Open an .dat file for ECG analysis

function [y,Fe] = Open_dat(filename1)


fid=fopen(filename1,'r');
time=10;
f=fread(fid,2*360*time,'ubit12');
fclose(fid);
y=f(1:2:length(f));

y = y(:)';
Fe = 360;
