

erstes_el(X, [ X | _]).

letztes_el(X, [ X ]).
letztes_el(X, [ _ | T ]) :- letztes_el(X,T).

enthalten(X, [ X | _ ]).
enthalten(X, [ _ | T ]) :- entahlen(X,T).

anhaengen([],L1,L1).
anhaengen( [H1 | T1], L2, [H1|T] ) :- anhaengen(T1,L2,T).

