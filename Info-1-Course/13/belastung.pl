
belastung(Gang, Stunde) :- 
	fach(Gang), 
	lehrplan(Gang, Vorlesung), 
	addiere(Vorlesung,Stunde).

addiere([],0).
addiere( [Ertse | Rest], Stunde ):- 
	vorlesung(Erste, StundenErste), 
	addiere(Rest, StundenRest), 
	Stunden is StundenErtse + StundenRest.
