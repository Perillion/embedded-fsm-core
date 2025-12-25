# C++ Sonderzeichen auf dem Mac (Deutsches Layout)

Hier sind die wichtigsten Tastenkombinationen für Zeichen, die auf der Apple-Tastatur nicht direkt aufgedruckt sind, aber für C++ ständig benötigt werden.

Die Taste `Option` ist die Taste mit der Aufschrift `alt` (⌥).

## Wichtige Klammern & Blöcke

| Zeichen | Name | Tastenkombination | Verwendung |
| :---: | --- | --- | --- |
| `{` | Geschweifte Klammer auf | `Option` + `8` | Funktionskörper, Klassen, Scopes |
| `}` | Geschweifte Klammer zu | `Option` + `9` | Ende von Scopes |
| `[` | Eckige Klammer auf | `Option` + `5` | Arrays, Lambda-Captures `[]` |
| `]` | Eckige Klammer zu | `Option` + `6` | Arrays, Lambda-Captures |

## Operatoren & Logik

| Zeichen | Name | Tastenkombination | Verwendung |
| :---: | --- | --- | --- |
| `|` | Pipe (Senkrechter Strich) | `Option` + `7` | Bitweises ODER, Logisches ODER `||` |
| `\` | Backslash | `Shift` + `Option` + `7` | Zeilenumbruch in Makros, Escape-Sequenzen |
| `~` | Tilde | `Option` + `N` | Destruktor `~Class()`, Bitweises NICHT |
| `/` | Slash | `Shift` + `7` | Kommentare `//`, Division, Pfade |

## Sonstiges

| Zeichen | Name | Tastenkombination | Verwendung |
| :---: | --- | --- | --- |
| `@` | At-Zeichen | `Option` + `L` | Doxygen Kommentare |
| `•` | Bullet Point | `Option` + `Ü` | (Nützlich für Notizen) |

## Tipps

*   **Kommentare**: `Shift` + `7` (zweimal drücken für `//`)
*   **Pointer**: `Shift` + `+` (für `*`)
*   **Include**: `Shift` + `<` (Taste neben Y) für `#include <...>`

## CLion Shortcuts (Wortvorhersage & Co.)

| Funktion | Tastenkombination | Beschreibung |
| :---: | --- | --- |
| **Code Completion** | `Ctrl` + `Leertaste` (`^` + `Space`) | Zeigt Vorschläge für Methoden, Variablen etc. (Wortvorhersage) |
| **Smart Completion** | `Ctrl` + `Shift` + `Leertaste` | Filtert Vorschläge nach passendem Typ |
| **Parameter Info** | `Cmd` + `P` | Zeigt welche Parameter eine Funktion erwartet |
| **Quick Fix** | `Option` + `Enter` | Schlägt Lösungen für Fehler vor (die "Glühbirne") |
