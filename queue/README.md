# Factory Simulation

This programm simulate a piston factory with an assembly line. It's made to practice
using **queue** in C++.

## 🔧 Implementation

During the process 100 pistons will be created. A piston is made up of 3 parts: the head, the skirt and the pin.
Each part has to be processed in a specific machine. Each machine takes a different time to process a part and has a 25% chance of breaking down, taking 5 to 10 minutes to repair.

## 📋 Requirements

- C++ compiler
- Make

To install the requirements on Debian based systems, use the following commands:

```bash
sudo apt update
sudo apt install build-essential
sudo apt install cmake
```

## 🚀 Usage

First, clone the repository:

```bash
git clone https://github.com/Matth-L/data-struct-compendium.git
cd queue
```

To build and run the game, use the following commands:

```bash
make
./factory
```

To clean up the build files, use:

```bash
make clean
```
