As beautiful as a shell

This project consists in writing a mini-shell able to read to evaluate basic command lines from a user. The reading part implies trivial lexical and syntactic analyses of the command line, and the evaluation part implies to locate the requested binary on the computer and run it, or running the corresponding code in case of a built in functionality of the shell.

Through the Minishell project, I got to the core of the Unix system and explored an important part of this system’s API: process creation and synchronisation. Executing a command inside a shell implies creating a new process, which execution and final state will be monitored by its parent’s process.