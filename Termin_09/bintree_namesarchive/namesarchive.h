#ifndef NAMEARCHIVE_H
#define NAMEARCHIVE_H

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
// Der Name soll in beliebiger Länge gespeichert werden können.
int addName(const char *name);
// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name);
// Gibt die Namen zeilenweise und alphabetisch sortiert aus.
void printNamesSorted();
// Leert das Archiv
void clearArchive();

#endif