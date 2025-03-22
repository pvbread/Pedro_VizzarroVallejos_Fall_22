# Archimedes

Archimedes is a C++ implementation of a Connect Four-style game with a visual interface built using a lightweight rendering framework called **Abelian**. The game supports a single-player mode where the second player is controlled by a simple adversary using a random-move strategy.

---

## 🎮 How It Works

- Two players alternate placing tiles on a 6x7 board.
- The game highlights the current player’s turn.
- Player 1 is human-controlled using the keyboard.
- Player 2 (the adversary) places pieces using a basic strategy (currently random).
- The game detects and highlights winning sequences (vertical, horizontal, diagonal) or a draw.

---

## 🕹️ Controls

| Key       | Action              |
|-----------|---------------------|
| ←         | Move selection left |
| →         | Move selection right|
| Enter     | Drop tile           |

---

## 🛠️ Building the Game

Requirements:
- CMake ≥ 3.24
- A C++17 compatible compiler

### Build Steps

```bash
mkdir build && cd build
cmake ..
cmake --build .
./Archimedes
```

Assets will be copied automatically into the correct runtime directories.

---

## 🖼️ Graphics

The game uses PNG textures to display:
- Empty slots
- Player 1 and Player 2 pieces
- Highlighted winning tiles
- Player turn indicators

All rendering is done using OpenGL via the Abelian framework, made here.
