# kshell

A small Unix shell written in C, built to learn how terminals, processes,
and system calls work, with a focus on security (input limits, audit logging).

## Status
🚧 In progress

## Planned Features
- [ ] Prompt loop and `exit`
- [ ] Built-ins: `cd`, `pwd`, `echo`, `help`, `history`
- [ ] Run programs with fork/exec
- [ ] Security: input length limits, command audit log, zero memory errors

## Build
gcc -Wall -o kshell *.c && ./kshell
