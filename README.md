# kshell

A small Unix shell written in C, built to learn how terminals, processes,
and system calls work, with a focus on security (input limits, audit logging).

## Status
🚧 phase two under construction (parse, history, builtins)


## Planned Features
- [x] Prompt loop and `exit`
- [x] Split commands into words using strtok
- [ ] Built-ins: `cd`, `pwd`, `echo`, `help`, `history`
- [ ] Run programs with fork/exec
- [ ] Security: input length limits, command audit log, zero memory errors

## Build
```
gcc -Wall -o kshell *.c && ./kshell
```

## Tests
```
gcc -Wall -I. -o test_p tests/test_parse.c parse.c && ./test_p
```

## Authors
Kurt ([rg-gurt](https://github.com/rg-gurt)) · Jamie ([Inerrrtia](https://github.com/Inerrrtia))

**note:** AI was used as a tutor for specs and code review; the implementation is fully our own.