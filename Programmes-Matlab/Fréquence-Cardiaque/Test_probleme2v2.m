%programme test Problème 2 v2 avec le fichier 100.dat

[y,Fe] = Open_dat('100.dat');

[y2] = fonctionautocorrelation(y);

[locs] = fonctionmaximums(y2);

[ bpm ] = fonctionbmpv2(locs);