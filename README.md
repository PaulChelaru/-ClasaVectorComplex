# -ClasaVectorComplex

<h2> Cerinte comune tuturor temelor: </h2>
<ul>
<il>implementare in C++ folosind clase</il>
<il>datele membre private</il>
<il>constructoride initializare (cu si fara parametrii), constructorde copiere</il>
<il>get, set pentru toate datele membre</il>
<il>ATENTIE:functiile  pe   care   le-am   numit   mai   josmetode(fie   ca   sunt  supraincarcari   de operatori, fie altfel de functii),pot fi implementate ca functii prietenin loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala;</il>
<il>supraincarcarea  operatorilor  <<  si  >>  pentru  iesiri  si  intrari  de  obiecte,  dupa  indicatiile  de mai jos, astfel incat sa fie permise (si ilustrate in program)</il>
<il>sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte, memorarea și afisarea acestora</il>
<il>programul sa aiba un meniu interactiv</il>
<ul>

<h2> Clasa ”Vector_Complex” </h2>
<ul>
 <il>clasa este prietena a clasei Numar_Complex definita în Tema 0</il>
 <il>membri privati pentru vectorul propriuzis si numarul de elemente;</il>
 <il>constructor pentru initializarea cu un numar dat pe toate componentele (primeste ca parametru numarul respectiv si numarul componentelor);</il>
 <il>constructori pentru initializare si copiere;-destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);</il>
 <il>supraincarcarea operatorilor << și >> sa utilizeze supraincarea acestora în cadrul clasei Numar_Complex;-metoda   publica   pentru   determinarea   vectorului   modulelor,   folosind   metoda   de determinare a modulului din clasa numar complex;</il>
 <il>metoda publica pentru sortarea crescatoare dupa module a vectorului;</il>
 <il>metoda  publica  pentru  calculul  sumei  tuturor  elementelor  vectorului,  care  sa  utilizeze operatorul + din clasa de numere complexe;</il>
</ul>

<h2>Clasa Complex a fost implementata in timpul orelor de laborator</h2>
