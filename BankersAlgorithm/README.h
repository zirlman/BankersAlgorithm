#pragma once

/*
	Tekst zadatka:
	Korištenjem proizvoljnog programskog jezika implementirati aplikaciju koja će prikazati rješenje bankarskog
	algoritma za sistem sa 4 procesa.Programu se putem argumenata komandne linije prosljeđuju podaci o
	instancama resursa A i B koje su trenutno rezervisane i koje su tražene, kao i slobodne količine resursa.
	Program ispisuje jedan od mogućih redoslijeda izvršavanja procesa(ako on postoji) ili poruku o tome da se
	sistem nalazi u zastoju.Ako postoji redoslijed izvršavanja procesa, onda je potrebno ispisati i stanja u
	svakom koraku izvršavanja algoritma.
	
	------------------------------------------------------------

	Algoritam rekurzivno prolazi kroz niz procesa, prvo znaci da je proces obradjen,oslobodi svoje resurse i stavi processId u
	safe vektor. Nakon toga poziva se safeSequence() u kojoj se preskacu oznaceni procesi. Nakon sto se naidje na sigurnu sekvencu.
	for petlja se nece izvrsiti i provjerava se uslov da li postoji sigurna sekvenca, ukoliko ona postoji onda se vrsi ispis elemenata koji cine
	sigurnu sekvencu. Po zavrsetku te metode vrsi se povratak iz rekurzije pri cemu se proces izbacuje iz sigurne sekvence, oznacava da nije obradjen
	i zauzima resurse koje je prethodno oslobodio.
*/