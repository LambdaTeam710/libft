# Libft — My First C Library

```text
┌────────────────────────────────────────────┐
│ λ By: Oussama_ES-SλIDY - LambdaTeam710     │
│ self-taught C / systems engineer           │
└────────────────────────────────────────────┘
```

> This is my personal completed project. Please do not copy it for evaluation.

---

## What is Libft?

Libft is a project that aims to reimplement common C library functions from scratch.

The goal is to understand how standard C functions behave internally, rebuild them safely, and then add custom utility functions on top of that foundation.

This library covers:

```text
strings
memory
character checks
conversion
file descriptor output
linked lists
function pointers
```

For me, this was not just a school project. It was the project where C finally became concrete: memory, pointers, allocation, cleanup, edge cases, and debugging.

---

## Background

I am self-taught and a 1337 (42 Morocco) piscine survivor for the 2025/2026 pool.

After the 2026 pool did not go my way, I did not stop. I kept learning alone, reading, testing, failing, and rebuilding until things started to make sense.

Libft is the first complete project I built by myself.

It was difficult, but it taught me how to learn C properly.

---

## Project Constraints

This project was built with strict constraints:

- Written in C
- No external libraries
- Only low-level calls such as `malloc`, `free`, and `write` are used where necessary
- Compiled with strict flags:

```bash
cc -Wall -Wextra -Werror
```

- Functions are kept small and focused
- Helper functions are used when logic needs to be split
- Function length is kept under 25 lines where required

---

## Function List

### Character Checks and Conversion

| Function | Description |
|---|---|
| `ft_isalpha` | checks if a character is alphabetic |
| `ft_isdigit` | checks if a character is a digit |
| `ft_isalnum` | checks if a character is alphanumeric |
| `ft_isascii` | checks if a value fits the ASCII range |
| `ft_isprint` | checks if a character is printable |
| `ft_toupper` | converts lowercase to uppercase |
| `ft_tolower` | converts uppercase to lowercase |

---

### Memory Functions

| Function | Description |
|---|---|
| `ft_memset` | fills memory with a specific byte |
| `ft_bzero` | fills memory with zeros |
| `ft_memcpy` | copies memory from source to destination |
| `ft_memmove` | copies memory safely when areas overlap |
| `ft_memchr` | finds the first occurrence of a byte in memory |
| `ft_memcmp` | compares two memory areas |
| `ft_calloc` | allocates memory and fills it with zeros |

---

### String Basics

| Function | Description |
|---|---|
| `ft_strlen` | calculates string length |
| `ft_strlcpy` | copies a string with a destination size limit |
| `ft_strlcat` | concatenates strings with a destination size limit |
| `ft_strchr` | finds the first occurrence of a character |
| `ft_strrchr` | finds the last occurrence of a character |
| `ft_strncmp` | compares two strings up to `n` bytes |
| `ft_strnstr` | finds a substring inside the first `n` bytes |
| `ft_strdup` | duplicates a string into newly allocated memory |

---

### Conversion Functions

| Function | Description |
|---|---|
| `ft_atoi` | converts a string to an integer |
| `ft_itoa` | converts an integer to a string |

---

### Custom String Utilities

| Function | Description |
|---|---|
| `ft_substr` | extracts a substring from a string |
| `ft_strjoin` | joins two strings into a new string |
| `ft_strtrim` | trims specified characters from both ends of a string |
| `ft_split` | splits a string by a delimiter into a NULL-terminated array |
| `ft_strmapi` | applies a function to each character using its index and returns a new string |
| `ft_striteri` | applies a function to each character using its index in place |

---

### Output Functions

| Function | Description |
|---|---|
| `ft_putchar_fd` | writes one character to a file descriptor |
| `ft_putstr_fd` | writes a string to a file descriptor |
| `ft_putendl_fd` | writes a string followed by a newline |
| `ft_putnbr_fd` | writes an integer to a file descriptor |

---

### Linked List Functions

| Function | Description |
|---|---|
| `ft_lstnew` | creates a new list node |
| `ft_lstadd_front` | adds a node to the beginning of the list |
| `ft_lstsize` | counts the number of nodes in the list |
| `ft_lstlast` | returns the last node of the list |
| `ft_lstadd_back` | adds a node to the end of the list |
| `ft_lstdelone` | deletes one node and its content |
| `ft_lstclear` | deletes a node and every node after it |
| `ft_lstiter` | applies a function to the content of every node |
| `ft_lstmap` | creates a new list by applying a function to every content |

The linked list part uses this structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

---

## Hardest Parts

The hardest functions for me were:

```text
ft_split
ft_itoa
```

`ft_split` was the real deal.

It required careful handling of:

```text
delimiters
empty strings
consecutive delimiters
allocation failure
cleanup
NULL-terminated arrays
helper function design
```

It also forced me to respect the function length constraint while keeping the logic clean.

`ft_itoa` was also harder than it looks, especially because of:

```text
negative numbers
INT_MIN
digit counting
allocation size
right-to-left filling
```

These two functions taught me that in C, the main logic is often not the hardest part.

The hardest part is handling every edge case without leaking memory or crashing.

---

## How to Build

Clone the repository:

```bash
git clone https://github.com/lambdateam710/libft.git
cd libft
```

Compile the library:

```bash
make
```

This creates:

```text
libft.a
```

Useful Makefile rules:

```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and libft.a
make re     # clean everything and recompile
```

---

## How to Use It

Include the header:

```c
#include "libft.h"
```

Compile your program with `libft.a`:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program
```

Example using `ft_split`:

```c
#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello,world,libft", ',');
	if (!words)
		return (1);

	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		i++;
	}

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);

	return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program
./my_program
```

Expected output:

```text
hello
world
libft
```

---

## Testing

All functions were tested using:

```text
Tripouille/libftTester
```

Tester repository:

```text
https://github.com/Tripouille/libftTester
```

General testing flow:

```bash
git clone https://github.com/Tripouille/libftTester.git
cd libftTester
make m
make b
```

The tester checks:

```text
basic behavior
edge cases
memory leaks
invalid input
segmentation faults
timeout cases
```

---

## AI Usage

I used AI during this project, but not as a copy-paste tool.

I read the man pages and the subject first, then used AI as a learning assistant.

Specifically:

- **Qwen**  
  Used for deep explanations, understanding function behavior, return types, memory ownership, and organizing my implementation plan.

- **Gemini**  
  Used for quick testing ideas and sanity checks on individual functions.

AI helped me understand faster and debug more consciously.

It did not replace:

```text
reading documentation
writing code
debugging
testing
understanding memory
```

I used AI as a tool, not as a shortcut around learning.

---

## What This Project Taught Me

Libft taught me how to think in C.

Before this project, C was mostly syntax and confusion.

After this project, I understand much better:

```text
pointers
memory allocation
malloc and free discipline
string manipulation
linked lists
function pointers
edge-case handling
debugging
```

Most importantly, it taught me to break big problems into small pieces.

One helper.

One job.

One edge case at a time.

---

## Why This Repository Is Public

I am sharing this project because it represents a real step in my learning journey.

If this repository helps someone understand:

```text
C strings
memory functions
ft_split
ft_itoa
linked lists
```

then I am happy to share it.

Feel free to read it, learn from it, and use it as a reference for your own future projects.

Just do not submit it as your own evaluation work.

---

## Final Note

This project was built with effort, frustration, debugging, and persistence.

It is not perfect, but it is mine, and I understand it.

That is what matters most :)

---

GitHub: `LambdaTeam710`
