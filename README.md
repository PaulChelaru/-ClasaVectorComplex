# -ClasaVectorComplex

<h2> Cerinte comune tuturor temelor: </h2>
<ul>
<li>implementare in C++ folosind clase</li>
<li>datele membre private</li>
<li>constructoride initializare (cu si fara parametrii), constructorde copiere</li>
<li>get, set pentru toate datele membre</li>
<li>ATENTIE:functiile  pe   care   le-am   numit   mai   josmetode(fie   ca   sunt  supraincarcari   de operatori, fie altfel de functii),pot fi implementate ca functii prietenin loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala</li>
<li>supraincarcarea  operatorilor  <<  si  >>  pentru  iesiri  si  intrari  de  obiecte,  dupa  indicatiile  de mai jos, astfel incat sa fie permise (si ilustrate in program)</li>
<li>sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte, memorarea și afisarea acestora</li>
<li>programul sa aiba un meniu interactiv</li>
<ul>

<h2> Clasa ”Vector_Complex” </h2>
<ul>
 <li>clasa este prietena a clasei Numar_Complex definita în Tema 0</li>
 <li>membri privati pentru vectorul propriuzis si numarul de elemente</li>
 <li>constructor pentru initializarea cu un numar dat pe toate componentele (primeste ca parametru numarul respectiv si numarul componentelor)</li>
 <li>constructori pentru initializare si copiere;-destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata)</li>
 <li>supraincarcarea operatorilor << și >> sa utilizeze supraincarea acestora în cadrul clasei Numar_Complex;-metoda   publica   pentru   determinarea   vectorului   modulelor,   folosind   metoda   de determinare a modulului din clasa numar complex</li>
 <li>metoda publica pentru sortarea crescatoare dupa module a vectorului</li>
 <li>metoda  publica  pentru  calculul  sumei  tuturor  elementelor  vectorului,  care  sa  utilizeze operatorul + din clasa de numere complexe</li>
</ul>

<h4>Clasa Complex a fost implementata in timpul orelor de laborator</h4>
