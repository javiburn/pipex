# pipex
Simulating the pipe operator "|" in C language.

A project designed to learn about creating new processes and how to communicate between them. With this project I learned how the fork(), pipe() and dup2() functions work.

<img width="789" alt="Screen Shot 2023-05-17 at 12 06 57 PM" src="https://github.com/javiburn/pipex/assets/72255876/22c78cd0-6c10-46d0-9d7a-d4e04eca42bb">


The program admits 4 arguments (plus the program's name ./pipex), being the first one the name of the file to be read, then the two commands that will be executed simulating the pipe operation, and finally the name of the output file.

With this, the command "./pipex infile command1 command2 outfile" works the same way as "<infile command1 | command2>outfile", as it is shown in the image above.
