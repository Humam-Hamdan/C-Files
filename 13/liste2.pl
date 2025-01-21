
lange_falsch([], 0).
lange_falsch([_|Rest], Lange) :- lange_falsch(Rest, LangeRest), Lange=LangeRest+1.

lange([],0).
lange([_|Rest],Lange) :- lange(Rest,LangeRest), Lange is LangeRest+1.

