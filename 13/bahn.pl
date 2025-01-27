strecke(bielefeld, monchengladbach).
strecke(aachen, monchengladbach).
strecke(dusseldorf, monchengladbach).
strecke(aachen, koln).
strecke(koln, dusseldorf).
strecke(koln, wuppertal).
strecke(dusseldorf, bielefeld).
strecke(wuppertal, dusseldorf).
strecke(wuppertal, bielefeld).

verbindung(X,Y):- strecke(X,Y).
verbindung(X,Y):- strecke(X,Z), verbindung(Z,Y).

ueber(X,Y,Z):- verbindung(X,Y), verbindung(Y,Z).

%% verbindung(wuppertal, aachen).
% verbindung(X, dusseldorf).
% uber(aachen, X, wuppertal).
% ueber(X, koln, wuppertal).
