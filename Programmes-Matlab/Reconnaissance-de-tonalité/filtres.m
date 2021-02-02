function [signalSinusoidalF,signalUtilisateurF] = filtres(signalSinusoidal,signalUtilisateur)

load 'flitreS4.mat';


signalSinusoidalF = filter(Hd_4,signalSinusoidal);
signalUtilisateurF = filter(Hd_4,signalUtilisateur);
end