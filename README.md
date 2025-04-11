# C++ Exercise

This repository contains beginner-friendly C++ console applications that demonstrate practical programming concepts through interactive utilities:

## 🧮 Math Toolkit

An interactive command-line calculator that supports a range of mathematical operations, including:

- Addition, Subtraction, Multiplication, Division
- Power calculation (`a^b`)
- Square Root
- Natural Logarithm (`ln`)
- Base-10 Logarithm (`log10`)

### How It Works

The program presents a simple menu-based interface. Based on the user's selection, it performs the corresponding operation on the provided input(s). Input validation and common error handling (e.g., division by zero) are included.

### File

- `math-toolkit.cpp`: Source code for the math calculator.

---

## 🎯 Projectile Simulator

A physics-based simulation tool to calculate projectile motion characteristics using user-provided input for:

- Initial velocity (m/s)
- Launch angle (degrees)
- Initial height (m)

### Outputs

- Maximum height
- Final vertical velocity
- Final total velocity
- Total flight time
- Horizontal distance traveled

### File

- `projectile-simulator.cpp`: Implements a simplified 2D projectile motion simulator using classical mechanics formulas.

---

## 🛠 Requirements

- A C++ compiler (e.g., g++, clang++)
- Basic command line usage knowledge

### Compile & Run

```bash
g++ math-toolkit.cpp -o math-toolkit
./math-toolkit
```

```bash
g++ projectile-simulator.cpp -o projectile-simulator
./projectile-simulator
```

---

## 📁 Project Structure

```
cpp-exercises/
├── math-toolkit.cpp
└── projectile-simulator.cpp
```

---

## ℹ️ Note

This repository is created for educational purposes only.