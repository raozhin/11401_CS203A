# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++.
Students are expected to implement and analyze the behavior of hash functions,
evaluate their efficiency, and understand their applications in computer science.

**Developer:** Rao zhin
**Email:** s1133305@mail.yzu.edu.tw

## My Hash Function

### Integer Keys
- **Formula / Pseudocode:**
  ```cpp
  // Multiplication Method
  double A = sqrt(2);
  // Extract the fractional part of (key * A) and multiply by m
  hash = floor(m * (fmod(key * A, 1)));
````

  - **Rationale:**
    I implemented the **Multiplication Method**. By multiplying the key by an irrational number (in this case, $\sqrt{2}$) and taking the fractional part, the bits of the key are "scrambled" effectively. This method is generally less sensitive to patterns in the input data (like consecutive integers) compared to the simple Division Method (`key % m`), especially when `m` is not a prime number.

### Non-integer Keys (Strings)

  - **Formula / Pseudocode:**
    ```cpp
    // Polynomial Rolling Hash
    unsigned long hash = 0;
    for (char c : str) {
        hash = (hash * 31 + c);
        hash %= m; // Apply modulo at each step to prevent overflow issues impacting distribution
    }
    ```
  - **Rationale:**
    I used a **Polynomial Rolling Hash** approach. The multiplier `31` is a small prime number widely used in hash functions (like in Java's String hash). This ensures that the order of characters matters (e.g., "cat" and "act" produce different hashes) and helps distribute keys uniformly across the table size `m`.

## Experimental Setup

  - **Table sizes tested (m):** 10, 11, 37
  - **Test dataset:**
      - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
      - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
  - **Compiler:** GCC and G++
  - **Standard:** C23 and C++23

## Results

| Table Size (m) | Index Sequence (First few) | Observation |
| :---: | :--- | :--- |
| **10** | 6, 1, 5, 9, 3... | Distribution is somewhat scattered but patterns appear. |
| **11** | 7, 1, 5, 10, 3... | More uniform distribution due to prime size. |
| **37** | 25, 4, 19, 34, 13... | Wide spread of indices, effectively utilizing the table space. |

## Compilation, Build, Execution, and Output

### Compilation

The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:

```bash
# Build both C and C++ versions
make all

# Build only C version
make c

# Build only C++ version
make cxx
```

### Manual Compilation (if needed)

  - Command for C:

    ```bash
    gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c -lm
    ```

    *(Note: `-lm` added for math library linkage due to `sqrt` and `floor`)*

  - Command for C++:

    ```bash
    g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
    ```

### Clean Build Files

Remove all compiled files:

```bash
make clean
```

### Execution

Run the compiled binary:

```bash
./hash_function
# or
./hash_function_cpp
```

### Result Snapshot

**Example output for integers:**

```text
=== Hash Function Observation (C Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      6
22      1
...

=== Table Size m = 11 ===
Key     Index
-----------------
21      7
22      1
...

=== Table Size m = 37 ===
Key     Index
-----------------
21      25
22      4
...
```

**Example output for strings:**

```text
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     4
...

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     10
dog     6
...

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     27
dog     3
...
```

**Detailed Array Output:**

  - **Integers:**
    ```text
    Hash table (m=10): [6, 1, 5, 9, 3, 7, 1, 5, 0, 4, 1, 5, 9, 3, 7, 1, 6, 0, 4, 8]
    Hash table (m=11): [7, 1, 5, 10, 3, 8, 2, 6, 0, 4, 1, 5, 10, 4, 8, 2, 6, 0, 4, 9]
    Hash table (m=37): [25, 4, 19, 34, 13, 28, 6, 22, 0, 15, 4, 19, 35, 13, 28, 7, 22, 0, 16, 31]
    ```
  - **Strings:**
    ```text
    Hash table (m=10): [2, 4, 1, 9, 3, 8, 0, 5, 0, 3]
    Hash table (m=11): [10, 6, 6, 7, 9, 6, 5, 5, 0, 9]
    Hash table (m=37): [27, 3, 28, 20, 25, 23, 26, 29, 27, 18]
    ```

## Analysis

  - **Prime vs Non-prime `m`:** Prime table sizes (like 11 and 37) generally result in better distribution. Even when using the Multiplication Method (which is robust), using a prime `m` adds an extra layer of safety against collisions caused by input patterns.
  - **Patterns:** In `m=10`, we can observe some repeating values (e.g., Index 1 appears multiple times for Integers), whereas `m=37` spreads the keys much more widely across the available range.

## Reflection

1.  **Algorithm Choice:** Designing hash functions requires balancing simplicity and effectiveness. The Multiplication Method proved effective for integers, while the Polynomial Rolling Hash worked well for strings.
2.  **Table Size Importance:** My observations confirm that table size significantly impacts the uniformity of the hash distribution. Larger prime sizes drastically reduce collision probability.
3.  **Implementation:** Using C/C++ math libraries (`cmath`/`math.h`) allowed for precise implementation of the multiplication method using floating-point operations.
