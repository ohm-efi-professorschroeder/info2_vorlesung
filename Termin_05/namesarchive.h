#ifndef NAMEARCHIVE_H
#define NAMEARCHIVE_H

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
int addName(const char *name);
// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSorted(const char *name);
// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name);
// Sortiert die Namen im Archiv aufsteigend.
void sortNames();
// Gibt die Namen zeilenweise aus.
void printNames();
// Leert das Archiv
void clearArchive();

#endif