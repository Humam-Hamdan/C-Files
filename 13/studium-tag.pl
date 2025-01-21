%% tag(t) gilt wenn t n vorlesungstag ist.

tag(dienstag).
tag(mittwoch).
tag(donnerstag).

%% uhrzeit(U) gilt, wenn um U die VL beginnen konnen.

uhrzeit(8).
uhrzeit(10).

%% tag vor(t1,t2) gilt, wenn t1 direkt vor t2 kommt

tag_vor(dienstag,mittwoch).
tag_vor(mittwoch,donnerstag).

%% Regeln

termin(T,U):- tag(T), uhrzeit(U).

vor(T1,T2):- tag_vor(T1,T2).
vor(T1,T2):- tag_vor(T1,Z), vor(Z,T2).

%% direkt vor
nicht_direkt_vor(T1,T2):- vor(T1,T2), tag_vor(T,T2),  T1 \== T.
