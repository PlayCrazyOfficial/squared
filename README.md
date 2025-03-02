# Squared

*Squared is a small, free and open-source simple game.*

## What is Squared?
Squared is a video game developed by the PlayCrazy studio and published under the GPL 3 licence. It has been designed to be extremely simple, both in terms of gameplay and source code.

## Gameplay
In this top-down game, you control a square that can move in four directions (left, right, up, down), and must collect a number of small objects to increase its score. The game is endless.

## Supplementary informations
Platform: PC / Portable computer
Operating systems: Linux / Windows / MacOS

## Installation
*The automated construction of the game requires BASH, GCC and Raylib (C) to work. The produced executable will only run on a Linux system.*

**Step 1**: Run `build.sh`
```bash
chmod +x build.sh
./build.sh
```

**Step 2**: Install the game
```bash
su                      # You can use sudo too
chmod +x install.sh
./install.sh
```

**Step 3**: Run the game!
```bash
squared
```