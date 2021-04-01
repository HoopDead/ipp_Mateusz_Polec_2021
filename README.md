# ipp_Mateusz_Polec_2021

Indywidualny projekt programistyczny - Onyx RPG. Tworzony przez Mateusza Połcia.

## Pomysł na projekt

Stworzenie własnego silnika gier na podstawie biblioteki SFML nastawionego pod tworzenie gier gatunku RPG. Następnie stworzenie prostej gry RPG, przedstawiającej problem porzucanych zwierząt we współczesnym świecie.

## Funkcjonalności

- [x] Stworzenie ruchu niezależnego od FPSów,
- [x] Stworzenie Inputu i Bitmaski do obsługiwania wielu klawiszy wciśniętych na raz,
- [x] Stworzenie Menadżera Scen,
- [x] Stworzenie systemu komponentów,
- [x] Stworzenie systemu zasobów,
- [x] Stworzenie menadżera obiektów,
- [x] Stworzenie silnika animacji,
- [x] Stworzenie silnika wczytywania tilemapy,
- [] Stworzenie silnika kolizji,
- [] Stworzenie systemu kamer,
- [] Stworzenie systemu projectiles,
- [] Stworzenie komunikacji między kolizjami
- [] Stworzenie menadżera Questów,
- [] Stworzenie menadżera Dialogów,
- [] Stworzenie silnika cutscenes (?)
- [] Stworzenie shaderów do imitacji nocy, pogody
- [] Stworzenie menu,
- [] Stworzenie prostej mapy,
- [] Stworzenie systemu umiejętności,
- [] Stworzenie prostej misji,
- [] Stworzenie demo gry.

## Plan gry

Gra, która skupia się na problemie porzuconych zwierząt we współczesnym świecie. Głównią postacią jest pies rasy shibainu, porzucony przez właściciela. Bohaterem będzie można poruszać za pomocą klawiatury. Do rozgrywki zostaną dodanę elementy questów, dialogów, muzyki, menu i animacji. Akcja toczona będzie w Japońskim mieście. Gracz za główny cel będzie miał wybranie jednej ze ścieżki - odnalezienia nowego właściciela, lub poznania uroków życia dzikiego. Pobocznymi zadaniami będzie możliwość pomocy innym zwierzętom/ludziom. Opis poszczególnych questów pojawi się wraz z **Raportem III**. 


Przykładowa grafika (aktualnie w trakcie tworzenia):

![alt text](https://i.imgur.com/vPuId7y.png)

## Technicze szczegóły gry:

Grafika 2D, pixelartowa, obsługiwanie eventów wprowadzanych z klawiatury/myszki.


## Przykładowy Quest (Startowy):

Start gry odbywa się przy akompaniamencie melancholinej muzyki. Znajdujemy się w portowej - nieznanej dla gracza - części miasta. Pierwszym zadaniem jest odnalezienie jakiegokolwiek schronienia na początek. Gracz zwesząd będzie doświadczał ogromnej ignoracnji ze strony środowiska - na psa nikt nie będzie zwracał uwagi. Do wyboru gracza będzie kilka miejsc, w których początkowo będzie mógł się schronić (Weranda domu, zaułek ulicy, portowy magazyn). W każdym z miejsc doświadczymy zarówno plusów wyboru, jak i minusów.

**Portowy magazyn**:
- Gracz znajdzie tutaj pożywienie,
- Gracz zostanie poturbowany przez inne, dzikie zwierzęta

**Weranda domu**:
- Gracz znajdzie schronienie na noc,
- Gracz zostanie rano przegoniony przez właściciela domu
- 
**Zaułek ulicy**:
- Gracz nie znajdzie schronienia
- Gracz pozna NPC, który będzie mu pomagał.



## Technologie

- C++ w wersji 17,
- SFML w wersji 2.5.1,
- C++ STL,
- tmxlite.

## Dokładny opis tasków:

Można znaleźć pod tym linkiem, lub zakładce "Projects" repozytorium:

[Opisy wszystkich zadań](https://github.com/HoopDead/ipp_Mateusz_Polec_2021/projects/)



## Harmonogram

- 23.03.2021 - Propozycja projektu
- 06.03.2021 - I Raport, Planowane gotowe rozwiazania:
- Silnik wczytywania mapy,
- Tester optymalizacyjny kodu,
- Global Timer
- Stworzenie mapy do gry (a przynajmniej wstepnego zarysu)
- 20.03.2021 - II Raport, Planowane gotowe rozwiazania:
- System kamer,
- System Projectiles,
- System Questow
- 11.04.2021 - IV Raport, Planowane gotowe rozwiązania:
- System dialogów,
- System quick time eventów
- System muzyki/dialogów,
- Stworzenie silnika cutscenes (?)
- 25.04.2021 - V Raport,
- Stworzenie menu gry
- Stworzenie demo gry - questy, eventy, dialogi
- 18.05.2021 - Finałowy projekt, ostatni raport.
