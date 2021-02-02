% // ---------------- DEBUT EN TETE --------------------------------------//
%    NOM :    Problème 2 :  
% //                                                                      //
%    AUTEURS : Pacome Léna Anaëlle Vincent Baptiste Yassir                                                    
% //                                                                      //
%    VERSION :    2.0 le 06/12/20                                                     
% //                  Création en Matlab                                  //
% // ENTREE :         locs      liste                                     //            
%    SORTIES :        bpm       int
%                     

%                      
%
%   MODIFIEES :         bmp           int
%                       frequence     int
%                       period        int
% //                                                                      //
%    LOCALES :         frequence      int
%                      period         int
% //                                                                      //
% //                                                                      //
%    FONCTIONS APPELEES :
%     
%                                                                      
%    ALGO - REFERENCES :                                           
% //                                                                      //
% // ---------------- FIN EN TETE ----------------------------------------//

function[ bpm ] = fonctionbmpv2(locs);

t0=0;
t1=t0;

for i=1:1:10
    t1=t0;
    t0=locs(i);
    period = (t0-t1)/360;
    frequence = 1/period;
    bpm = frequence*60;
    if bpm<140
        disp(bpm)
    end
end
end
