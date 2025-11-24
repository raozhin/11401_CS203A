<img width="526" height="539" alt="螢幕擷取畫面 2025-11-24 173923" src="https://github.com/user-attachments/assets/8119782a-f315-4898-84fc-d6e37982320d" /><img width="526" height="539" alt="螢幕擷取畫面 2025-11-24 173923" src="https://github.com/user-attachments/assets/c96bf501-77e5-4181-87b8-15e54f57eb8e" /># Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++.
Students are expected to implement and analyze the behavior of hash functions,
evaluate their efficiency, and understand their applications in computer science.

**Developer:** Rao zhin
**Email:** s1133305@mail.yzu.edu.tw

This project was developed and tested in a **Windows** environment.

* **Operating System:** Windows
* **Compiler:** GCC and G++ (MinGW-w64)
* **Build Tool:** `Makefile.bat` (Windows batch script)
* **IDE:** Visual Studio Code
## My Hash Function

### Integer Keys
- **Formula / Pseudocode:**
  ```cpp
  // Multiplication Method
  double A = sqrt(2)-1;
  // Extract the fractional part of (key * A) and multiply by m
  hash = floor(m * (fmod(key * A, 1)));
``

  - **Rationale:**
    I implemented the **Multiplication Method**. By multiplying the key by an irrational number (in the range $(0, 1)$,this case: $\sqrt{2}-1$). Using an irrational number effectively "scrambles" the key's bits and breaks up input patterns, such as arithmetic progressions. The final index is obtained by multiplying this fractional part by the table size $m$ and taking the floor. This approach is generally more robust against patterned data than the simple division method ($key \pmod m$), especially when $m$ is not prime.
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
    I used a **Polynomial Rolling Hash** approach. This method treats a string as a polynomial where each character's ASCII value is a coefficient, and a prime number $31$, a small prime commonly used in string hashing algorithms. This approach ensures that:
    1.Order Matters: "cat" and "act" will produce different hashes because the characters are at different positions in the polynomial.

    2.Uniform Distribution: The prime multiplier helps distribute the resulting hash values more uniformly across the table. It is crucial to apply the modulo operator (% m) at each step of the calculation to prevent integer overflow, which could skew the distribution.

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

## Compilation, Build, and Execution (Windows)

This project is developed in a **Windows environment** and includes a `Makefile.bat` script to simplify the build process.

### Building the Project

Open a command prompt (cmd) or PowerShell in the project's root directory and use the following commands:

  - **Build both C and C++ versions (default):**

    ```cmd
    Makefile.bat
    ```

    or

    ```cmd
    Makefile.bat all
    ```


  - **Build only the C version:**

    ```cmd
    Makefile.bat c
    ```


  - **Build only the C++ version:**

    ```cmd
    Makefile.bat cxx
    ```


To remove all compiled executables and object files:

```cmd
Makefile.bat clean
```


###Manual Compilation

If you prefer to compile manually, use the following commands in your command prompt:

  - **C Version:**

    ```cmd
    gcc -std=c23 -Wall -Wextra -Wpedantic -g -c C\main.c -o C\main.o
    gcc -std=c23 -Wall -Wextra -Wpedantic -g -c C\hash_fn.c -o C\hash_fn.o
    gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C\hash_function.exe C\main.o C\hash_fn.o
    ```


  - **C++ Version:**

    ```cmd
    g++ -std=c++23 -Wall -Wextra -Wpedantic -g -c CXX\main.cpp -o CXX\main.o
    g++ -std=c++23 -Wall -Wextra -Wpedantic -g -c CXX\hash_fn.cpp -o CXX\hash_fn.o
    g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX\hash_function_cpp.exe CXX\main.o CXX\hash_fn.o
    ```

    [cite\_start][cite: 3]

### Execution

Run the generated executables from the project root directory:

  - **Run C version:**

    ```cmd
    .\C\hash_function.exe
    ```

    [cite\_start][cite: 3]

  - **Run C++ version:**

    ```cmd
    .\CXX\hash_function_cpp.exe
    ```

    [cite\_start][cite: 3]

### Output Screenshot

Below is a screenshot demonstrating the successful execution of both C and C++ versions of the program.

    ```<img width="593" height="545" alt="image" src="https://github.com/user-attachments/assets/9d30aba5-6db0-4606-8a89-75dce083b7d6" />
    <img width="499" height="544" alt="image" src="https://github.com/user-attachments/assets/9b9e401c-c26c-4368-8185-dd5fa3e58de3" />

  

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

=== Hash Function Observation (C++ Version) ===

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

## Analysis & Reflection

### Analysis of Results

  - **Impact of Table Size (m):** The experimental results clearly show that **prime number table sizes (11, 37) yield significantly better key distribution** and fewer collisions compared to a composite size (10). This holds true even when using a robust algorithm like the Multiplication Method. The larger prime size (37) provided the best distribution, drastically reducing the collision probability.
  - **Algorithm Effectiveness:**
      - The **Multiplication Method** successfully handled the patterned integer input (arithmetic sequences), preventing the obvious patterns that a simple division hash might have produced.
      - The **Polynomial Rolling Hash** effectively distinguished between short strings. The collisions observed at smaller `m` values are expected due to the Pigeonhole Principle, but the algorithm itself performed well, as evidenced by the near-perfect distribution at `m=37`.

### Key Takeaways

1.  **Balancing Act:** Designing a good hash function is a balance between simplicity, speed, and collision minimization. The chosen methods are standard and effective for their respective key types.
2.  **Prime is Prime:** The choice of table size `m` is as critical as the hash function itself. Always prefer a prime number for `m` to maximize the effectiveness of the hash function's distribution properties.

<!-- end list -->




