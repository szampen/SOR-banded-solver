# Sparse Banded SOR Solver: High-Performance Linear System Solver

A C++ implementation of the **Successive-Over-Relaxation (SOR)** method, specifically optimized for **symmetric sparse banded matrices**. 

## Key Features

- **Memory Efficiency:** Instead of storing a full $NxN$ matrix $(O(N^2))$, this solver only stores non-zero bands and the diagonal, achieving $O(N*M)$ **memory complexity** ($N$ - size of the matrix, $M$ - number of bands)
- **Numerical Stability:** Implements the SOR iterative algorithm with a configurable relaxation parameter ($\omega$) to accelerate convergence.
- **Banded Matrix Support:** Specifically handles symmetric matrices where non-zero elements appear only within a distance $M$ from the diagonal.
- **Scientific Precision:** High-precision output in scientific notation.

## Mathematical Background

This solver finds the solution for a system of linear equations $Ax = y$

### The SOR Method

The Successive-Over-Relaxation (SOR) method is an iterative technique. Given a starting vector $x^{(0)}$, it computes the next approximation $x^{(k+1)}$ using the formula:

$$x_i^{(k+1)} = (1 - \omega)x_i^{(k)} + \frac{\omega}{a_{ii}} (y_{i} - \sum_{j < i}a_{ij}x_{j}^{(k+1)} - \sum_{j > i}a_{ij}x_{j}^{(k)})$$

where:

- $\omega$ is the **relaxation factor** ($0 < \omega < 2$).
- If $\omega = 1$, the method reduces to Gauss-Seidel method.
- If $1 < \omega < 2$, the method is called "over-relaxation" and can significantly speed up convergence for certain systems.

## Project Structure
```text
.
├── include/
│   └── SORSolver.hpp     # Class and method declaration
├── src/
│   ├── SORSolver.cpp     # SOR algorithm implementation
│   └── main.cpp          # Input/Output handling and CLI
├── data/                 # Sample input/output files
├── Makefile              # Build system configuration
└── README.md
```

## Build & Run

This project uses `make` and requires a compiler that supports `C++17` standard.

### Compilation
Build the project using the provided `Makefile`:

```bash
make
```

### Running the Solver
The program reads data from standard input. You can pipe your data files directly:

```bash
./sor_solver < data/file1.in
```

### Running sample input files

```bash
make test
```

### Clean up
To remove object files and the executable:

```bash
make clean
```

## Input format
This solver expects the following input sequence:

1. `N` - size of matrix, `N` - number of bands above or below the diagonal
2. `M` lines for each band (starting from the furthest from the diagonal)
3. The main diagonal elements
4. The right-hand side vector $y$
5. The initial guess vector $x^{(0)}$
6. The relaxation parameter $\omega$
7. The number of iterations $L$

## Usage Example

To demonstrate the solver, we can use the provided sample data from `data/file1.in`. This example represents a system with a $7 x 7$ matrix, $M = 2$ non-zero bands and relaxation factor $\omega = 1.5$.

### Sample Input

```text
7                   # N - matrix size
2                   # M - number of bands
1 2 1 2 1           # band 2 (furthest from diagonal)
2 -1 3 1 3 -1       # band 1 (next to diagonal)
5 6 7 8 9 10 11     # main diagonal
8 9 11 16 15 14 11  # vector y
2 3 2 3 2 3 2       # initial guess vector x0
1.5                 # relaxation factor
1                   # number of iterations
```

### Sample Output
This program outputs the solution vector $x^{(L)}$ after $L$ iterations:

```text
-1.0000000000e+00
 2.5000000000e-01
-7.3214285714e-01
 3.1808035714e-01
-2.6432291666e-01
 9.2352120535e-01
 6.6197874391e-01
```


