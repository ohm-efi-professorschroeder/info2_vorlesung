# Pufferüberlauf-Beispiele
Bei diesen Beispielen können Sie mit den Auswirkungen und dem Ausnutzen von Pufferüberläufen experimentieren.

Ziel ist es, über eine geschickte Eingabe die Passwortkontrolle bzw. das Eingeben des korrekten (aber unbekannten) Passworts zu überspringen.

Eine grundlegende Anleitung finden Sie in den Vorlesungsfolien. Unter Windows x64 lässt sich diese 1:1 mit dem Programm `bufferOverflow.c` nachstellen. Auf anderen Betriebssystemen bzw. Prozessorarchitekturen kann es Unterschiede im Stacklayout und der Aufrufkonvention geben, wodurch sich Adressen und Abstände ändern können bzw. das Beispiel gar nicht funktioniert. Schauen Sie in die Kommentare der einzelnen Programme zu Hinweisen, auf welchen Plattformen sie laufen.

Tipp: Versuchen Sie als Übung einmal, die Beispiele auf Ihrem System nachzustellen. Dadurch können Sie sehr viel über die Funktionsweise des Stacks und den Aufruf von Funktionen lernen!

## Cheat Sheet
Hier ein paar Befehle, die dabei nützlich sein können.

### Auf Unix-Systemen die Adressrandomisierung deaktvieren
`sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'`

### Auf Unix-Systemen bzw. in der Bash Bytes auf den Input-Stream des Programms schreiben
`printf "BLABLABLA\x42\x0a" | ./bufferOverflow.out`

### Ein paar nützliche GDB-Befehle
#### Programm starten
```
gdb ./bufferoverflow.out
run
```

#### In GDB auf den Input-Stream des Programms schreiben
`run < <(printf "BLABLABLA\x42\x0a")`

#### Breakpoint setzen
`b myFunction` (Funktion) oder `b bufferOverflow.c:12` (Zeile)

#### Programmablauf nach Breackpoint fortsetzen
`n` (*next*, nächster Schritt)
`c` (*continue*, bis zum nächsten Breakpoint)

#### Adresse einer Funktion anzeigen
`info address myFunction`

#### Informationen zum aktuellen Stackframe anzeigen
`info frame`

#### Speicherinhalt des Stacks tabellarisch anzeigen
`x/40x $sp`

#### Einen 64-Bit (unsigned long) Wert an eine Speicheradresse schreiben
`set {unsigned long}0x7fffffffffff = 0x0000aaaabbbbcccc`