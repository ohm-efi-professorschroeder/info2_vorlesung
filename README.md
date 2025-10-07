# INFO2 Vorlesung

*Autor: Prof. Dr.-Ing. Enrico Schröder, OHM Technische Hochschule Nürnberg, Fakultät EFI.*

**Hier finden Sie den Code aus der Vorlesung INFO2, den wir gemeinsam während der Vorlesung
entwickeln.**

Ich werde nach den Vorlesungen den erarbeiteten Stand des Codes hier hochladen. Bitte beachten Sie, dass es sich hierbei
nicht um eine Musterlösung handelt, sondern der Code dem aktuellen Stand aus der Vorlesung entspricht. D.h., er ist
möglicherweise nicht vollständig oder korrekt.

Ich empfehle Ihnen, sich den Code nochmals anzuschauen und ihn nachzuvollziehen und ggf. zu vervollständigen. Fragen
können wir gerne jeweils am Anfang der Vorlesungen besprechen.

Um den Code zu verwenden, klonen Sie das Repository und öffnen Sie es in einer geeigneten Entwicklungsumgebung, wie z.B.
Jetbrains CLion oder VSCode. Sie können die einzelnen Programme manuell über die Kommandozeile kompilieren.

Alternativ befindet sich im Wurzelverzeichnis ein s.g. `Makefile`, welches Regeln zur Erstellung der einzelnen Programme beinhaltet. Zum Kompilieren führen Sie in der Kommandozeile den Befehl `make <Programmname>` aus, also z.B. für das Programm *bufferOverflow* aus dem ersten Termin:

> make bufferOverflow

Hinweis: Dies setzt die Installation des Programms **Make** voraus. Diese ist meistens beim Compiler mit dabei, falls Sie jedoch Fehlermeldungen bekommen ("Make could not be found" o.ä.), versuchen Sie, Make manuell zu installieren. 