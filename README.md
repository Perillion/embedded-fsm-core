# Perillion Core: FSM & HAL

Embedded FSM Framework with Hardware Abstraction Layer.

## Prerequisites

You need to install CMake to build this project.
On macOS with Homebrew:

```bash
brew install cmake
```

## Build & Test Anleitung

Das Projekt nutzt CMake und Catch2. So führst du das "Hello World" Test-Programm aus:

### 1. Build-Verzeichnis erstellen und konfigurieren
```bash
mkdir build
cd build
cmake ..
```
*Hinweis: Beim ersten Mal wird Catch2 automatisch heruntergeladen.*

### 2. Projekt bauen
```bash
cmake --build .
```

### 3. Tests ausführen
Du hast zwei Möglichkeiten:

**Option A: Über CTest (Empfohlen)**
```bash
ctest --output-on-failure
```

**Option B: Direktes Ausführen**
```bash
./unit_tests
```
