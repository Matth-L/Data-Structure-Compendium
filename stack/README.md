# 🃏 Card Game Simulation: War 🎴

This program simulates the classic card game **War**. It's designed to practice using **stacks** in C++.

## 🔧 Implementation

In this project, 100 cards will be shuffled and randomly split between two players. 
Each player's cards will be stored in a stack. The game continues until one player runs out of cards, and a clear winner is determined.

## 📋 Requirements
- C++ compiler
- Make
- CxxTest (for running tests)

To install the requirements on Debian based systems, use the following commands:

```bash
sudo apt update
sudo apt install build-essential
sudo apt install cmake
sudo apt install cxxtest
```

## 🚀 Usage

To build and run the game, use the following commands:

```bash
make
./war_game
```

We created tests to check the stack implementation. To run the tests, use:

```bash
./test_pile
```

To clean up the build files, use:

```bash
make clean
```
