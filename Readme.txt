PRIMA PARTE	
Task 1 - Bit by Bit 
	1.Functia get_bit - am folosit o masca pe 64 de biti pentru a verifica bitul de pe pozitia i.
	2.Functia flip_bit - m-am folosit de functia de mai sus pentru a afla daca bitul de pe pozitia 
        i este 1 sau 0.
	3,4.Functiile activate_bit si clear_bit - am modificat bitul cu ajutorul operatiilor pe biti 
        si al mastii.

Task 2 - One Gate to Rule Them All
	5,6,7,8. Functiile and_gate, not_gate,or_gate,xor_gate - am implementat cu ajutorul operatorilor 
        logici desenele prezentate.

Task 3 - Just Carry the Bit
	1.Functia full_adder - Am implementat sumatorul pe biti prezentat la PL de pe https://logic.ly/demo,
        apoi am concatenat bitul suma si bitul de carry in res.
	2.Functia ripple carry adder - Am considerat bitul de carry fiind 0 initial, apoi am folosit functia 
        full_adder pentru fiecare bit din a si b(biti pe care i-am obtinut apeland get_bit). Daca bitul sumei
        este activ, atunci il activez si in res. Daca ultimul carry este 1 se produce overflow si prin 
        conventie ii atribui lui res 0.

A DOUA PARTE
Task1 - The Beginning
1.Functia send_byte_message - Aflu codul fiecarei litere folosind codul ASCII si o trimit.
2.Functia recv_byte_message - Aflu litera fiecarui cod si le printez folosindu-ma de vectorul v.
3.Functia comm_byte - Am primit fiecare codare urmand sa o trimit de 2 ori.

Task2 - Wainting for the Message
1.Functia send_message - Am aflat dimensiunea mesajului folosind strlen, dimensiune pe care o codez 
conform figurii.
Apoi trimit codul fiecarei litere din mesaj cu ajutorul vectorului v.
2.Functia recv_message - Primesc dimensiunea mesajului codat(x) pe care il decodez resetandu-i bitii 
de pe pozitiile 6 si 7 si eliminand primii 2 biti. Primesc fiecare cod pe care il pun in vectorul v 
si il transform in litere folosind codul ASCII, dupa care printez.
3.Urmez pasii de la functia anterioara si verific daca ultimul caracter citit(pe care l-am decodat) 
este P SAU V.
Trimit lungimea mesajului in cazul respectiv, codarea lui si codul fiecarei litere.
 
Task3 - In the Zone
1.Functia send_squanch2 - formez bit cu bit numarul : daca bitul este 1 il voi adauga la nr 
shiftat pe pozitia j si cresc j, altfel tot cresc j(creste pozitia).
2.Functia decode_squanch2 - formez bit cu bit numarul conform desenului.

A TREIA PARTE
Task1 - Axii
1.Functia find_spell - parcurg bit cu bit numarul cu un contor, iar cand gasesc 5 biti consecutivi 1 retin pozitia si voi
taia bitii care nu imi trebuie.In final raman cu cheia formata din 16 biti si bitii din fata, dar pentru ca res este 
declarat pe 16 biti va stoca doar primii 16 biti din numar, exact cei ceruti in functie.
2.Functia find_key - parcurg bit cu bit numarul cu un contor, iar cand gasesc 3 biti consecutivi 1 retin pozitia si 
stiind ca inaintea lor am cheia de 16 biti voi taia bitii dupa cheie. In final raman cu cheia formata din 16 biti 
si bitii din fata, dar pentru ca res este declarat pe 16 biti va stoca doar primii 16 biti din numar, exact cei 
ceruti in functie.
3.Functia  decrypt_spell - se obeserva pe un exemplu.

Task2 - Sword Play
1.Functia choose_sword - numar cati biti activi am pentru a decide cu ce biti imi va incepe sabia(daca e om sau nu). 
Apoi folosesc ecuatiile problemei.

Task3
1.Functia trial_of_the_grasses - obtin rezultatul substituind a doua si a treia ecuatie in prima.
2.Functia trial_of_forrest_eyes - Am format numarul pe care trebuie sa il obtin pentru padurea 
Hindar in mask2 si il voi compara cu map. Pentru a verifica daca o padure este formata doar din 
4 copaci consecutivi gasesc pozitia primului copac si maresc j pana la ultimul copac. 
Daca diferenta de pozitii nu este 4 atunci ok = 0.
3.Functia trial_of_the_dreams - gasesc pozitia primului si celui de-al doilea 1 dupa care aflu
distanta dintre ele. 
 


