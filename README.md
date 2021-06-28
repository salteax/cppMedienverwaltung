# Medienverwaltung

### Programmierung 2 - Beleg

### Inhalt
* [Worum geht es?](#worum-geht-es)
* [Funktionen](#funktionen)
* [Kompilieren](#kompilieren)
* [Build](#build)

### Worum geht es?

Bei dem folgenden Beleg handelt es sich um eine Medienverwaltung.
Es werden Medien, wie auch Personen verwaltet. Dies bedeutet man kann Personen und Medien erfassen, anzeigen, auflisten und löschen.
Desweiteren können Personen Medien ausleihen als auch zurückgeben.
Die Daten welche dabei erfasst werden, werden in Dateien gespeichert und können aus diesen auch wieder herausgelesen werden.
Beim Programm selbst handelt es sich um ein CLI (Command Line Interface) welches mit bestimmten Befehlen betätigt wird.

### Funktionen

Liste alles Befehle (welche auch mit dem Parameter h im CLI angezeigt werden kann):

* 'h'	  - Auflistung aller Argumente und den zugehörigen Funktionen.
* 'q'	  - Beendet das Programm.
* 'of'  - Öffnet Dateien und lädt die Daten in die entsprechenden Listen.
* 'sf'  - Speichert die Daten aus den Listen in die entsprechenden Dateien.
* 'l'	  - Listet alle Elemente aus der entsprechenden Liste auf.
* 'n'	  - Erstellt ein neues Element und fügt es der entsprechenden Liste hinzu.
* 'd'	  - Löscht ein Element aus entsprechenden Liste.
* 's'	  - Sucht ein Element in entsprechenden Liste und gibt es aus falls es gefunden wurde.
* 'a'	  - Zum Verleih von Medien.
* 'r'	  - Zur Rückgabe von Medien.

Desweiteren gibt es Labels welche dem Nutzer zur besseren Bedinung verhelfen sollen:

* I - Kennzeichnet Informationen. Gibt ihnen ggf. auch bestätigung, dass etwas funktioniert hat.
* ?	- Kennzeichnet eine Abfrage. Wartet auf ihre Eingabe.
* !	- Kennzeichnet ein Problem. Gibt ihnen Information darüber, dass etwas nicht funktioniert hat.

### Kompilieren

Befehl zum kompilieren des Programmes im Terminal:
`g++ -Wall main.cpp Klassen/person.cpp Klassen/Medien/medium.cpp Klassen/Medien/buch.cpp Klassen/Medien/cd.cpp Klassen/Medien/dvd.cpp -o Medienverwaltung`

### Build

Zum erstellen des Programmes wurde lediglich der g++ Compiler genutzt als auch ein Editor.

Version g++: g++ (GCC) 11.1.0
