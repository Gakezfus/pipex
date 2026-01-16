*This project has been created as part of the 42 curriculum by echoo.*

## Description

This project creates a program that simulates shell commands in this format: < file1 cmd1 | cmd2 > file2

## Instructions

### Compilation

For mandatory function:
```bash
make
```
or

```bash
make all
```

### Execution

```bash
./pipex file1 cmd1 cmd2 file2
```

## Resources

### Documentation & References

Details of pipes work can be found in "man pipe"

Details of how C programs can fork and execute child commands can be found in "man fork" and "man execve" respectively.

### AI Usage

AI helped me to understand how forking, execve and loops worked, and it was an invaluable resource. It was also very useful for debugging when I had trouble understanding the behaviour of the functions, and also helped me just by giving me someone to talk to and reason with.
