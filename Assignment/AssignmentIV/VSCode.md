This document outlines the setup process of Visual Studio Code (VS Code) for C/C++ development and its integration with Git and GitHub for this assignment in a **Windows environment**.

## 1. Prerequisites

Before starting the setup, ensure the following software is installed on your Windows system:

* **Visual Studio Code**: The latest version from [code.visualstudio.com](https://code.visualstudio.com/).
* **Git**: For version control, installed from [git-scm.com](https://git-scm.com/).
* **C/C++ Compiler**: GCC and G++ (e.g., via MinGW-w64).

## 2. VS Code Extensions Setup

To transform VS Code into a powerful C/C++ IDE, the following extensions were installed from the Marketplace (Ctrl+Shift+X):

* **C/C++ Extension Pack (by Microsoft)**: This is essential. It includes IntelliSense (code completion), debugging features, and code browsing tools for C and C++.
* **(Optional) GitLens**: Provides deeper insights into Git history directly within the editor lines, which is very helpful for tracking changes.
* **GitHub Pull Requests and Issues**: Allows you to review and manage GitHub pull requests and issues directly in VS Code.

## 3. Integrating Git and GitHub

VS Code has excellent built-in support for Git. Here is the workflow used for this assignment:

### 3.1. Signing in to GitHub

1.  Open the Command Palette (`Ctrl+Shift+P`).
2.  Type `GitHub: Sign in` and select the option.
3.  Follow the prompts to authenticate with your GitHub account.

### 3.2. Cloning the Repository

Instead of using the command line externally, I used VS Code's command palette:
1.  Opened the Command Palette (`Ctrl+Shift+P`).
2.  Typed `Git: Clone` and selected the option.
3.  Pasted the course repository URL when prompted.
4.  Selected the local destination folder where the repository will be cloned.
5.  Once cloned, VS Code prompted to open the repository, and I clicked `Open`.

### 3.3. Managing Changes (Source Control View)

[cite_start]I utilized the **Source Control** view (Ctrl+Shift+G) in the sidebar for version control operations:

1.  **Staging**: Modified files appear under "Changes". Clicking the `+` button next to a file stages it for commit (equivalent to `git add`).
2.  **Committing**: Entered a descriptive commit message in the message box above the staged changes and clicked the "Commit" button.
3.  **Pushing**: Synced changes to GitHub by clicking the "Sync Changes" button (or "Push" option in the menu) in the bottom-left status bar or in the Source Control view.

## 4. Building and Running the Assignment (Windows)

Since this assignment is developed in a Windows environment and provides a `Makefile.bat`, the build process is streamlined using VS Code's integrated terminal.

1.  **Open Integrated Terminal**: Used the shortcut `` Ctrl+` `` (backtick) to open the terminal within VS Code.
2.  **Compile**: Ran the `Makefile.bat` command to build both C and C++ executables.
    ```cmd
    .\Makefile.bat all
    ```
3.  **Run**: Executed the compiled binaries directly from the terminal.
    ```cmd
    .\C\hash_function.exe    # For the C version
    .\CXX\hash_function_cpp.exe  # For the C++ version
    ```
This document outlines the setup process of Visual Studio Code (VS Code) for C/C++ development and its integration with Git and GitHub for this assignment in a **Windows environment**.

## 1. Prerequisites

Before starting the setup, ensure the following software is installed on your Windows system:

* **Visual Studio Code**: The latest version from [code.visualstudio.com](https://code.visualstudio.com/).
* **Git**: For version control, installed from [git-scm.com](https://git-scm.com/).
* **C/C++ Compiler**: GCC and G++ (e.g., via MinGW-w64).

## 2. VS Code Extensions Setup

To transform VS Code into a powerful C/C++ IDE, the following extensions were installed from the Marketplace (Ctrl+Shift+X):

* **C/C++ Extension Pack (by Microsoft)**: This is essential. It includes IntelliSense (code completion), debugging features, and code browsing tools for C and C++.
* **(Optional) GitLens**: Provides deeper insights into Git history directly within the editor lines, which is very helpful for tracking changes.
* **GitHub Pull Requests and Issues**: Allows you to review and manage GitHub pull requests and issues directly in VS Code[cite: 2].

## 3. Integrating Git and GitHub

VS Code has excellent built-in support for Git. Here is the workflow used for this assignment:

### 3.1. Signing in to GitHub

1.  Open the Command Palette (`Ctrl+Shift+P`).
2.  Type `GitHub: Sign in` and select the option.
3.  Follow the prompts to authenticate with your GitHub account.

### 3.2. Cloning the Repository

Instead of using the command line externally, I used VS Code's command palette:
1.  Opened the Command Palette (`Ctrl+Shift+P`).
2.  Typed `Git: Clone` and selected the option.
3.  Pasted the course repository URL when prompted.
4.  Selected the local destination folder where the repository will be cloned.
5.  Once cloned, VS Code prompted to open the repository, and I clicked `Open`.

### 3.3. Managing Changes (Source Control View)

I utilized the **Source Control** view (Ctrl+Shift+G) in the sidebar for version control operations:

1.  **Staging**: Modified files appear under "Changes". Clicking the `+` button next to a file stages it for commit (equivalent to `git add`).
2.  **Committing**: Entered a descriptive commit message in the message box above the staged changes and clicked the "Commit" button (check icon).
3.  **Pushing**: Synced changes to GitHub by clicking the "Sync Changes" button (or "Push" option in the menu) in the bottom-left status bar or in the Source Control view.

## 4. Building and Running the Assignment (Windows)

Since this assignment is developed in a Windows environment and provides a `Makefile.bat`, the build process is streamlined using VS Code's integrated terminal.

1.  **Open Integrated Terminal**: Used the shortcut `` Ctrl+` `` (backtick) to open the terminal within VS Code.
2.  **Compile**: Ran the `Makefile.bat` command to build both C and C++ executables.
    ```cmd
    .\Makefile.bat all
    ```
3.  **Run**: Executed the compiled binaries directly from the terminal.
    ```cmd
    .\C\hash_function.exe    # For the C version
    .\CXX\hash_function_cpp.exe  # For the C++ version
    ```


