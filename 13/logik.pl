%% ne Aussage muss wahr oder falsch sein.

aussage(falsch).
aussage(wahr).

%% logische Negation

nicht(wahr,falsch).
nicht(falsch,wahr).

%% logisches UND

und(falsch,falsch,falsch).
und(falsch,wahr,falsch).
und(wahr,falsch,falsch).
und(wahr,wahr,wahr).

%% logische ODER

oder(falsch,falsch,falsch).
oder(falsch,wahr,wahr).
oder(wahr,falsch,wahr).
oder(wahr,wahr,wahr).

%% Implikation => == nicht a oder b

impliziert(X,Y,Z) :- nicht(X, Nicht_X), oder(Nicht_X, Y, Z).

