# Brainfuck Interpreter (C)

This project is a simple interpreter for the esoteric programming language **Brainfuck**, written in C. It reads a `.bf` file and executes its instructions using a simulated memory tape.

---

## What is Brainfuck

Brainfuck is an extremely minimal programming language created for educational and recreational purposes. Despite its simplicity, it is Turing complete.

It uses only **8 commands**:

| Command | Meaning |
|--------|--------|
| `+` | Increments the value at the current cell |
| `-` | Decrements the value at the current cell |
| `>` | Moves the pointer to the right |
| `<` | Moves the pointer to the left |
| `.` | Outputs the character at the current cell |
| `,` | Reads a character from input and stores it in the current cell |
| `[` | Starts a loop (runs while current cell is not zero) |
| `]` | Ends a loop |

The language operates on a simple memory tape, where each cell initially contains zero.

---

## How this interpreter works

This implementation simulates:

- A memory tape of 1024 bytes (`unsigned char tape[1024]`)
- A pointer (`ptr`) that moves across the tape
- A loop that reads the source code character by character
- Execution using a `switch(cmd)` dispatcher

### Key features

- Input handling using `getchar()`
- Output using `putchar()`
- Loop support with `[` and `]`
- Basic boundary protection for the pointer (0 to 1023)

---

## How to compile

Use `gcc` to compile the program:

```bash
gcc bfI.c -o bfI
